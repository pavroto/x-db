#ifndef H_XDB_STATEMENT
#define H_XDB_STATEMENT

#include "xdb_general.h"

typedef enum {
  PREPARE_SUCCESS,
  PREPARE_UNRECOGNIZED_STATEMENT,
} xdb_prepare_result_t;

typedef enum {
  STATEMENT_SELECT,
  STATEMENT_INSERT,
} xdb_statement_type_t;

typedef struct {
   xdb_statement_type_t type; 
} xdb_statement_t;

xdb_prepare_result_t xdb_prepare_statement(xdb_string_t* input, xdb_statement_t* statement);
void xdb_execute_statement(xdb_statement_t* statement);

#endif
