#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

typedef struct usr_input {
  char *result;
  struct usr_input *next;
  struct usr_input *prev;
} usr_input;

void print_5(usr_input *head) {
  int count = 0;
  usr_input *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  while (count < 4 && temp->prev != NULL) {
    temp = temp->prev;
    count++;
  }
  while (count >= 0 && temp != NULL) {
    printf("%s", temp->result);
    temp = temp->next;
    count--;
  }
}

int main() {
  usr_input *head = NULL;
  while (1) {
    char *lineptr = NULL;
    size_t size = 0;

    printf("Enter input: ");
    usr_input *n = malloc(sizeof(*n));
    if (head == NULL) {
      head = n;
      ssize_t input = getline(&lineptr, &size, stdin);
      n->result = lineptr;
      n->next = NULL;
      n->prev = NULL;
      if (strcmp(lineptr, "print\n") == 0) {
        print_5(head);
        while (head != NULL) {
          usr_input *free_cache = head;
          head = head->next;
          free(free_cache);
        }
        free(lineptr);
      }
    } else {
      usr_input *cache = head;
      while (cache->next != NULL) {
        cache = cache->next;
      }
      cache->next = n;
      n->prev = cache;
      ssize_t input = getline(&lineptr, &size, stdin);
      n->result = lineptr;
      n->next = NULL;
      if (strcmp(lineptr, "print\n") == 0) {
        print_5(head);
        while (head != NULL) {
          usr_input *free_cache = head;
          head = head->next;
          free(free_cache);
        }
        free(lineptr);
      }
    }
  }
}
