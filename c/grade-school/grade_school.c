#include "grade_school.h"
#include <stdio.h>

void init_roster(roster_t *r) {
  r->count = 0;  
}

bool add_student(roster_t* r, char* str, uint8_t num) {
  uint8_t i= 0;
  for (i =0; i<r->count; i++) {
    if (strcmp(str,r->students[i].name)==0) {
      return false;
    }
  }

  student_t s = {.grade = num };
  strcpy(s.name, str);
  r->students[r->count] = s;
  r->count+=1;
  sort(r);
  sort_by_name(r);
  return true;
}

void sort(roster_t* r) {
  uint8_t i,j,min_id;
  for (i=0; i<r->count; i++) {
    student_t s = r->students[i];
    min_id = i;
    for (j=i+1; j<r->count; j++) {
      if (r->students[j].grade < r->students[min_id].grade)
        min_id =j;
    }
    swap(&r->students[min_id], &r->students[i]);
    printf("name %s",s.name);
  }
}

void sort_by_name(roster_t* r) {
  uint8_t i,j,min_id;
  student_t sj,smin;
  for (i=0; i<r->count; i++) {
    min_id = i;
    for (j=i+1; j<r->count; j++) {
      sj = r->students[j];
      smin = r->students[min_id];
      if (sj.grade == smin.grade && strcmp(sj.name, smin.name) < 0)
        min_id =j;
    }
    swap(&r->students[min_id], &r->students[i]);
  }
}

void swap(student_t* xp, student_t* yp) 
{ 
    student_t temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

roster_t get_grade(roster_t* r, uint8_t dg) {
  uint8_t i;
  roster_t rgrades;
  init_roster(&rgrades);
  for (i =0; i< r->count; i++) {
    if (r->students[i].grade == dg)
      add_student(&rgrades,r->students[i].name, r->students[i].grade);
  }
  return rgrades;
}
