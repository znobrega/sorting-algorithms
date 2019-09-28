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
