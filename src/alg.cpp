// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int k = 0;
  int i = 0;
  while (i < len - 1) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        k++ ;
      }
    }
    i++;
  }
  return k;
}
int countPairs2(int *arr, int len, int value) {
  int k = 0;
  int i = 0;
  while (i < len - 1) {
    for (int j = len - 1; j > i; j--) {
      if (arr[i] + arr[j] == value) {
        k++;
      }
    }
    i++;
  }
  return k;
}
int countPairs3(int *arr, int len, int value) {
  int k = 0;
  int i = 0;
  int j = len - 1;
  while (i < len ) {
    int per = value - arr[i];
    int ii = i + 1;
    while (ii < j) {
      int mid = (ii + j) / 2;
      if (arr[mid] == per) {
        k++;
        while (arr[mid - 1] == per) {
          k++;
          mid--;
        }
        while (arr[mid + 1] == per) {
          k++;
          mid++;
        }
        break;
       } else if (arr[mid] > per) {
         j = mid;
       } else {
         ii = mid + 1;
       }
    }
    i++;
  }
  return k;
}
