#ifndef __road_path_h__
#define __road_path_h__

#include <bits/types/FILE.h>
#include <stdio.h>
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
    char *road_copy = (char *)strdup(road);
    char **elements;

    for (short i = 0; i < strlen(road); i++) {}
  }  //elsei1
}  //void function
#endif  // __road_path_h__
