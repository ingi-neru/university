// Laszlo Kazmer
// 512
// Lab7/7
// Adott egy 𝑛 elemű egész számokat tartalmazó 𝑎 sorozat. 
// Állapítsuk meg a sorozatban található inverziók számát! Inverziónak nevezünk minden olyan 𝑖 < 𝑗 indexpárt, amelyre 𝑎𝑖 > 𝑎𝑗 .
#include<iostream>
using namespace std;

void in ( long &n, long arr[] ){
    cin >> n;
    for( long i = 0; i < n; i++ ) cin >> arr[i];
}

long merge(long arr[], long left, long middle, long right) {
  long i = left, j = middle, k = 0;
  long numOfInversions = 0;
  long aux[100001];
 
  while ((i < middle) && (j <= right)) {
    if (arr[i] <= arr[j]) {
      aux[k] = arr[i];
      ++k;
      ++i;
    } else {
      aux[k] = arr[j];
      numOfInversions += middle - i;
      ++k;
      ++j;
    }
  }
 
  while (i < middle) {
    aux[k] = arr[i];
    ++k;
    ++i;
  }
 
  while (j <= right) {
    aux[k] = arr[j];
    ++k;
    ++j;
  }
    k = 0;
  for (i = left; i <= right; i++) {
    arr[i] = aux[k];
    k++;
  }
 
  return numOfInversions;
}
long mergeSort( long arr[], long left, long right) {
        long mid = (right + left) / 2, numOfInversions = 0;
  if (right > left) {
    numOfInversions = mergeSort(arr, left, mid);
    numOfInversions += mergeSort(arr, mid + 1, right);
    numOfInversions += merge(arr, left, mid + 1, right);
  }
  return numOfInversions;
}
int main(){
    long arr[100001];
    long n;
    in(n, arr);
    cout << mergeSort(arr, 0, n - 1);
    return 0;
}