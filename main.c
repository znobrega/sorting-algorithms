#include <stdio.h>

void CountingSort(int a[], int b[], int k) {
  // k = a.length
  int i,max = 0;

  for (i = 0; i < k; i++) {
    if (a[i] > max) 
      max = a[i];
  }

  int c[max];

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

void CountingSortRadix(int a[], int size, int exp) {
  int i,max = 0;
  int b[size];
  int c[10] = {0};

  for (i = 0; i < max + 1; i++) {
    c[i] = 0;
  }

  for (i = 0; i < size; i ++) {
    c[a[i]]++;
  }

  for (i = 0; i < max + 1; i++) {
    c[i] += c[i-1];
  }

  for (i = size; i >= 0; i--) {
    b[--c[a[i]]] = a[i];
  }

}


void RadixSort(int arr[], int size) {
  int i, maxNum = arr[0];
  
  for (i = 0; i < size; i++) {
    if (maxNum < arr[i])
      maxNum = arr[i];
  }

  for (int exp = 1; maxNum/exp > 0; exp *= 10) {
    CountingSortRadix(arr, size, exp);
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

void BubbleSort(int arr[], int n) {
  for(int i = 0; i < n-1; i++) {
      for (int j = 0; j < n-i-1; j++) {
        if(arr[j] > arr[j+1])
          int aux = arr[j];
          arr[j] = arr[j+1];
          arr[j+1] = aux; 
      }
    }
}

int main(void) {
  int n = 6;
  int arr[n];
  arr[0] = 3;
  arr[1] = 2;
  arr[2] = 1;
  arr[3] = 3;
  arr[4] = 2;
  arr[5] = 1;

  //SelectionSort(arr, n);
  int c[10] = {0};

  for (int i = 0; i < n; i++) {
    printf("%d \n", c[i]);
  }

  printf("Hello World\n");
  return 0;
}