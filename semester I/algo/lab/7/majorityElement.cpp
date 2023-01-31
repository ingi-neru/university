// Laszlo Kazmer
// 512
// Lab7/2
// Határozzuk meg oszd meg és uralkodj módszerrel egy 𝑛 elemű sorozat többségi elemét, ha létezik ilyen, anélkül, hogy rendeznénk azt!

#include<iostream>
using namespace std;

void in ( long &n, long arr[] ){
    cin >> n;
    for( long i = 1; i <= n; i++ ) cin >> arr[i];
}

long majority ( long n, long arr[], long left, long right){
    long maj = 1, nominated = arr[left];
    for ( long i = left + 1; i <= right; i++ ){
    if ( nominated != arr[i] ){
        if ( maj == 0 ){
            maj = 1;
            nominated = arr[i];
        }
        else {
            maj--;
        }
    }
    }
    return nominated;
}

long numberOfCandidates ( long n, long arr[] , long candidate ){
    long num = 0;
    for ( long i = 1; i <= n; i++ ){
        if ( arr[i] == candidate ) num++;
    }
    return num;
}

long majorityDivide ( long n, long arr[], long left, long right ){
    if ( n == 0 ) return -1;
    long majorityLeft, majorityRight, pivot = left + right / 2;
    majorityLeft = majority(n, arr, left, pivot );
    majorityRight = majority(n, arr, pivot + 1, right);
    if ( majorityLeft == majorityRight ) return majorityLeft;
    else{
        long leftNum, rightNum;
        leftNum = numberOfCandidates(n, arr, majorityLeft);
        rightNum = numberOfCandidates(n, arr, majorityRight);
        if ( leftNum <= n / 2 && rightNum <= n / 2) return -1;
        else{
        if ( leftNum > rightNum ) return majorityLeft;
        else return majorityRight;
        }
    }
}

int main(){
    long n, arr[100001];
    in(n, arr);
    cout << majorityDivide(n, arr, 1, n);
    return 0;
}