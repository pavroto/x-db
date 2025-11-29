#ifndef H_XDB_COMMAND
#define H_XDB_COMMAND

#include "xdb_general.h"

typedef enum {
  COMMAND_SUCCESS,
  COMMAND_EXIT,
  COMMAND_UNRECOGNIZED,
} xdb_command_result_t;

xdb_command_result_t xdb_handle_command(xdb_string_t* command);

#endif
