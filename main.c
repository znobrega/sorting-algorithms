#include <stdio.h>
#include <stdlib.h>

#define SWAP(a, b) { int aux = a; a = b; b = aux; }

void CountingSort(int a[], int b[], int size) {
  int i, max = 0, min = 0, k;

  for (i = 0; i < size; i++) {
    if (a[i] > max) 
      max = a[i];
    
    if (a[i] < min) 
      min = a[i];
  }
  
  k = max - min + 1;

  int c[k + 1];

  for (i = 0; i < k; i++) {
    c[i] = 0;
  }

  for (i = 0; i < size; i ++) {
    c[a[i] - min]++;
  }

  for (i = 0; i < k; i++) {
    c[i] += c[i-1];
  }

  for (i = size; i >= 0; i--) {
    b[--c[a[i] - min]] = a[i];
  }

}

void CountingSortRadix(int a[], int b[], int size, int exp) {
  int i,max = 0;
  int c[19] = {0};

  for (i = 0; i < size; i ++) {
    c[((a[i]/exp)%10)+9]++;
  }

  for (i = 1; i < 19; i++) {
    c[i] += c[i-1];
  }

  for (i = size - 1; i >= 0; i--) {
    int aux = --c[((a[i]/exp)%10) + 9];
    b[aux]= a[i];
    
  }

  for (i = 0; i < size; i++) 
        a[i] = b[i]; 

}

void RadixSort(int arr[], int outPut[], int size) {
  int i, maxNum = arr[0];
  
  for (i = 0; i < size; i++) {
    if (maxNum < arr[i])
      maxNum = arr[i];
  }

  for (int exp = 1; maxNum/exp > 0; exp *= 10) {
    CountingSortRadix(arr, outPut, size, exp);
  }

  for (int i = 0; i < size; i++) {
    outPut[i] = arr[i];
  }
}

void InsertionSort(int arr[], int outPut[], int n) {
  int i, j, pivo = 0;
  for (i = 1; i <= n-1; i++) {
    pivo = arr[i];
    j = i-1;
    while (j >= 0 && arr[j] > pivo) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = pivo;
  }

  
  for (int i = 0; i < n; i++) {
    outPut[i] = arr[i];
  }
}

void SelectionSort(int arr[], int outPut[], int n) {
  int i, j, iMin, temp;
  for (i = 0; i <= n-1; i++) {
    iMin = i;
    for (j = i+1; j <= n-1; j++) {
      if (arr[j] < arr[iMin]) {
        iMin = j;
      }
    }
    if (arr[i] !=  arr[iMin]) {
      SWAP(arr[i], arr[iMin]);
    }
  }

  for (int i = 0; i < n; i++) {
    outPut[i] = arr[i];
  }
}

void BubbleSort(int arr[], int outPut[], int n) {
  for(int i = 0; i < n-1; i++) {
      for (int j = 0; j < n-i-1; j++) {
        if(arr[j] > arr[j+1]) {
          SWAP(arr[j], arr[j+1])
        }
      }
    }

  for (int i = 0; i < n; i++) {
    outPut[i] = arr[i];
  }
  
}

int main(int argc, char* argv[]) {

  
  char *fileName;

  fileName = argv[2];

  FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

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
        printf("counting");
        fflush(stdout);
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
      default:  
        BubbleSort(numbers, outPut, size);
        break;
    }

    for (int i = 0; i < size; i++) {
      printf("%d \n", outPut[i]);
    }

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);

  return 0;
}