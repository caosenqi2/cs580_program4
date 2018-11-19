#ifndef ROURNAMENT_H
#define ROURNAMENT_H

typedef struct Player{
  int team;
  char first[100];
  char last[100];
  int number;
  int offensive;
  int defensive;
} Player;

typedef struct Team{
  char name[100];
  Player * players;
  void (*delete) (struct Team * team);
} Team;


#endif