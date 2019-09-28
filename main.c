#include <stdio.h>
#include <stdlib.h>

#define SWAP(a, b) { int aux = a; a = b; b = aux; }

#include "src/CountingSort.h"
#include "src/RadixSort.h"
#include "src/InsertionSort.h"
#include "src/SelectionSort.h"
#include "src/BubbleSort.h"
#include "src/MergeSort.h"
#include "src/QuickSort.h"

int main(int argc, char* argv[]) {
  
  char *fileName;

  fileName = argv[2];

  FILE * fp;
    char * line = NULL;
    size_t len = 0;
    size_t read;

    fp = fopen(fileName, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    int lineNumber = 0;
    
    while ((read = getline(&line, &len, fp)) != -1) {
        lineNumber++;
    }

    int numbers[lineNumber];
    lineNumber = 0;
    fp = fopen(fileName, "r");
    while ((read = getline(&line, &len, fp)) != -1) {
        int number = atoi(line);
        numbers[lineNumber] = number;
        lineNumber++;
    }

    int size = lineNumber;
    int outPut[size];

    switch (atoi(argv[1])) {
      case 1:
        CountingSort(numbers, outPut, size);
        break;    
      case 2:
        RadixSort(numbers, outPut, size);;
        break;
      case 3:
        SelectionSort(numbers, outPut, size);
        break;
      case 4:
        InsertionSort(numbers, outPut, size);
        break;
      case 5:
        BubbleSort(numbers, outPut, size);
        break;
      case 6:
        MergeSort(numbers, 0, size);
        break;
      case 7:
        QuickSort(numbers, 0, size);
        break;
      default:  
        BubbleSort(numbers, outPut, size);
        break;
    }

    for (int i = 0; i < size; i++) {
      printf("%d \n", numbers[i]);
    }

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);

  return 0;
}