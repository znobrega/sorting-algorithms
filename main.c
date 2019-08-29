#include <stdio.h>
#include <stdlib.h>

void CountingSort(int a[], int b[], int k) {
  // k = Array length
  int i,max = 0;

  for (i = 0; i < k; i++) {
    if (a[i] > max) 
      max = a[i];
  }

  int c[max + 1];

  for (i = 0; i < max + 1; i++) {
    c[i] = 0;
  }

  for (i = 0; i < k; i ++) {
    c[a[i]]++;
  }

  for (i = 0; i < max + 1; i++) {
    c[i] += c[i-1];
  }

  for (i = k; i >= 0; i--) {
    b[--c[a[i]]] = a[i];
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

void RadixSort(int arr[], int b[], int size) {
  int i, maxNum = arr[0];
  
  for (i = 0; i < size; i++) {
    if (maxNum < arr[i])
      maxNum = arr[i];
  }

  for (int exp = 1; maxNum/exp > 0; exp *= 10) {
    CountingSortRadix(arr, b, size, exp);
  }
}

void InsertionSort(int arr[], int n) {
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
}

void SelectionSort(int arr[], int n) {
  int i, j, iMin, temp;
  for (i = 0; i <= n-1; i++) {
    iMin = i;
    for (j = i+1; j <= n-1; j++) {
      if (arr[j] < arr[iMin]) {
        iMin = j;
      }
    }
    if (arr[i] !=  arr[iMin]) {
      temp = arr[i];
      arr[i] = arr[iMin];
      arr[iMin] = temp;
    }
  }
}

int main(void) {

  char *fileName = "./instancias-num/num.100000.4.in";


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
    int b[size];
    RadixSort(numbers, b, size);

    for (int i = 0; i < lineNumber; i++) {
      printf("%d \n", b[i]);
    }

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);

  return 0;
}