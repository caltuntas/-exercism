#include "anagram.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

static enum anagram_status is_anagram_of(const char *word, const char *subject)
{
  int subject_len = strlen(subject);
  int word_len = strlen(word);
  if (subject_len != word_len) return NOT_ANAGRAM;

  int sum_word =0, sum_subject =0, count =0;
  for (int i=0; i<word_len; i++) {
    sum_word += tolower(word[i]);
    sum_subject += tolower(subject[i]);
    count+=(tolower(word[i]) == tolower(subject[i]));
  }

  if (sum_subject != sum_word || word_len == count) return NOT_ANAGRAM;

  count =0;

  for (int j=0; j<subject_len; j++) {
    for (int i=0; i<word_len; i++)
    {
      if(tolower(word[i])== tolower(subject[j])) {
        count++;
        break;
      }
    }
  }
  if(count != subject_len) return NOT_ANAGRAM;
  return IS_ANAGRAM;
}

void find_anagrams(const char *subject, struct candidates *candidates)
{
  for (size_t i=0; i<candidates->count; i++){
    struct candidate *c =&candidates->candidate[i];
    c->is_anagram = is_anagram_of(c->word,subject); 
  }
}

