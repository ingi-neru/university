#include<iostream>
using namespace std;

int sor[8] = {2, 1, -1, -2, -2, -1, 1, 2 };
int oszl[8] = {1, 2, 2, 1, -1, -2, -2, -1 };
int kezdo_x, kezdo_y;

void felepit_matrix ( int futar_x, int futar_y, int kezdo_x, int kezdo_y, int n , bool meg[][10] ){
for ( int i = 1; i <= n; i++ ){
    for ( int j = 1; j <= n; j++ ){
        if ( abs(futar_x - i) == abs( futar_y - j) || ( i == kezdo_x && j == kezdo_y ) ) meg[i][j] = false;
        else meg[i][j] = true; 
    }
}
}

bool isValid( int r,int c, int futar_x, int futar_y, int n, bool meg[][10] ){
    return ( r >= 1 && c >= 1 && r <= n && c <= n && abs(futar_x - r) != abs( futar_y - c) && meg[r][c]);
}

void knights_route( int futar_x, int futar_y, int jelenlegi_x, int jelenlegi_y, int n , bool meg[][10], int cel_x, int cel_y, int &megoldas ){
	int move_x, move_y;
	for( int k = 0; k < 8; k++ ){
		move_x = jelenlegi_x + sor[k];
		move_y = jelenlegi_y + oszl[k];
		if( isValid(move_x,move_y, futar_x, futar_y, n, meg) ){
			meg[move_x][move_y]  = false;
            if ( move_x == cel_x && move_y == cel_y ) {
            megoldas++;
            }
            knights_route(futar_x, futar_y, move_x, move_y, n, meg, cel_x, cel_y, megoldas);
            meg[move_x][move_y] = true;
		}
        
	}
}


int main(){
    int futar_x, futar_y, cel_x, cel_y, n, megoldas = 0;
    bool meg[10][10];
    cin >> n >> futar_x >> futar_y >> kezdo_x >> kezdo_y >> cel_x >> cel_y;
    felepit_matrix(futar_x, futar_y, kezdo_x, kezdo_y, n, meg);
    knights_route(futar_x, futar_y, kezdo_x, kezdo_y, n, meg, cel_x, cel_y, megoldas);
    cout << megoldas;
    return 0;
}