// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  bubbleSort(arr, len);
  int k = 0;
  int i = 0;
  while (i < len - 1) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        k++;
      }
    }
    i++;
  }
  return k;
}
int countPairs2(int *arr, int len, int value) {
  bubbleSort(arr, len);
  int k = 0;
  int i = 0;
  while (arr[len - 1] > value) {
    len--;
  }
  while (i < len) {
    for (int j = len; j > i; j--) {
      if (arr[i] + arr[j] == value) {
        k++;
      }
    }
    i++;
  }
  return k;
}
void bubbleSort(int *arr, int len) {
  int zam = 0;
  for (int i = 0; i < len; i++) {
    for (int j = len - 1; j >= i + 1; j--) {
      if (arr[j] < arr[j - 1]) {
        zam = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = zam;
      }
    }
  }
}
int cbinsearch(int *arr, int size, int value, int ii) {
  int count = 0;
  int i = ii, j = size - 1;
  while (i < j) {
    int mid = i + (j - i) / 2;
    if (arr[mid] == value) {
      count++;
      while (arr[mid - 1] == value) {
          count++;
          mid--;
        }
      while (arr[mid + 1] == value) {
          count++;
          mid++;
        }
      return count;
     } else if (arr[mid] > value) {
       j = mid;
     } else {
       i = mid + 1;
      }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  bubbleSort(arr, len);
  int k = 0;
  for (int i = 0; i < len; i++) {
    k += cbinsearch(arr, len, value - arr[i], i + 1);
  }
  return k;
}
