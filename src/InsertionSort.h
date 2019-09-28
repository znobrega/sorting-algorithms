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