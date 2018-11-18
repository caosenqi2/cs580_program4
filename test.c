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

  free(players);
  
  char * team_names[] = {
    "team1",
    "team2",
    "team3",
    "team4",
    "team5",
    "team6",
    "team7",
    "team8",
    "team9",
    "team10",
    "team11",
    "team12",
    "team13",
    "team14",
    "team15",
    "team16",
    "team17",
    "team18",
    "team19",
    "team20",
    "team21",
    "team22",
    "team23",
    "team24",
    "team25",
    "team26",
    "team27",
    "team28",
    "team29",
    "team30",
    "team31",
    "team32",
  };
  
  /********************************************************************/
  /*    DO NOT ALTER ANY OF THE THE DRIVER CODE BELOW                 */
  /********************************************************************/
#if !DEBUG
  fclose(stderr);
#endif
  printf("\t-----------------------------------\n");
  printf("\t-   Part1 : Creating Your League  -\n");
  printf("\t-----------------------------------\n");
  srand(time(NULL));
  
  printf("\n\t=========Test #1: Creating your Teams and Players===========\n\n");
  Team ** league = malloc(sizeof(Team*) * NUM_TEAMS);
  //create teams i.e. league of N teams.
  for(int counter = 0; counter < NUM_TEAMS; counter++){
    Player * draft = draftPlayers("players.dat", counter, NUM_PLAYERS);
    for(int i = 0; i < NUM_PLAYERS; i++)
      assert(draft[0].team == counter%NUM_TEAMS);
}
}