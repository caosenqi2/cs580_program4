#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "tournament.h"

Player * draftPlayers(char * filename, int team, int num_players){
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

