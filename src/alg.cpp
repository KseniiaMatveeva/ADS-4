// Copyright 2021 NNTU-CS
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

int countPairs1(int *arr, int len, int value) {
  bubbleSort(arr, len);
  int k = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = (i + 1); j < len; j++) {
      if (arr[i] + arr[j] == value) {
        k++;
      }
    }
  }
  return k;
}

int countPairs2(int *arr, int len, int value) {
  bubbleSort(arr, len);
  int k = 0;
  while (arr[len - 1] > value) {
    len--;
  }
  for (int i = 0; i < len - 1; i++) {
    for (int j = len - 1; j > i; j--) {
      if (arr[i] + arr[j] == value) {
        k++;
      }
    }
  }
  return k;
}

/*int cbinsearch(int *arr, int size, int value, int ii) {
  int count = 0;
  int i = ii, j = size - 1;
  while (i <= j) {
    int mid = i + (j - i) / 2;
    if (arr[mid] == value && mid != ii && mid != size) {
      count++;
      while (arr[mid - 1] == value && mid > ii) {
          count++;
          mid--;
        }
      while (arr[mid + 1] == value && mid < size) {
          count++;
          mid++;
        }
      break;
     } else if (arr[mid] > value) {
       j = mid - 1;
     } else {
       i = mid + 1;
      }
  }
  return count;
}*/

int countPairs3(int *arr, int len, int value) {
  bubbleSort(arr, len);
  int k = 0;
    for (int i = 0; i < len; i++) {
        int ii = i + 1;
        int jj = len - 1;
        while (ii < jj) {
            int mid = (ii + jj) / 2;
            if (arr[mid] + arr[i] < value) {
                ii = mid + 1;
            } else {
                jj = mid;
            }
        }
        while (arr[ii] + arr[i] == value) {
            k += 1;
            ii += 1;
        }
    }
  return k;
}
