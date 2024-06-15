#include "luhn.h"

bool luhn(const char *num) 
{
  int doubles[] = {0,2,4,6,8,1,3,5,7,9};
  int j = 1;
  int sum = 0;
  for (int i=strlen(num)-1; i>=0; i--)
  {
    char chr = num[i];
    if(chr >= '0' && chr <= '9')
    {
      int d = num[i]- '0';
      sum += j % 2 ? d:doubles[d];
      j++;
    }
    else if(chr != ' ')
      return 0;
  }
  return j >2 && sum % 10 == 0;
}
