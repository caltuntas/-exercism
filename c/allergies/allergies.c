#include "allergies.h"

int codes[] = { 1, 2, 4, 8, 16, 32, 64, 128 };

bool is_allergic_to(allergen_t a, int n)
{
  return (codes[a] & n) == codes[a];
}
allergen_list_t get_allergens(int a) 
{
  allergen_list_t list = { 0 };
  for (int i =0; i<ALLERGEN_COUNT; i++)
  {
    int allergic=is_allergic_to(i,a);
    list.allergens[i] =allergic;
    list.count += allergic;
  }
  return list;
}

