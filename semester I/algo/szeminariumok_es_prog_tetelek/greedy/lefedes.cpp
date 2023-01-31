#include<iostream>
using namespace std;

pair <long long, long long> indexes[100001];

void be ( long long &n, long long &m, long long kezd[], long long veg[]){
    cin >> m;
    long long i = 1;
    bool t = true;
    while( t ){
        cin >> kezd[i] >> veg[i];
        indexes[i + 1].first = kezd[i];
        indexes[i + 1].second = veg[i];
        if ( kezd[i] == 0 && veg[i] == 0 ) t = false;
        i++;
    }   
    n = i - 1;
    sort(indexes + 1, indexes + n + 1);
    for ( long i = 1; i <= n; i++ ){
        kezd[i] = indexes[i].first, veg[i] = indexes[i].second;
    }
}



void lefed ( long long n, long long m, long long kezd[], long long veg[] ){
    long long eleje = 0, vege = m, megoldas[3][100001] = {0}, hossz = 1, maxi = 0;
    bool nemVeg = true;
    for ( long long i = 1; i <= n && nemVeg; i++ ){
        if ( kezd[i] > eleje ){
        eleje = megoldas[2][hossz];
        hossz++;
        maxi = 0;
        }
        if ( veg[i] - eleje >= maxi && kezd[i] <= eleje ){
            maxi = veg[i] - eleje;
            megoldas[1][hossz] = kezd[i];
            megoldas[2][hossz] = veg[i];
            if ( veg[i] >= m ) nemVeg = false;
        }
    }
    if ( megoldas[2][hossz] < m ) cout << "No solution";
    else{
        cout << hossz << endl;
        for ( long long i = 1; i <= hossz; i++ ){
            cout << megoldas[1][i] << " " << megoldas[2][i] << endl;
        }
    }
}

int main(){
    long long n, m, kezd[100001], veg[100001];

    be(n, m, kezd, veg);
    lefed(n, m, kezd, veg);
    return 0;
}