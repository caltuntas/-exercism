#include "dnd_character.h"

int ability(void) {
  int min = 8, sum = 0;
  for ( int i=0; i<4; i++) {
    int n = rand() % 7;
    if (n < min)
      min = n;
    sum+=n;
  }
  return sum - min;
}

int modifier(int score) {
  return floor((score-10) / 2.0);
}

dnd_character_t make_dnd_character(void) {
  dnd_character_t dnd = {
    .strength=ability(),
    .dexterity=ability(),
    .constitution=ability(),
    .intelligence=ability(),
    .wisdom=ability(),
    .charisma=ability()
  };
  dnd.hitpoints = modifier(dnd.constitution) + 10;
  return dnd;
}
