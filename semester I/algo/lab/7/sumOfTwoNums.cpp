// Laszlo Kazmer
// 512
// Lab7/4
// Adott egy 𝑛 elemű tömb, mely 32 bites előjeles egész számokat tartalmaz és egy 𝑥 32 bites előjeles egész szám. 
// Határozzuk meg, hogy létezik-e két olyan eleme a tömbnek, melyek összege pontosan 𝑥. Alkalmazzunk bináris keresést!
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

long long sol1 = LLONG_MAX, sol2 = LLONG_MAX;
void in ( long long &n, long long &num, long long arr[], long long aux[] ){
    cin >> n;
    cin >> num;
    for( long long i = 1; i <= n; i++ ) {
        cin >> arr[i];
        aux[i] = arr[i];
    }
}

void beszurorendezes ( long long n, long long tomb[] ){
    for ( long long j = 2; j <= n; j++ ){
    long long seged = tomb[j], i = j - 1;
    while ( i > 0 && tomb[i] > seged ){
        tomb[i + 1] = tomb[i];
        i--;
    }
    tomb[i + 1] = seged;
    }
}

long long binKerRek ( long long left, long long right, long long num, long long arr[], long long ind ){
    if ( left > right ){
        return -1;
    }
    else{
        long long middle = (left + right) / 2;
        if ( num > arr[middle] ){
            return binKerRek(middle + 1, right, num, arr, ind);
        }
        else {
            if ( num < arr[middle] ){
                return  binKerRek(left, middle - 1, num, arr, ind); 
            }
            else if ( middle != ind ){ 
                return middle;
            }
        }
    }
}

void writeAns ( long long n, long long num1, long long num2, long long aux[] ){
long long index = 0, j = 1, solution1, solution2;
while ( j <= n && !index ){
    if ( aux[j] == num1 ) index = j;
    j++;
}
solution1 = index;
j = 1;
index = 0;
while ( j <= n && !index ){
    if ( aux[j] == num2 && solution1 != j ) index = j;
    j++;
}
solution2 = index;
if ( solution1 > solution2 ) swap(solution1, solution2);
if ( min(sol1, sol2) > min(solution1, solution2) ){
    sol1 = solution1, sol2 = solution2;
}
}

void sumOfTwoNums ( long long n, long long num, long long arr[], long long aux[] ){
bool megoldas = false;
for ( long long i = 1; i <= n - 1; i++ ){
    long long searched = 0, index;
    if ( num > 0 ){
        searched = num - arr[i];
    }
    else{
        if ( arr[i] > 0 ) searched = num + arr[i];
        else searched = num - arr[i];
    }
    index = binKerRek(1, n, searched, arr, i);
    if ( index != -1 ){
        if ( !megoldas){
        cout << 1 << endl;
        }
        megoldas = true;
        writeAns(n, arr[i], arr[index], aux);
    }
}
if ( !megoldas ) cout << 0;
else{
    if ( sol1 > sol2 ) swap(sol1, sol2);
    cout << sol1 << " " << sol2;
}
}


int main(){
    long long n, num, arr[100001], aux[100001];
    in(n, num, arr, aux);
    beszurorendezes(n, arr);
    sumOfTwoNums(n, num, arr, aux);
    return 0;
}

