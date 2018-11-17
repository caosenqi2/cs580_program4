#include<stdio.h>
#include <string.h> 
#include"tournament.h"
#include"tournament.h"

Player * draftPlayers(char * filename, int team, int num_players){
  Player * players = malloc(num_players*sizeof(Player));
  Player * t = players;
  
  t++;
  
  char str[] = "Geeks for Geeks";
  char * token; 
  char * rest = str; 
  
  while ((token = strtok_r(rest, " ", &rest))) 
    printf("%s\n", token);
  
  return players;
};

Team * newTeam(char * name, Player * players);

Team * game(Team *, Team *);

Team * tournament(Team **, int);


void deleteTeam(Team *);

