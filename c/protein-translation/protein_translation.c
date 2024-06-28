#include "protein_translation.h"

proteins_t proteins(const char *const rna)
{

  proteins_t proteins = {0};
  proteins.valid = false;
  proteins.count = 0;
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

    if(strcmp(codon,"AUG") == 0)
    {
      proteins.proteins[proteins.count++] = Methionine;
      proteins.valid = true;
    }
    if(strcmp(codon,"UUU") == 0 || strcmp(codon,"UUC") == 0)
    {
      proteins.proteins[proteins.count++] = Phenylalanine;
      proteins.valid = true;
    }
    if(strcmp(codon,"UUA") == 0 || strcmp(codon,"UUG") == 0)
    {
      proteins.proteins[proteins.count++] = Leucine;
      proteins.valid = true;
    }
    if(strcmp(codon,"UCU") == 0 || strcmp(codon,"UCA") == 0 || strcmp(codon,"UCC") == 0 || strcmp(codon,"UCG") == 0)
    {
      proteins.proteins[proteins.count++] = Serine;
      proteins.valid = true;
    }
    if(strcmp(codon,"UAC") == 0 || strcmp(codon,"UAU") == 0)
    {
      proteins.proteins[proteins.count++] = Tyrosine;
      proteins.valid = true;
    }
    if(strcmp(codon,"UGU") == 0 || strcmp(codon,"UGC") == 0)
    {
      proteins.proteins[proteins.count++] = Cysteine;
      proteins.valid = true;
    }
    if(strcmp(codon,"UGG") == 0)
    {
      proteins.proteins[proteins.count++] = Tryptophan;
      proteins.valid = true;
    }
    if (strcmp(codon,"UAA") == 0 || strcmp(codon,"UAG") == 0 || strcmp(codon,"UGA") == 0)
    {
      proteins.valid = true;
      break;
    }
  }
  return proteins;
}
