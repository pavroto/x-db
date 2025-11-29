#include "stdlib.h"
#include "string.h"

#include "xdb_general.h"

xdb_string_t* xdb_new_string() {
  xdb_string_t* result = (xdb_string_t*)malloc(sizeof(xdb_string_t));
  result->value = NULL;
  result->size = 0;
  result->buf_size = 0;

  return result;
}

xdb_string_t* xdb_clone_string(xdb_string_t* src) {
  xdb_string_t* dest = xdb_new_string();

  // I will use the ->size to 
  dest->value = (char*)malloc((src->size + 1) * sizeof(char));
  strncpy(dest->value, src->value, src->size);

  dest->value[src->size] = '\0';

  dest->size = src->size;
  dest->buf_size = src->size;

  return dest;
}

void xdb_clear_string(xdb_string_t* target) {
  if (!target || target == NULL)
    return;

  if (target->value != NULL)
    free(target->value);

  target->size = 0;
  target->buf_size = 0;
}

void xdb_destroy_string(xdb_string_t* target) {
  if (!target || target == NULL)
    return;

  if (target->value != NULL)
    free(target->value);

  free(target);
}
