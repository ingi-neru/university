// Laszlo Kazmer
// 512
// Lab5/5
// Bontsunk fel egy szót minden lehetséges módon palindromszavakra!
#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool Palindrom(string szo, int e, int v, int n)
{
    while ( e < v && e < szo.length() && v >= 0 ){
        if (szo[e] != szo[v])  return false;
        e++;
        v--;
    }
    if ( e == n || v < 0) return false;
    return true;
}

void backtrackSzo(vector<string> &megoldasok, vector<string> &jelenlegi, int k, int n, string szo)
{
    if (k >= n){
        int jel = jelenlegi.size() - 1;
        for ( int j = 0; j <= jel; j++ ) cout << jelenlegi[j] << " ";
        cout << endl;
        return;
    }
    for (int i = k; i < n; i++)
    {
        if (Palindrom(szo, k, i, n)){
            jelenlegi.push_back(szo.substr(k, i - k + 1));
            backtrackSzo(megoldasok, jelenlegi, i+1, n, szo);
            jelenlegi.pop_back();
        }
    }
}

int main()
{
    vector<string> megoldasok;
    vector<string> jelenlegi_particiok;
    string szo;
    cin >> szo;
    int n = szo.length();
    backtrackSzo(megoldasok, jelenlegi_particiok, 0, n, szo);
    return 0;
}