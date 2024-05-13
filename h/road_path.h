#ifndef __road_path_h__
#define __road_path_h__

#include <bits/types/FILE.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#ifdef __linux__
#define new_roadPath(path) mkdir(path, 0777)
#elif _win32
#endif  //__linux__ ... _win32

bool create_file_open(const char *road) {
  FILE *file = fopen(road, "a");
  if (file != NULL) {
    fclose(file);
    return false;
  } else {
    fclose(file);
    return true;
  }
}

void file_openNew_roadPath(const char *road) {
  FILE *file = fopen(road, "a");

  if (file == NULL) {
    char *road_copy = strdup(road);
    short num_tokens = 0;
    short max_tokens = 10;
    char *elements;
    char **str_elements = (char **)malloc(max_tokens * sizeof(char *));

    char *token = strtok_r(road_copy, "/", &elements);

    while (token != NULL) {
      str_elements[num_tokens++] = token;

      if (max_tokens <= num_tokens) {
        max_tokens += 3;
        str_elements = (char **)realloc(str_elements, max_tokens * sizeof(char *));
      }  // if2

      token = strtok_r(NULL, "/", &elements);
    }  // while1

    char *concat_path = str_elements[0];
    for (short i = 0; i < num_tokens - 1; i++) {
      printf("\n\n\t%s\n\n", concat_path);
      new_roadPath(concat_path);
      sprintf(concat_path, "%s/%s", concat_path, str_elements[i + 1]);
    }  // for i

    free(concat_path);
    free(*str_elements);
    free(str_elements);
    free(elements);
  }  //if1

  fclose(file);

  FILE *file2 = fopen(road, "a");
  if (file2 == NULL) {
    fclose(file2);
    exit(EXIT_FAILURE);
  } else {
    fclose(file2);
  }
}  //void function
#endif  // __road_path_h__
