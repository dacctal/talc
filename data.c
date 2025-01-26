#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

const char * makeDirectory(const char *home) {

  const char *dir = ".local/share/talc";
  static char fullPath[1024];

  snprintf(fullPath, sizeof(fullPath), "%s/%s", home, dir);



  // ------ DEBUG ------
  // struct stat dir_info;
  // if (stat(fullPath, &dir_info) != 0) {
  //   // Directory doesn't exist; create it
  //   if (mkdir(fullPath, 0755) != 0) {
  //     fprintf(stderr, "Error: Unable to create directory '%s'.\n", fullPath);
  //     exit(1);
  //   }
  //   printf("Directory '%s' created.\n", fullPath);
  // } else {
  //   printf("Directory '%s' already exists.\n", fullPath);
  // }
  // -------------------


  
  return fullPath;

}



void checkDirectory(char fullPath[], const char *dir) {

  struct stat dir_info;

  if (stat(fullPath, &dir_info) == 0 && S_ISDIR(dir_info.st_mode)) {
    printf("Directory '%s' exists in the home directory.\n", dir);
  } else {
    printf("Directory '%s' does not exist in the home directory.\n", dir);
  }

}



const char * getHome() {

  const char *home = getenv("HOME");

  if(home == NULL) {
    fprintf(stderr, "ERROR: Unable to retrieve home directory.\n");
    exit(1);
  }

  // printf("Home: %s", home);

  return home;

}



int getAddress(const char *filePath) {

    FILE *file = fopen(filePath, "r");

    if (file == NULL) {
        return 0;
    }

    int lines = 0;
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), file)) {
        lines++;
    }

    fclose(file);

    return lines;
}



void readFile() {

  const char *home = getHome();
  const char *dir = makeDirectory(home);

  char filePath[1024];
  snprintf(filePath, sizeof(filePath), "%s/%s", dir, "history.txt");

  FILE *file = fopen(filePath, "r");

  if(file == NULL) {
    fprintf(stderr, "ERROR: Unable to open file '%s'.\n", filePath);
    exit(1);
  }

  char buffer[1024];

  while(fgets(buffer, sizeof(buffer), file) != NULL) {
    printf("%s", buffer);
  }

  fclose(file);

}



void writeFile(float num1, char operation, float num2, float result) {

  const char *home = getHome();
  const char *dir = makeDirectory(home);

  char filePath[1024];
  snprintf(filePath, sizeof(filePath), "%s/%s", dir, "history.txt");

  FILE *history = fopen(filePath, "a");

  if (history == NULL) {
    fprintf(stderr, "Error: Unable to open file '%s'.\n", filePath);
    exit(1);
  }

  int address = getAddress(filePath);

  fprintf(history, "%i: %f %c %f = %f\n", address + 1, num1, operation, num2, result);

  fclose(history);

}
