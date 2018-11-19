#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "tournament.h"

#define NUM_PLAYERS 10
Player players[NUM_PLAYERS];

Player * draftPlayers(char * filename, int team, int num_players){
  FILE * fp = fopen(filename, "r");
  
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  //Player players[num_players];
  //Player * players = malloc(num_players*sizeof(Player));
  int i = 0;
  while ((read = getline(&line, &len, fp)) != -1) {
    //printf("%s\n",line);
    char *token = strtok(line, ",");
    
    if (atoi(token) == team){
      players[i].team = atoi(token);
      token = strtok(NULL, ",");
      
      strcpy(players[i].first,token);
      token = strtok(NULL, ",");
      
      strcpy(players[i].last,token);
      token = strtok(NULL, ",");
      
      players[i].number = atoi(token);
      token = strtok(NULL, ",");
      
      players[i].offensive = atoi(token);
      token = strtok(NULL, ",");
      
      players[i].defensive = atoi(token);
      token = strtok(NULL, ",");
      i++;
      //printf("team:%d\n", players[0].team);
      //printf("first:%s\n", players[1].first);
      //printf("last:%s\n", players[2].last);
      //printf("num:%d\n", players[3].number);
      //printf("off:%d\n", players[4].offensive);
      //printf("deff:%d\n", players[5].defensive);
    }
  }
  
  fclose(fp);
  if (line)
    free(line);
  //free(players);
  return players;
}

void deleteTeam(Team * team){
  //free(team->name);
  //free(team->players);
  free(team);
};

Team * newTeam(char * name, Player * players){
  Team * team = malloc(sizeof(Team));
  strcpy(team->name,name);
  team->players = players;
  team->delete = deleteTeam;
  return team;
}

Team * game(Team * team1, Team * team2){
  if (team1 == NULL || team2 == NULL) return NULL;
  int i = 0;
  int deffensive_1 = 0;
  int deffensive_2 = 0;
  int offensive_1 = 0;
  int offensive_2 = 0;
  int score_1 = 0;
  int score_2 = 0;
  
  for (i=0;i<10;i++){
    //printf("offensives:%d\n",players[i].offensive);
    deffensive_1 += team1->players[i].defensive;
    deffensive_2 += team2->players[i].defensive;
    offensive_1 += team1->players[i].offensive;
    offensive_2 += team2->players[i].offensive;
  }
  while(score_1 == score_2){
    if (rand() % (offensive_1 + 1) > deffensive_2) score_1+=1;
    if (rand() % (offensive_1 + 1) > deffensive_2) score_1+=1;
    if (rand() % (offensive_2 + 1) > deffensive_1) score_2+=1;
    if (rand() % (offensive_2 + 1) > deffensive_1) score_2+=1;
    
    if (score_1 > score_2) return team1;
    
    if (score_2 > score_1) return team2;
  }
};

Team * tournament(Team ** league, int n){
  int N = n;
  while(n != 1){
    if (n%2 == 0){
      n = n/2;
    }
    else{
      printf("The number of teams is invalid.");
      return NULL;
    }
  }
  
  Team * team1 = league[0];
  Team * team2;
  int i = 0;
  for (i=1;i<N;i++){
    team2 = league[i];
    team1 = game(team1,team2);
  }
  return team1;
}




