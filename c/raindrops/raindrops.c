#include "raindrops.h"

void convert(char result[], int drops) {
  if ( drops % 3  && drops % 5  && drops % 7) {
    sprintf(result,"%d",drops);
    return;
  }


  if ((drops % 3)==0) {
    strcat(result,"Pling");
  }

  if ((drops % 5)==0) {
    strcat(result,"Plang");
  }

  if ((drops % 7)==0) {
    strcat(result,"Plong");
  }

}
