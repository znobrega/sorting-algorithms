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