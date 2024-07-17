#define _GNU_SOURCE
#include "acronym.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

char *abbreviate(const char *phrase)
{
  if (phrase==NULL || strlen(phrase) == 0 || *phrase == '\0') return NULL;
  char *str = strdup(phrase);
  char *acronym = calloc(strlen(str),sizeof(char));
  char *chr = str;
  while ((chr = strtok(chr," -_")) !=NULL) {
    char c = toupper(*chr);
    strncat(acronym,&c,1);
    chr = NULL;
  }
  free(str);
  return acronym;
}

