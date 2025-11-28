#include "stdlib.h"

#include "xdb_general.h"

xdb_string* xdb_new_string() {

  xdb_string* result = (xdb_string*)malloc(sizeof(xdb_string));
  result->value = NULL;
  result->size = 0;
  result->buf_size = 0;

  return result;
}

void xdb_clear_string(xdb_string* target) {
  if (!target || target == NULL)
    return;

  if (target->value != NULL)
    free(target->value);

  target->size = 0;
  target->buf_size = 0;
}

void xdb_destroy_string(xdb_string* target) {
  if (!target || target == NULL)
    return;

  if (target->value != NULL)
    free(target->value);

  free(target);
}
