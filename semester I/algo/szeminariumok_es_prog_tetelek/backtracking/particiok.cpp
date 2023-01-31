#include<iostream>
using namespace std;

void Particiok( int n, int ered[], int h, int k ){
    if ( k > n ){
        for ( int i = 1; i <= h; i++ ){
            cout << "{";
            for ( int j = 1; j <= k; j++ ){
                if ( ered[j] == i )
                    cout << j << " ";
            }
            cout << "}";
        }
        cout << endl;
        
    }
    else{
        for ( int i = 1; i <= h + 1; i++ ){
        ered[k] = i;
        Particiok(n, ered, max(i, h), k + 1);
        }
    }
}

int main(){
    int n, ered[111], h = 1, k = 1;
    cin >> n;
    Particiok(n, ered, h, k);
    return 0;
}