#include<iostream>
using namespace std;

int sor[4] = {2, 2, -2, -2};
int oszlop[4] = {2, -2, 2, -2};
int fekete_sor[4] = {1, 1, -1, -1};
int fekete_oszlop[4] = {1, -1, 1, -1};
int kezdo_x, kezdo_y;

int Valid ( int mat[][11], int jelenlegi_x, int jelenlegi_y ){
    return ( jelenlegi_x >= 1 && jelenlegi_y >= 1 && jelenlegi_x <= 10 && jelenlegi_y <= 10 && mat[jelenlegi_x][jelenlegi_y] == 0
    || ( mat[jelenlegi_x][jelenlegi_y] == 2 && jelenlegi_x == kezdo_x && jelenlegi_y == kezdo_y ) );
}

void numOfTakes ( int n, int mat[][11], int index_x, int index_y, int megoldas, int &maxi ){
int t = true;
for ( long i = 0; i < 4; i++ ){
if ( mat[index_x + fekete_sor[i]][index_y + fekete_oszlop[i]] == 1 && Valid(mat, index_x + sor[i], index_y + oszlop[i] )){
mat[index_x][index_y] = 2;
numOfTakes(n, mat, index_x + sor[i], index_y + oszlop[i], megoldas + 1, maxi);
t = false;
}
}
if ( t && maxi < megoldas ) {
    maxi = megoldas;
}
}

void Read ( int &n, int mat[][11], int megoldasok[] ){
    cin >> n;
    for ( int k = 1; k <= n; k++ ){
    
    for ( int i = 1; i <= 10; i++ ){
        for ( int j = 1; j <= 10; j++ ){
        mat[i][j] = 0;
        }
    }
    
    for ( int i = 1; i <= 10; i++ ){
        for ( int j = 1; j <= 10; j++ ){
            char karakter;
            cin >> karakter;
            if ( karakter == 'W' ){
            kezdo_x = i;
            kezdo_y = j;
            }
            else if ( karakter == 'B' ){
            mat[i][j] = 1;
            }
        }
   
    }
    int maxi = 0;
    numOfTakes(n, mat, kezdo_x, kezdo_y, 0, maxi);
    megoldasok[k] = maxi;
    }
}

int main(){
    int mat[11][11] = {false}, megoldasok[101];
    int n;
    Read(n, mat, megoldasok);
    for ( int i = 1; i <= n; i++ ){
        cout << megoldasok[i] << endl;
    }
    return 0;
}