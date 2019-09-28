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