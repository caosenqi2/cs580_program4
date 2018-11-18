#ifndef ROURNAMENT_H
#define ROURNAMENT_H

typedef struct Player{
  int team;
  char * first;
  char * last;
  int number;
  int offensive;
  int defensive;
} Player;

typedef struct Team{
  char * name;
  Player * players;
  void (*delete) (struct Team * team);
} Team;


#endif