#include "yacht.h"
#define DICE_COUNT 5
#define FOR_EACH_VALUES(action) \
  for (int i=0; i<6; i++) { \
    action \
  }

typedef struct {
  int *counts;
  int sum;
  category_t category;
} params;

typedef int func(params p);

static int check_count(int counts[], int times) {
  FOR_EACH_VALUES ( if (counts[i] == times) return 1; );
  return 0;
}

static int check_straight(int counts[], int val) {
  if (counts[val]) return 0;
  FOR_EACH_VALUES ( if (counts[i] > 1 ) return 0;);
  return 30;
}

static int number_of(params p) {
  return p.counts[p.category]*(p.category+1);
}

static int choice(params p) {
  return p.sum;
}

static int four_of(params p) {
  FOR_EACH_VALUES ( if (p.counts[i] >= 4) return (i+1)*4;);
  return 0;
}

static int little_straight(params p) {
  return check_straight(p.counts,5);
}

static int big_straight(params p) {
  return check_straight(p.counts,0);
}

static int full_house(params p) {
  if (check_count(p.counts,2) && check_count(p.counts,3))
    return p.sum;
  return 0;
}

static int yacht(params p) {
  FOR_EACH_VALUES ( if (p.counts[i] == 5 ) return 50;);
  return 0;
}

func *functions[12] = { 
  number_of,
  number_of,
  number_of,
  number_of,
  number_of,
  number_of,
  full_house,
  four_of,
  little_straight,
  big_straight,
  choice,
  yacht
};


int score(dice_t dice, category_t category)
{
  int counts[6] = {0};
  int sum = 0;
  for (int i=0; i<DICE_COUNT; i++)
  {
    int face = dice.faces[i];
    counts[face-1]++;
    sum += face;
  }

  params p = { counts, sum, category };
  return functions[category](p);
}

