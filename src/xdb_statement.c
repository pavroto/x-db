#include "stdio.h"
#include "string.h"

#include "xdb_general.h"
#include "xdb_statement.h"

xdb_prepare_result_t xdb_prepare_statement(xdb_string_t* input, xdb_statement_t* statement) {
  xdb_prepare_result_t result = PREPARE_UNRECOGNIZED_STATEMENT;
  xdb_string_t* buffer = xdb_clone_string(input);

  const char delimiters[] = " ";

  char* token;
  char* saveptr;

  token = strtok_r(buffer->value, delimiters, &saveptr);

  if (strcmp(token, "insert") == 0) {
    statement->type = STATEMENT_INSERT;
    result = PREPARE_SUCCESS;
  } else if (strcmp(token, "select") == 0) {
    statement->type = STATEMENT_SELECT;
    result = PREPARE_SUCCESS;
  }

  xdb_destroy_string(buffer);
  return result;
}

void xdb_execute_statement(xdb_statement_t* statement) {
  switch (statement->type) {
    case (STATEMENT_INSERT):
      printf("INSERT statement executed.\n");
      break;
    case (STATEMENT_SELECT):
      printf("SELECT statement executed.\n");
      break;
  }
}
