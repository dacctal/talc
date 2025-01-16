#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

void getFilePath(char *filePath, size_t size) {
  // Get the home directory path
  const char *homeDir = getenv("HOME");
  if (homeDir == NULL) {
    printf("Error: Could not find the home directory.\n");
    exit(1);
  }

  // Construct the directory path
  char dirPath[256];
  snprintf(dirPath, sizeof(dirPath), "%s/.talc", homeDir);

  // Create the directory if it doesn't exist
  if (mkdir(dirPath, 0777) != 0 && errno != EEXIST) {
    perror("Error creating directory");
    exit(1);
  }

  // Construct the full file path
  snprintf(filePath, size, "%s/history.csv", dirPath);
}

void storeData(float num1, char operation, float num2, float result) {
  char filePath[256];
  getFilePath(filePath, sizeof(filePath));

  FILE *fptr = fopen(filePath, "a");
  if(fptr == NULL) {
    printf("Error: Unable to create/open file.");
    exit(1);
  }

  int is_header_written = 0; // Ensures the header is written only once
  if (ftell(fptr) == 0) {
    fprintf(fptr, "N1,OP,N2,E,R\n");
    is_header_written = 1;
  }

  fprintf(fptr, "%f %c %f = %f\n", num1, operation, num2, result);

  fclose(fptr);
}

void readData() {
  char filePath[256];
  getFilePath(filePath, sizeof(filePath));

  FILE *fptr = fopen(filePath, "r"); // Open the file in read mode
  if (fptr == NULL) {
    printf("Error: Unable to open file %s.\n", filePath);
    exit(1);
  }

  char line[256]; // Buffer to store each line

  if (fgets(line, sizeof(line), fptr) == NULL) {
    printf("Error: File is empty or couldn't read the first line.\n");
    fclose(fptr);
    return;
  }

  printf("History:\n");

  while (fgets(line, sizeof(line), fptr)) {
    printf("%s", line); // Print each line
  }

  fclose(fptr);
}
