#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int main() {
  printf("Please enter some text: ");
  char *line_ptr = NULL;
  size_t size = 0;
  ssize_t user_input = getline(&line_ptr, &size, stdin);
  char *strtok_ptr = NULL;
  char *result = strtok_r(line_ptr, " ", &strtok_ptr);
  printf("Tokens: \n");
  while (result != NULL) {
    printf(" %s\n", result);
    result = strtok_r(NULL, " ", &strtok_ptr);
  }
  free(line_ptr);

  return 0;
}
