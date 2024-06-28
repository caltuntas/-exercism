#include "nucleotide_count.h"

char *count(const char *dna_strand)
{
  char* str = NULL;
  int a=0,c=0,g=0,t=0;
  while (*dna_strand)
  {
    if(*dna_strand =='A') a++;
    else if(*dna_strand =='C') c++;
    else if(*dna_strand =='G') g++;
    else if(*dna_strand =='T') t++;
    else return malloc(0);
    dna_strand++;
  }
  asprintf(&str,"A:%d C:%d G:%d T:%d",a,c,g,t);
  return str;
}
