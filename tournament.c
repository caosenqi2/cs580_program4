#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "tournament.h"

Player * draftPlayers(char * filename, int team, int num_players){
  FILE * fp = fopen(filename, "r");
  
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  Player players[num_players];
  
  while ((read = getline(&line, &len, fp)) != -1) {
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
    }
  }
  
  fclose(fp);
  if (line)
    free(line);
  return players;
}

void deleteTeam(Team * t){
  free(t->name);
  free(t->players);
  free(t);
};

Team * newTeam(char * name, Player * players){
  Team * t = malloc(sizeof(Team));
  strcpy(t->name,name);
  t->players = players;
  t->delete = deleteTeam;
  return t;
}

Team * game(Team *, Team *);

Team * tournament(Team **, int);




