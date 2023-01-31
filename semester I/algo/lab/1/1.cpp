//László Kázmér
//512
//1
//Hasonlıtsuk  ossze ket egesz tıpusu valtozo cserejenek sebesseget harom kulonbozo modszerrel:
//segedvaltozoval
//osszeadassal es kivonassal
//xor cserevel
#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;
void segedvaltozo( int a, int b ){
    int aux = a;
    a = b;
    b = aux;
    cout << a << " " << b << endl;
}
void osszeadas ( int a, int b ){
    a = a + b;
    b = a - b;
    a = a - b;
}
void xor_csere ( int a, int b ){
a = a ^ b;
b = a ^ b;
a = a ^ b;
}
void be( int &a, int &b ){
    cin>>a>>b;
}
int main(){
    int a,b;
    double timer;
    be(a,b);
    timer = clock();
    segedvaltozo(a,b);
    cerr<<(clock()-timer)/1000<<endl;
    timer = clock();
    osszeadas(a,b);
    cerr<<(clock()-timer)/1000<<endl;
    timer = clock();
    xor_csere(a,b);
    cerr<<(clock()-timer)/1000<<endl;
    return 0;
}