//#define SWAP(a, b) { int aux = a; a = b; b = aux; }

int partition(int arr[], int init, int end) {
  int pivot = arr[end];

  int i = init - 1;

  for (int j = init; j <= end -1; j++) {

    if (arr[j] < pivot) {
      i++;
      SWAP(arr[i], arr[j]);
    }

  }

  SWAP(arr[i + 1], arr[end]);

  return (i + 1);
}

void QuickSort(int arr[], int init, int end) {
  if (init < end) {
    int q = partition(arr, init, end);
    
    QuickSort(arr, init, q - 1);
    QuickSort(arr, q + 1, end);
  }
}