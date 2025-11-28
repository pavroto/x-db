#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "string.h"

#include "xdb_general.h"

void print_motd() {
  printf("Welcome to X-DB!\n\n");
}

void print_prompt(xdb_string* filename) {
  if (!filename || filename == NULL) {
    printf("x-db> ");
    return;
  }
  printf("x-db> "); // TODO: Replace with filename
}

void read_input(xdb_string* input_buffer) {
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
  
  xdb_string* input_buffer = xdb_new_string();
  while (true) {
    print_prompt(NULL);
    read_input(input_buffer);

    if (strcmp(input_buffer->value, ".exit") == 0) {
      xdb_destroy_string(input_buffer);
      exit(EXIT_SUCCESS);
    } else {
      printf("Unrecognized function \"%s\".\n", input_buffer->value);
    }

    xdb_clear_string(input_buffer);
  }
}

