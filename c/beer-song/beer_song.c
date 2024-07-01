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
    if(i>1)
      sprintf(song[j],bottles_of,i,i);
    if(i == 1)
      sprintf(song[j],bottle_of,i,i);
    if(i == 0)
      sprintf(song[j],"%s",bottle_of_no_more);
    if(i-1>1)
      sprintf(song[j+1],take_down_bottles,i-1);
    if(i-1 == 1)
      sprintf(song[j+1],take_down_bottle,i-1);
    if(i-1 == 0)
      sprintf(song[j+1],"%s",take_down_no_more);
    if(i-1 < 0)
      sprintf(song[j+1],"%s",take_down_store);
  }
}
