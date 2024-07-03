#include "all_your_base.h"

size_t rebase(int8_t digits[],int16_t input_base,int16_t output_base,size_t input_length)
{
  if (input_length == 0) return 0;
  if (input_base <2 ) return 0;
  if (output_base <2 ) return 0;
  for (size_t i=0; i<input_length; i++)
  {
    if (digits[i] < 0 || digits[i] >= input_base ) return 0;
  }

  int sum =0;
  for (size_t i=input_length,j=0; i>0; i--,j++)
  {
    int digit = digits[i-1];
    int power = pow(input_base,j);
    sum += ( digit * power );
  }

  int result =1;
  int total = sum;
  while(sum >= output_base)
  {
    sum = sum / output_base;
    result++;
  }

  for (int j=result-1; j>=0; j--)
  {
    int tmp = total % output_base;
    total = total / output_base;
    digits[j] = tmp;
  }

  return result;
}
