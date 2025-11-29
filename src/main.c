#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "string.h"

#include "xdb_general.h"
#include "xdb_command.h"
#include "xdb_statement.h"

void print_motd() {
  printf("Welcome to X-DB!\n\n");
}

void print_prompt(xdb_string_t* filename) {
  if (!filename || filename == NULL) {
    printf("x-db> ");
    return;
  }
  printf("x-db> "); // TODO: Replace with filename
}

void read_input(xdb_string_t* input_buffer) {
  ssize_t bytes_read = getline(&(input_buffer->value), &(input_buffer->buf_size), stdin);
  
  if (bytes_read <= 0) {
    printf("Error reading input\n");
    exit(EXIT_FAILURE);
  }

  input_buffer->size = bytes_read - 1;
  input_buffer->value[bytes_read - 1] = '\0'; // Remove '\n'
}

int main(int argc, char* argv[], char** envp) {
  print_motd();
  
  xdb_string_t* input_buffer = xdb_new_string();
  while (true) {
    print_prompt(NULL);
    read_input(input_buffer);

    // Handle x-db commands starting with '.'
    if (input_buffer->value[0] == '.') {
      switch(xdb_handle_command(input_buffer)) {
        case (COMMAND_SUCCESS):
          continue;
        case (COMMAND_EXIT):
          xdb_destroy_string(input_buffer);
          exit(EXIT_SUCCESS);
        case (COMMAND_UNRECOGNIZED):
          printf("Unrecognized function \"%s\".\n", input_buffer->value);
          continue;
      }
    }

    // Handle actual SQL statement
    xdb_statement_t statement;
    switch (xdb_prepare_statement(input_buffer, &statement)) {
      case(PREPARE_SUCCESS):
        break;
      case(PREPARE_UNRECOGNIZED_STATEMENT):
        printf("Unrecognized keyword at start of \"%s\".\n", input_buffer->value);
        continue;
    }

    xdb_execute_statement(&statement);
  }
}

