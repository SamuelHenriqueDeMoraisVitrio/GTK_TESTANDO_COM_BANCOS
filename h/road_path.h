#ifndef __road_path_h__
#define __road_path_h__

#include <bits/types/FILE.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __linux__
#define new_roadPath(road) mkdir(road, 0777)
#elif _win32
#endif  //__linux__ ... _win32

void file_openNew_roadPath(const char *road) {
  FILE *file = fopen(road, "a");

  if (file != NULL) {
    fclose(file);
  } else {
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
      }  // if1

      token = strtok_r(NULL, "/", &elements);
    }  // while1

    for (short i = 0; i < num_tokens; i++) { printf("\n\n\t%s\n", str_elements[i]); }  // for i

    //free(str_elements[i]);
    free(str_elements);
    //free(elements);
    //free(road_copy);
    //free(token);
  }  //elsei1
}  //void function
#endif  // __road_path_h__
