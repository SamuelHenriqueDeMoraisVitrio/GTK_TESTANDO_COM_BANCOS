#ifndef __road_path_h__
#define __road_path_h__

#include <bits/types/FILE.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef __linux__
#define new_roadPath(road) mkdir(road, 0777)
#elif _win32
#endif  //__linux__ ... _win32

void file_openNew_roadPath(const char *road) {
  FILE *path = fopen(road, "a");

  if (path != NULL) {
    fclose(path);
  } else {
    bool j = false;
    char *roadDirs;
    for (int i = strlen(road); i >= 0; i--) {
      if ((road[i] == '/' || road[i] == '\\') && !j) { j = true; }
      if (j) {
        roadDirs = (char *)malloc(i * sizeof(char));
        roadDirs[i] = road[i];
      }
    }
    printf("\n\n\t%s\n\n", roadDirs);
    free(roadDirs);
  }
}
#endif  // __road_path_h__
