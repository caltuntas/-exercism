#include "rna_transcription.h"

char *to_rna(const char *dna) {
  int len = strlen(dna);
  char *rna = malloc(len+1);
  memset(rna, 0, len + 1);
  int i = 0;
  for (i = 0; i< len; i++){
    if (dna[i] =='G')
      strcat(rna,"C");
    if (dna[i] =='C')
      strcat(rna,"G");
    if (dna[i] =='T')
      strcat(rna,"A");
    if (dna[i] =='A')
      strcat(rna,"U");
  }
  rna[len] = '\0';
  return rna;
}
