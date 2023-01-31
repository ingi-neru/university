#include<iostream>
#include<algorithm>
using namespace std;

void calcCoins ( int i ){
    int n;
    cin >> n;
    unsigned long long *a = new unsigned long long [n + 1];
    for ( int i = 1; i <= n; i++ ){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    cout << "Case #" << i << ": ";
    if ( n == 0 || n == 1){
        cout << n << endl;
    }
    else{
    unsigned long long sum = a[1];
    int num = 1;
    for ( int i = 2; i < n; i++ ){
        if ( sum + a[i] < a[i + 1]){
            sum += a[i];
            num++;
        }
    }
    cout << num + 1 << endl;
    }
}

void in ( int &cases, int &n, long long coins[] ){
    cin >> cases;
    for ( int i = 1; i <= cases; i++ ){
        
        calcCoins(i);
    }
   
}

int main(){
    int n, cases;
    long long coins[1010];
    in(cases, n, coins);
    return 0;
}