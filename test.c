#include<stdio.h>
#include <stdlib.h>
#include<string.h>

int main(){
  FILE * fp = fopen("players.dat", "r");
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  
  while ((read = getline(&line, &len, fp)) != -1) {
    char* token; 
    char* rest = line; 
    
    while ((token = strtok_r(rest, ",", &rest))) 
      printf("%s\n", token); 
    //printf("%s", line);
  }
  
  fclose(fp);
  if (line)
    free(line);
  exit(EXIT_SUCCESS);
}