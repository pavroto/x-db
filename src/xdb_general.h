#ifndef H_XDB_GENERAL
#define H_XDB_GENERAL

#include "stdlib.h"

typedef struct {
  char* value;
  ssize_t size; // Size of the actual content
  size_t buf_size; // Size of allocated memory
} xdb_string;

xdb_string* xdb_new_string();
void xdb_clear_string(xdb_string* target);
void xdb_destroy_string(xdb_string* target);

#endif
