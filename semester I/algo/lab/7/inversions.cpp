#include<iostream>
using namespace std;

long numOfInversions = 0, n;

void in ( long &n, long arr[] ){
    cin >> n;
    for( long i = 1; i <= n; i++ ) cin >> arr[i];
}

void inversions( long arr[], long left, long right ){
cout << left << " " << right << endl;
if ( arr[left] > arr[right] ) {
    swap(arr[left], arr[right]);
    numOfInversions++;
}

}

bool sorted ( long arr[], long n ){
    for ( long i = 1; i < n; i++ ){
        if ( arr[i] > arr[i + 1] ) return false;
    }
    return true;
}

void countInversions ( long arr[], long left, long right ){
    if ( !sorted(arr, n) ){
    if ( left < right ){
        long middle = ( left + right ) / 2;
        countInversions(arr, left, middle);
        countInversions(arr, middle + 1, right);
        inversions(arr, left, right);
    }
    }
}

int main(){
    long arr[100001];
    in(n, arr);
    countInversions(arr, 1, n);
    cout << numOfInversions;
    return 0;
}