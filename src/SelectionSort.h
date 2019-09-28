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