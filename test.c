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
  Player * players = malloc(num_players*sizeof(Player));
  Player * t = players;
  t++;
  
  free(players);
  return players;
};

int main(){
  FILE * fp = fopen("players.dat", "r");
  
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  
  Player ** players = malloc(10*sizeof(Player));
  Player * t = players;
  
  while ((read = getline(&line, &len, fp)) != -1) {
    printf("%s\n",line);
    char *token = strtok(line, ",");
    
    t->team = atoi(token);
    token = strtok(NULL, ",");
    
    t->first = token;
    token = strtok(NULL, ",");
    
    t->last = token;
    token = strtok(NULL, ",");
    
    t->number = atoi(token);
    token = strtok(NULL, ",");
    
    t->offensive = atoi(token);
    token = strtok(NULL, ",");
    
    t->defensive = atoi(token);
    token = strtok(NULL, ",");
    
    printf("team:%d\n", t->team);
    printf("first:%s\n", t->first);
    printf("last:%s\n", t->last);
    printf("num:%d\n", t->number);
    printf("off:%d\n", t->offensive);
    printf("deff:%d\n", t->defensive);
    
    t++;
  }

  fclose(fp);
  if (line)
    free(line);
  free(players);
}