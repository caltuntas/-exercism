#include "beer_song.h"

void recite(uint8_t start_bottles, uint8_t take_down, char **song)
{
  for (int i=start_bottles, j=0; i>start_bottles-take_down; i--,j+=3)
  {
    char* bottles_of = "%d bottles of beer on the wall, %d bottles of beer.";
    char* bottle_of = "%d bottle of beer on the wall, %d bottle of beer.";
    char* bottle_of_no_more = "No more bottles of beer on the wall, no more bottles of beer.";
    char* take_down_bottles = "Take one down and pass it around, %d bottles of beer on the wall.";
    char* take_down_bottle = "Take one down and pass it around, %d bottle of beer on the wall.";
    char* take_down_no_more = "Take it down and pass it around, no more bottles of beer on the wall.";
    char* take_down_store = "Go to the store and buy some more, 99 bottles of beer on the wall.";
    char *line1 = calloc(100,sizeof *line1);
    char *line2 = calloc(100,sizeof *line1);
    char *empty = calloc(1,sizeof(char));
    if(i>1)
      sprintf(line1,bottles_of,i,i);
    if(i == 1)
      sprintf(line1,bottle_of,i,i);
    if(i == 0)
      sprintf(line1,"%s",bottle_of_no_more);
    if(i-1>1)
      sprintf(line2,take_down_bottles,i-1);
    if(i-1 == 1)
      sprintf(line2,take_down_bottle,i-1);
    if(i-1 == 0)
      sprintf(line2,"%s",take_down_no_more);
    if(i-1 < 0)
      sprintf(line2,"%s",take_down_store);


    song[j] = line1;
    song[j+1] = line2;
    song[j+2] = empty;
  }
}
