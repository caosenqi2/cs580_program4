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
  
  while ((read = getline(&line, &len, fp)) != -1) {
    char* token;
    char* rest = line;
    
    while ((token = strtok_r(rest, ",", &rest))) {
      //printf("%s\n", token); 
      
    }
      
    
    //printf("%s", line);
  }

  fclose(fp);
  if (line)
    free(line);
  //exit(EXIT_SUCCESS);
  
  
  Player * players = malloc(10*sizeof(Player));
  Player * t = players;
  printf("hello%d\n",sizeof(Player));
  printf("hello%d\n",t);
  t++;
  printf("hello1%d\n",t);
  
  free(t);
  free(players);
}