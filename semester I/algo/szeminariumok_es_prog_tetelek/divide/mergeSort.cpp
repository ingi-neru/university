#include<iostream>
using namespace std;

long numOfInversions = 0;

void merge(long arr[], long left, long mid, long right) {
  long i = left, j = mid + 1, k = 0;
  long invCount = 0;
  long temp[(right - left + 1)];
 
  while ((i < mid) && (j <= right)) {
    if (arr[i] <= arr[j]) {
      temp[k] = arr[i];
      ++k;
      ++i;
    } else {
      temp[k] = arr[j];
      invCount += (mid - i);
      ++k;
      ++j;
    }
  }
 
  while (i < mid) {
    temp[k] = arr[i];
    ++k;
    ++i;
  }
 
  while (j <= right) {
    temp[k] = arr[j];
    ++k;
    ++j;
  }
 
  for (i = left, k = 0; i <= right; i++, k++) {
    arr[i] = temp[k];
  }
 
}

void mergeSort ( long arr[], long left, long right ){
    if ( left < right ){
        long middle = ( left + right ) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

int main(){
    long arr[101] = {-1, 2, 4, 3, 1}, n = 4;
    mergeSort(arr, 1, n);


    for ( long i = 1; i <= n; i++ ){
        cout << arr[i] << " ";
    }
    cout << endl<< numOfInversions << endl;
    return 0;
}