#include<iostream>
using namespace std;

long binSearch ( long left, long right, long num, long arr[] ){
    if ( left > right ){
        return -1;
    }
    else{
        long middle = (left + right) / 2;
        if ( num > arr[middle] ){
            return binSearch(middle + 1, right, num, arr);
        }
        else {
            if ( num < arr[middle] ){
                return  binSearch(left, middle - 1, num, arr); 
            }
            else{
                return middle;
            }
        }
    }
}

int main(){
    long n = 5, arr[10] = { -1, -33, 10, 21, 46, 51};
    cout << binSearch(1, n, -33, arr);
    return 0;
}