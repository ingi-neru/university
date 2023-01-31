//Laszlo Kazmer
//512
//5
//Számítsuk ki, adott 𝑛 és 𝑥 értékekre, a következő összeget: 𝑆=1−𝑥^2/2! +𝑥^4/4! −𝑥^6/6! +...+(−1)^𝑛 𝑥^2𝑛/2n!
#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;
clock_t start_time,end_time;
double fact ( int k ){
    double s = 1;
  for ( int i = 2 ; i<= k ; i++ ){
    s *= i;
  }
  return s;
}
int keplet ( int n , int x ){
  int s=1,f;
for( int i = 1 ; i <= n ; i++ ){
    f=2*i;
    if ( i % 2 == 0 ) s += ( pow ( x , 2 * i ) / fact( f ));
    else s-= ( pow ( x , 2 * i ) / fact( f ));
    }
    return s;
}
int main()
{
    double x;
    int n;
    cin>>n>>x;
    cout<<round( keplet ( n , x ) * 100.0 ) / 100.0;
    return 0;
}