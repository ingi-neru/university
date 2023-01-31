// Laszlo Kazmer
// 512
// Lab7/2
// Adott egy 𝑛 elemű tömb, mely 64 bites valós számokat tartalmaz és egy 𝑘 természetes szám. 
// Határozzuk meg a tömb 𝑘. legkisebb elemét, anélkül, hogy rendeznénk azt, vagy használnánk az nth_element függvényt!
#include<iostream>
using namespace std;

void in ( long double &n, long double &k, long double arr[] ){
    cin >> n;
    cin >> k;
    for( long i = 1; i <= n; i++ ) cin >> arr[i];
}

long double lomutoPartitions ( long double arr[], long left, long right ){
    long pivot = arr[right], i = left - 1;
    for ( long j = left; j < right; j++ ){
        if ( arr[j] <= pivot ){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

long double nMinDivImp( long double arr[], long double k, long left, long right ){
    if ( left == right ){
        return arr[right];
    }
    long pos = lomutoPartitions(arr, left, right), i = pos - left + 1;

    if ( i == k ){
        return arr[pos];
    }
    else if ( i > k ){
        return nMinDivImp(arr, k, left, pos - 1);
    }
    else{
        return nMinDivImp(arr, k - i, pos + 1, right);
    }
}

int main(){
    long double n, k, arr[100001];
    in(n, k, arr);
    cout << nMinDivImp(arr, k, 1, n);
    return 0;
}