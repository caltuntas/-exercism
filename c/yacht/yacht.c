#include "yacht.h"
#define DICE_COUNT 5
#define FOR_EACH_VALUES(action) \
  for (int i=0; i<6; i++) { \
    action \
  }

static int check_count(int counts[], int times)
{
  FOR_EACH_VALUES ( if (counts[i] == times) return 1; );
  return 0;
}

static int check_straight(int counts[], int val)
{
  if (counts[val]) return 0;
  FOR_EACH_VALUES ( if (counts[i] > 1 ) return 0;);
  return 30;
}

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

  if (category == YACHT)
    FOR_EACH_VALUES ( if (counts[i] == 5 ) return 50;);

  if (category >= ONES && category <= SIXES)
    return counts[category]*(category+1);

  if (category == FULL_HOUSE)
  {
    if (check_count(counts,2) && check_count(counts,3))
      return sum;
  }

  if (category == FOUR_OF_A_KIND)
    FOR_EACH_VALUES ( if (counts[i] >= 4) return (i+1)*4;);

  if (category == LITTLE_STRAIGHT)
    return check_straight(counts,5);

  if (category == BIG_STRAIGHT)
    return check_straight(counts,0);

  if (category == CHOICE)
    return sum;
  return 0;
}

