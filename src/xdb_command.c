#include "string.h"

#include "xdb_command.h"
#include "xdb_general.h"

xdb_command_result_t xdb_handle_command(xdb_string_t* command) {
  if (strcmp(command->value, ".exit") == 0)
    return COMMAND_EXIT;
  return COMMAND_UNRECOGNIZED;
}
