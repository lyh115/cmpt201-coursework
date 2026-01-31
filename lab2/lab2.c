#define _POSIX_C_SOURCE 200811L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int main() {

  while (1) {
    printf("Enter programs to run.\n");
    printf("> ");
    char *line_ptr = NULL;
    char *strotk = NULL;
    size_t size = 0;
    ssize_t user_input = getline(&line_ptr, &size, stdin);
    if (line_ptr[user_input - 1] == '\n') {
      line_ptr[user_input - 1] = '\0';
    }
    char *result = strtok_r(line_ptr, "/", &strotk);
    char *path = malloc(sizeof(char) * 100);
    int i = 1;
    int path_size = 100;
    path[0] = '/';
    while (result != NULL) {

      for (int j = 0; j < strlen(result); j++) {
        path[i] = result[j];
        i++;
      }
      path[i] = '/';
      i++;
      result = strtok_r(NULL, "/", &strotk);
      if (result != NULL && i + strlen(result) >= path_size) {
        char *cache = realloc(path, i + strlen(result) + 5);
        if (cache != NULL) {
          path = cache;
          path_size = i + strlen(result) + 5;
          free(cache);
        }
      }
    }
    path[i - 1] = '\0';
    pid_t pid = fork();
    if (pid == 0) {
      execl(path, result, NULL);
      printf("Exec failure\n");
      _exit(0);
    } else {
      waitpid(pid, NULL, 0);
    }

    free(line_ptr);
    free(path);
  }
}
