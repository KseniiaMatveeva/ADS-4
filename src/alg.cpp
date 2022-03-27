// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int k = 0;
  int i = 0;
  while (i < len){
    for (int j = i + 1; j < len; j++){
      if (arr[i] + arr[j] == value) {
        k++;
      }
    }
    i++;
  }
  return k;
}
int countPairs2(int *arr, int len, int value) {
  int k = 0;
  int i = 0;
  int j = len - 1;
  while (i < j){
    for (int jj = len - 1; jj > (len / 2); jj--){
      if (arr[i] + arr[jj] == value) {
        k++;
      }
    }
    i++;
    j--;
  }
  return k;
}
int countPairs3(int *arr, int len, int value) {
  int k = 0;
  int i = 0;
  int ii = i;
  int j = len - 1;
  int jj = j;
  while (arr[i] < (value)/2) {
    int per = value - arr[i];
    while (ii < jj) {
      int mid = ii + (jj - ii) / 2;
      if (arr[mid] == per) {
        k++;
       } else if (arr[mid] > per) {
         jj = mid;
       } else {
         ii = mid + 1;
       }
    }
    i++;
  }
  return k;
}
