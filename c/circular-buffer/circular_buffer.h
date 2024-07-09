#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <stdint.h>

typedef int buffer_value_t;

typedef struct {
  int capacity;
  int size;
  int oldest;
  int newest;
  buffer_value_t items[];
} circular_buffer_t;

circular_buffer_t *new_circular_buffer(size_t size);
int16_t read(circular_buffer_t *buffer, buffer_value_t *value);
void delete_buffer(circular_buffer_t *buffer);
int16_t write(circular_buffer_t *buffer, buffer_value_t value);
int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value);
void clear_buffer(circular_buffer_t *buffer);
#endif
