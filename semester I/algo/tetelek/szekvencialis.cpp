#include<iostream>
using namespace std;

bool T ( int x ){

}

int szekvencialis1 ( int n, int a[], int hely){
    hely = 0;
    int i = 1;
    while ( hely == 0 && i <= n ){
        if ( T( a[i] ) ) hely = i;
        else i++;
    }
    return hely;
}

int szekvencialis2 ( int n, int a[], int hely ){
int i = 1;
while ( i <= n && !T( a[i] ) ) i++;
if ( i <= n ) hely = i;
else hely = 0;
return hely;
} 
int main(){

    return 0;
}