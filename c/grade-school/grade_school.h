#ifndef GRADE_SCHOOL_H
#define GRADE_SCHOOL_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_STUDENTS 20

typedef struct {
   uint8_t grade;
   char name[MAX_NAME_LENGTH];
} student_t;

typedef struct {
   size_t count;
   student_t students[MAX_STUDENTS];
} roster_t;

void init_roster(roster_t* r);
bool add_student(roster_t* r, char* str, uint8_t num);
roster_t get_grade(roster_t* r, uint8_t dg);
void sort(roster_t* r);
void sort_by_name(roster_t* r);
void swap(student_t* xp, student_t* yp);
#endif
