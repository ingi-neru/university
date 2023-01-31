//Laszlo Kazmer 
//512
//Hasonlıtsuk ossze egy ismetlodo ciklus sebesseget amely a beolvasott szam gyokeig megy el, haromfelekeppen implementalva:
//while (i*i <= n)
//sqrt(n)-t segedvaltozoba mentve a ciklus elott  
//while (i <= sqrt(n))
#include<iostream>
#include<ctime>
#include<cmath>
using namespace std;
void negyzetelve ( int n ){
int i=1,db=0;
while ( i * i <= n ){
    db++;
    i++;
}
cout<<db<<endl;
}
void segedvaltozo ( int n ){
    int k=sqrt(n);
    for ( int i=1;i<=k;i++ ){
    
    }
}
void gyokeig ( int n ){
    int i = 1 ;
    while ( i <= sqrt(n) ){
        i++;
    }
} 
int main(){
    int n;
    double timer;
    cin >> n;
    timer=clock();
    negyzetelve(n);
    cerr << ( clock() - timer ) / 1000 << endl;
    timer=clock();
    segedvaltozo(n);
    cerr << ( clock() - timer ) / 1000 << endl;
    timer=clock();
    gyokeig(n);
    cerr << ( clock() - timer ) / 1000;
    return 0;
}