#include"tournament.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

#define DEBUG 1
#define NUM_TEAMS 32
#define NUM_PLAYERS 10

Player players[NUM_PLAYERS];
int inLeague(Team *, Team **);
Player * draftPlayers(char * filename, int team, int num_players){
  FILE * fp = fopen(filename, "r");
  
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  //Player players[num_players];
  //Player * players = malloc(num_players*sizeof(Player));
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
  //free(players);
  return players;
}

void deleteTeam(Team * team){
  free(team->name);
  free(team->players);
  free(team);
};

Team * newTeam(char * name, Player * players){
  Team * team = malloc(sizeof(Team));
  strcpy(team->name,name);
  team->players = players;
  team->delete = deleteTeam;
  return team;
}

Team * game(Team * team1, Team * team2){
  if (team1 == NULL || team2 == NULL) return NULL;
  int i = 0;
  int deffensive_1 = 0;
  int deffensive_2 = 0;
  int offensive_1 = 0;
  int offensive_2 = 0;
  int score_1 = 0;
  int score_2 = 0;
  
  for (i=0;i<10;i++){
    printf("offensives:%d\n",players[i].offensive);
    deffensive_1 += team1->players[i].defensive;
    deffensive_2 += team2->players[i].defensive;
    offensive_1 += team1->players[i].offensive;
    offensive_2 += team2->players[i].offensive;
  }
  while(score_1 == score_2){
    if (rand() % (offensive_1 + 1) > deffensive_2) score_1+=1;
    if (rand() % (offensive_1 + 1) > deffensive_2) score_1+=1;
    if (rand() % (offensive_2 + 1) > deffensive_1) score_2+=1;
    if (rand() % (offensive_2 + 1) > deffensive_1) score_2+=1;
    if (score_1 > score_2) return team1;
    if (score_2 > score_1) return team1;
  }
};

Team * tournament(Team ** league, int n){
  while(n != 1){
    if (n%2 == 0){
      n = n/2;
    }
    else{
      printf("The number of teams is invalid.");
      return NULL;
    }
  }
  
  Team * team1 = league[0];
  Team * team2;
  printf("begin");
  
  for (int i=1;i<n;i++){
    printf("i%d\n",i);
    printf("hello");
    team2 = league[i];
    team1 = game(team1,team2);
    printf("winner%s, ",team1->name);
  }
  
  printf("lastwinner:%s, ",team1->name);
  return team1;
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
  //free(players);
  
  
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
  printf("\t-----------------------------------\n");
  printf("\t-   Part2 : Exhibition Games      -\n");
  printf("\t-----------------------------------\n");
  
  printf("\n\t=========Test #2: Sanity check for the game===========\n\n");
  
  Team * winner = game(NULL, NULL);
  assert(winner == NULL);
  printf("\n\t\t....Test Passed\n");
  printf("\n\t=========Test #3: Playing a Game between two random teams===========\n\n");
  Team * team1 = league[rand() % NUM_TEAMS];
  Team * team2 = league[rand() % NUM_TEAMS];
  printf("Up next, an exhibition game between %s and %s\n", team1->name, team2->name);
  winner = game(team1, team2);
  assert(winner == team1 || winner == team2);
  printf("The winning team is %s\n\n", winner->name);
  printf("\n\t\t....Test Passed\n");
  printf("\n\t=========Test #4: Playing a Game between the same team===========\n\n");
  int team_num = rand() % NUM_TEAMS;
  printf("Up next, a a scrimmage for %s\n", league[team_num]->name);
  winner = game(league[team_num], league[team_num]);
  assert(winner == league[team_num]);
  printf("The winning team is %s\n\n", winner->name);
  printf("\n\t\t....Test Passed\n");
  printf("\t-----------------------------------\n");
  printf("\t-   Part3 : Running a Tournament  -\n");
  printf("\t-----------------------------------\n");
  printf("\n\t=========Test #5: Ensure number of teams is a power of 2===========\n\n");
  winner = tournament(league, 20);
  assert(winner == NULL);
  printf("\n\t\t....Test Passed\n");
  printf("\n\t=========Test #6: Should result in a single winner===========\n\n");
  winner = tournament(league, NUM_TEAMS/4);
  assert(inLeague(winner, league));
  winner = tournament(league, NUM_TEAMS/2);
  assert(inLeague(winner, league));
  winner = tournament(league, NUM_TEAMS);
  assert(inLeague(winner, league));
  printf("\n************************ Result *******************************\n\n");
  printf("The winning team is %s\n\n", winner->name);
  printf("\n\t\t....Test Passed\n");
  
  printf("\n\t=========Test #7: Should result in a random winner===========\n\n");
  const int NUM_SEASONS = 25;
  Team * winners[NUM_SEASONS];
  for(int counter = 0; counter < NUM_SEASONS; counter++){
    winners[counter] = tournament(league, NUM_TEAMS);
    printf("Winner is %s\n", winners[counter]->name);
    assert(inLeague(winners[counter], league));
  }
  printf("good");
  Team * randomness_test = winners[0];
  int is_random = 0;
  for(int counter = 1; counter < NUM_SEASONS; counter++){
    if(randomness_test != winners[counter]){
      is_random = 1;
    }
  }
  assert(is_random);
  printf("\n\t\t....Test Passed\n");
}


int inLeague(Team * t, Team ** league){
  int i = 0;
  for(; i < NUM_TEAMS; i++){
    if(league[i] == t){
      return 1;
    }
  }
  return 0;
}
