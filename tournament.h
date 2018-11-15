#ifndef ROURNAMENT_H
#define ROURNAMENT_H

typedef struct Player{
  int offensive;
  int defensive;
  int number;
  int team;
  char * first;
  char * last;
} Player;

typedef struct Team{
  char *name;
  Player *players;
  void (*delete) (struct Team * team);
} Team;


#endif