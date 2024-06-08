#include "high_scores.h"

static int cmp(const void* a, const void* b) {
    int f = *((int*)a);
    int s = *((int*)b);
    return f-s;
}

int32_t latest(const int32_t *scores, size_t scores_len) {
  return scores[scores_len-1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len) {
  qsort((void*)scores,scores_len,sizeof(int32_t),cmp);
  return scores[scores_len-1];
}

size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output) {
  qsort((void*)scores,scores_len,sizeof(int32_t),cmp);
  size_t len = 3;
  if (scores_len < 3)
    len = scores_len;
  for (size_t i=0; i<len; i++)
  {
    output[i] = scores[scores_len-(i+1)];
  }
  return len;
}
