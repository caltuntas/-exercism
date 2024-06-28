#include "protein_translation.h"
#define STOP (7)

proteins_t proteins(const char *const rna)
{
  char* codes[][8] =
  {
    { "AUG",NULL},
    { "UUU", "UUC",NULL},
    { "UUA", "UUG",NULL},
    { "UCU", "UCC", "UCA", "UCG" ,NULL},
    { "UAU", "UAC",NULL},
    { "UGU", "UGC",NULL},
    { "UGG",NULL},
    { "UAA", "UAG", "UGA",NULL}
  };

  proteins_t proteins = {0};
  if (strlen(rna) == 0)
  {
    proteins.valid = true;
    return proteins;
  }
  const char *ptr = rna;
  while(*ptr)
  {
    char codon[4] ={0};
    strncpy(codon,ptr,3);
    ptr +=3;
    if (strlen(codon) % 3 !=0)
    {
      proteins.valid = false;
      return proteins;
    }

    for (int i=0; i<8; i++)
    {
      for (int j=0; codes[i][j] != NULL; j++)
      {
        if(strcmp(codon,codes[i][j]) == 0)
        {
          proteins.valid = true;
          if ( i == STOP) return proteins;
          proteins.proteins[proteins.count++] = i;
        }
      }
    }
  }
  return proteins;
}
