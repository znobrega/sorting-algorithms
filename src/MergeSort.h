void Merge(int aux[], int init, int mid, int end) {
  int i,j,k;
  int n1 = mid - init + 1;
  int n2 = end - mid;

  int left[n1], right[n2];

  for (i = 0; i < n1; i++) {
    left[i] = aux[init + i];
  }

  for (j = 0; j < n2; j++) {
    right[j] = aux[mid + 1 + j];
  }

  
    i = 0; 
    j = 0; 
    k = init; 
    while (i < n1 && j < n2) 
    { 
        if (left[i] <= right[j]) 
        { 
            aux[k] = left[i]; 
            i++; 
        } 
        else
        { 
            aux[k] = right[j]; 
            j++; 
        } 
        k++; 
    } 
  

    while (i < n1) 
    { 
        aux[k] = left[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        aux[k] = right[j]; 
        j++; 
        k++; 
    } 
}

void MergeSort(int arr[], int init, int end) {
  if (init < end) {
    int mid = (init+end)/2;
    MergeSort(arr, init, mid);
    MergeSort(arr, mid+1, end);

    Merge(arr, init, mid, end);
  }
}