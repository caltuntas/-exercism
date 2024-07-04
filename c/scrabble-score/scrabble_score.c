#include "scrabble_score.h"

typedef struct {
  char *letters;
  int value;
} score_t;

unsigned int score(const char *word)
{
  score_t scores[] = {
    {"aeioulnrst",1},
    {"dg",2},
    {"bcmp",3},
    {"fhvwy",4},
    {"k",5},
    {"jx",8},
    {"qz",10},
  };

  int sum =0;
  for (unsigned long i=0; i<strlen(word); i++)
  {
    char chr = word[i] | 1 << 5;
    for (int j=0; j<7; j++)
    {
      score_t s = scores[j];
      if (strchr(s.letters,chr) != NULL)
        sum +=s.value;
    }
  }
  return sum;
}
