// Laszlo Kazmer
// 512
// Lab4/5
// Rendezzünk egy 𝑛 elemű tömböt számjegyes rendezéssel!
// A bemenet első sora tartalmazza az 𝑛 értéket, a többi 𝑛 sor a sorozat elemeit.
#include <iostream>
#include <climits>
using namespace std;

unsigned long long maxkivalaszt1 ( unsigned long long n, unsigned long long a[]){
    unsigned long long maxi = a[1];
    for ( unsigned long long i = 2; i <= n ;i++ ){
        if ( maxi < a[i] ) maxi = a[i];
    }
    return maxi;
}

void countSort(unsigned long long tomb[], unsigned long long n, unsigned long long hatv, unsigned long long maxi)
{
    unsigned long long seged[101], darab[11]; 
    for ( unsigned long long i = 0; i < 10; i++ ){
    darab[i] = 0;
    }
    for (unsigned long long i = 1; i <= n; i++){
        darab[(tomb[i] / hatv) % 10]++;
    }
    for (unsigned long long i = 1; i < 10; i++){
        darab[i] += darab[i - 1];
    }
    for (unsigned long long i = n; i >= 1; i--) {
        seged[darab[(tomb[i] / hatv) % 10]] = tomb[i];
        darab[(tomb[i] / hatv) % 10]--;
    }
    for (unsigned long long i = 1; i <= n; i++){
        tomb[i] = seged[i];
    }
}

void radixsort(unsigned long long tomb[], unsigned long long n)
{   
    unsigned long long maxi = maxkivalaszt1(n, tomb);
    for (unsigned long long hatv = 1; maxi / hatv > 0; hatv *= 10){ 
        countSort(tomb, n, hatv, maxi);
    }
}

void be(unsigned long long &n, unsigned long long tomb[])
{
    cin >> n;
    for (unsigned long long i = 1; i <= n; i++){
        cin >> tomb[i];
    }
}   

int main()
{
    unsigned long long n = 1, tomb[101];
    be(n, tomb);
    radixsort(tomb, n);
    for (unsigned long long i = 1; i <= n; i++){
        cout << tomb[i] << endl;
    }
    return 0;
}