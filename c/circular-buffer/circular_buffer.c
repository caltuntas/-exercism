#include "circular_buffer.h"

circular_buffer_t *new_circular_buffer(size_t capacity)
{
  circular_buffer_t *cb = malloc(sizeof(cb) + capacity * sizeof(int));
  cb->size = 0;
  cb->oldest = 0;
  cb->newest = 0;
  cb->capacity = capacity;
  return cb;
}

int16_t read(circular_buffer_t *buffer, buffer_value_t *value)
{
  if (buffer->size <= 0)
  {
    errno = ENODATA;
    return EXIT_FAILURE;
  }

  *value = buffer->items[buffer->oldest];
  buffer->items[buffer->oldest] =0;
  buffer->oldest = (buffer->oldest +1) % buffer->capacity;

  if (--buffer->size == 0)
  {
    buffer->oldest =0;
    buffer->newest =0;
  }

  return EXIT_SUCCESS;
}

void delete_buffer(circular_buffer_t *buffer)
{
  free(buffer);
}

int16_t write(circular_buffer_t *buffer, buffer_value_t value)
{
  if (buffer->size == buffer->capacity)
  {
    errno = ENOBUFS;
    return EXIT_FAILURE;
  }

  buffer->size++;
  buffer->items[buffer->newest] =value;
  buffer->newest = (buffer->newest +1) % buffer->capacity;
  return EXIT_SUCCESS;
}

int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value)
{
  if (buffer->size == buffer->capacity)
  {
    buffer->items[buffer->oldest] =value;
    buffer->oldest = (buffer->oldest +1) % buffer->capacity;
    return EXIT_SUCCESS;
  }
  return write(buffer,value);
}

void clear_buffer(circular_buffer_t *buffer)
{
  buffer->oldest =0;
  buffer->newest =0;
  buffer->size =0;
}

