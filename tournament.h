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

Player * draftPlayers(char * filename, int team, int num_players);
void deleteTeam(Team * team);
Team * newTeam(char * name, Player * players);
Team * game(Team * team1, Team * team2);
Team * tournament(Team ** league, int n);

#endif