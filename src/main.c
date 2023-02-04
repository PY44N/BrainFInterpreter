#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *inputPointer =
      "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<++++"
      "+++++++++++.>.+++.------.--------.>+.>.";
  int memorySize = 2;
  char *memoryCells = calloc(memorySize, sizeof(char));
  char *memoryPointer = memoryCells;

  while (*inputPointer) {
    if (*inputPointer == 62) { // >
      if (memoryPointer - memoryCells >= memorySize) {
        memoryCells = realloc(memoryCells, sizeof(char) * memorySize * 2);

        // Memset didn't want to work
        char *newS = memoryCells + memorySize;
        while (newS < memorySize) {
          *newS++ = 0;
        }
        memorySize *= 2;
      }
      memoryPointer++;
    } else if (*inputPointer == 60) { // <
      memoryPointer--;
    } else if (*inputPointer == 43) { // +
      (*memoryPointer)++;
    } else if (*inputPointer == 45) { // -
      (*memoryPointer)--;
    } else if (*inputPointer == 46) { // .
      putchar(*memoryPointer);
    } else if (*inputPointer == 44) { // ,
      *memoryPointer = getchar();
    } else if (*inputPointer == 93 && *memoryPointer) { // ]
      while (*inputPointer != 91) {                     // TODO: Nested loops
        inputPointer--;
      }
    }

    inputPointer++;
  }

  return 0;
}