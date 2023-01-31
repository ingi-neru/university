#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

ll sumOfTrees ( ll trees[], int n, int mid ){
    ll sum = 0;
    for ( int i = 1; i <= n; i++ ){
        if ( trees[i] > mid ){
            sum += trees[i] - mid;
        }
    }
    return sum;
}

ll binSearch ( ll trees[], int N, int M ){
    int left = 1, right = 1000000001;
    while ( left <= right ){
        int middle = (left + right) / 2;
        ll sum = sumOfTrees(trees, N, middle);

        if ( sum == M ){
                return middle;
        }
        else {
            if ( sum > M ){
                left = middle + 1;
            }
            else{
                right = middle - 1;
            }
        }
    }
    return right;
}

int main(){
    long long N, M;
    cin >> N >> M;
    long long *trees = new long long [N + 1];
    for ( long long i = 1; i <= N; i++ ){
        cin >> trees[i];
    }
    cout << binSearch(trees, N, M);
    return 0;
}