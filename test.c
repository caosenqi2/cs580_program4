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
  FILE * fp = fopen(filename, "r");
  
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  //Player players[num_players];
  Player * players = malloc(num_players*sizeof(Player));
  int i = 0;
  while ((read = getline(&line, &len, fp)) != -1) {
    //printf("%s\n",line);
    char *token = strtok(line, ",");
    
    if (atoi(token) == team){
      players[i].team = atoi(token);
      token = strtok(NULL, ",");
      
     // players[i].first = token;
      strcpy(players[i].first,token);
      token = strtok(NULL, ",");
      
     // players[i].last = token;
      strcpy(players[i].last,token);
      token = strtok(NULL, ",");
      
      players[i].number = atoi(token);
      token = strtok(NULL, ",");
      
      players[i].offensive = atoi(token);
      token = strtok(NULL, ",");
      
      players[i].defensive = atoi(token);
      token = strtok(NULL, ",");
      i++;
      //printf("team:%d\n", players[0].team);
      //printf("first:%s\n", players[1].first);
      //printf("last:%s\n", players[2].last);
      //printf("num:%d\n", players[3].number);
      //printf("off:%d\n", players[4].offensive);
      //printf("deff:%d\n", players[5].defensive);
    }
  }
  
  fclose(fp);
  if (line)
    free(line);
  free(players);
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



int main(){
  FILE * fp = fopen("players.dat", "r");
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  Player players[320];
  //Player * players = malloc(10*sizeof(Player));
  int i = 0;
  while ((read = getline(&line, &len, fp)) != -1) {
    //printf("%s\n",line);
    char *token = strtok(line, ",");
    
    if (atoi(token) == 0){
      
      players[i].team = atoi(token);
      token = strtok(NULL, ",");
      
      //players[i].first = token;
      strcpy(players[i].first,token);
      token = strtok(NULL, ",");
      
      //players[i].last = token;
      strcpy(players[i].last,token);
      token = strtok(NULL, ",");
      
      players[i].number = atoi(token);
      token = strtok(NULL, ",");
      
      players[i].offensive = atoi(token);
      token = strtok(NULL, ",");
      
      players[i].defensive = atoi(token);
      token = strtok(NULL, ",");
      //printf("i:%d\n",i);
      //printf("team:%d\n", players[i].team);
      //printf("first:%s\n", players[i].first);
      //printf("last:%s\n", players[i].last);
      //printf("num:%d\n", players[i].number);
      //printf("off:%d\n", players[i].offensive);
      //printf("deff:%d\n", players[i].defensive);
      i++;
    }
  }
  fclose(fp);
  if (line)
    free(line);
  free(players);
  
  
  /*****  Change the team names to names of your choosing ******/
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
  for(int counter = 0; counter < NUM_TEAMS; counter++){
    Player * draft = draftPlayers("players.dat", counter, NUM_PLAYERS);
    for(int i = 0; i < NUM_PLAYERS; i++)
      assert(draft[0].team == counter%NUM_TEAMS);
    league[counter] = newTeam(team_names[counter], draft);
    assert(sizeof((league[counter]->players[rand() % NUM_PLAYERS])) == sizeof(Player));
    assert((league[counter]->players[rand() % NUM_PLAYERS]).offensive > 0);
    assert((league[counter]->players[rand() % NUM_PLAYERS]).defensive > 0);
    assert(sizeof(*(league[counter])) == sizeof(Team));
  }
  
}
