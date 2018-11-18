#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "tournament.h"

Player * draftPlayers(char * filename, int team, int num_players){
  FILE * fp = fopen(filename, "r");
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  
  while ((read = getline(&line, &len, fp)) != -1) {
    char* token; 
    char* rest = line; 
    
    while ((token = strtok_r(rest, ",", &rest))) 
      printf("%s\n", token); 
    //printf("%s", line);
  }
  
  fclose(fp);
  if (line)
    free(line);
  exit(EXIT_SUCCESS);
  
  Player * players = malloc(num_players*sizeof(Player));
  Player * t = players;
  t++;
  
  free(players);
  return players;
};

Team * newTeam(char * name, Player * players){
  
};

Team * game(Team *, Team *);

Team * tournament(Team **, int);


void deleteTeam(Team *);

