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
  free(team->name);
  free(team->players);
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
  
};

Team * tournament(Team **, int);




