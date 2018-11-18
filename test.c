#include"tournament.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

#define DEBUG 1
#define NUM_TEAMS 32
#define NUM_PLAYERS 10

Player * draftPlayers(char * filename, int team, int num_players){
  FILE * fp = fopen(filename, "r");
  
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  Player players[num_players];
  
  while ((read = getline(&line, &len, fp)) != -1) {
    //printf("%s\n",line);
    char *token = strtok(line, ",");
    
    if (atoi(token) == team){
      players[0].team = atoi(token);
      token = strtok(NULL, ",");
      
      players[1].first = token;
      token = strtok(NULL, ",");
      
      players[2].last = token;
      token = strtok(NULL, ",");
      
      players[3].number = atoi(token);
      token = strtok(NULL, ",");
      
      players[4].offensive = atoi(token);
      token = strtok(NULL, ",");
      
      players[5].defensive = atoi(token);
      token = strtok(NULL, ",");
      
      printf("team:%d\n", players[0].team);
      printf("first:%s\n", players[1].first);
      printf("last:%s\n", players[2].last);
      printf("num:%d\n", players[3].number);
      printf("off:%d\n", players[4].offensive);
      printf("deff:%d\n", players[5].defensive);
    }
  }
  
  fclose(fp);
  if (line)
    free(line);
  return players;
}

int main(){
  FILE * fp = fopen("players.dat", "r");
  
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  Player players[320];
  
  while ((read = getline(&line, &len, fp)) != -1) {
    //printf("%s\n",line);
    char *token = strtok(line, ",");
    
    if (atoi(token) == 1){
      players[0].team = atoi(token);
      token = strtok(NULL, ",");
      
      players[1].first = token;
      token = strtok(NULL, ",");
      
      players[2].last = token;
      token = strtok(NULL, ",");
      
      players[3].number = atoi(token);
      token = strtok(NULL, ",");
      
      players[4].offensive = atoi(token);
      token = strtok(NULL, ",");
      
      players[5].defensive = atoi(token);
      token = strtok(NULL, ",");
      
      printf("team:%d\n", players[0].team);
      printf("first:%s\n", players[1].first);
      printf("last:%s\n", players[2].last);
      printf("num:%d\n", players[3].number);
      printf("off:%d\n", players[4].offensive);
      printf("deff:%d\n", players[5].defensive);
    }
    
    
  }

  fclose(fp);
  if (line)
    free(line);
  draftPlayers("players.dat",2,10);
}
