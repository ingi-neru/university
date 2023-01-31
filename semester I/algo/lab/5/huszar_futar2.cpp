// Laszlo Kazmer
// 512
// Lab5/6
// Egy 𝑛 × 𝑛 méretű sakktáblán az (𝑥, 𝑦) pozíción található egy futár és az (𝑥0, 𝑦0) pozíción egy ló.
// A lónak el kell jutnia erről a helyről az (𝑥1, 𝑦1) pozícióra, anélkül, hogy egy bizonyos négyzetre többször lépne illetve, hogy olyan helyen
// állna meg, ahonnan a futár kiütheti. Írjuk ki, hogy hányféleképpen lehetséges ez!
#include <iostream>
using namespace std;
int N, mat[8][8];
int row[8] = {2, 1, -1, -2, -2, -1, 1, 2 };
int col[8] = {1, 2, 2, 1, -1, -2, -2, -1 };
bool isValid( int r,int c, int futar_x, int futar_y ){
    return ( r >= 1 && c >= 1 && r <= N && c <= N && !( r == futar_x || c == futar_y || ( abs(futar_x - r) == abs( futar_y - c)) ) && (r >= 1 && c >= 1 && r <= N && c <= N && mat[r][c] == -1) );
}

void kiiras(){
    	for(int i = 1;i <= N;i++)
			{
			for(int j = 1;j <= N;j++)
				cout<<mat[i][j]<<"  ";
			cout<<endl;
		}
}
void knight_tour(int futar_x, int futar_y, int r,int c,  int move, int &megoldas, int cel_x, int cel_y){
	int move_x, move_y;
	for( int k = 0; k < 8; k++ ){
		move_x = r + row[k];
		move_y = c + col[k];
		if( isValid(move_x,move_y, futar_x, futar_y) ){
			mat[move_x][move_y] = move + 1;
			kiiras();
            cout <<endl << endl;
            if ( move_x == cel_x && move_y == cel_y ) {
            megoldas++;
            }
            knight_tour(futar_x, futar_y,move_x,move_y,move + 1, megoldas, cel_x, cel_y);
		}
		else mat[move_x][move_y] = -1;
	}
}

int main() {
    int megoldas = 0, futar_x, futar_y, kezdo_x, kezdo_y, cel_x, cel_y;
    cin >> N >> futar_x >> futar_y >> kezdo_x >> kezdo_y >> cel_x >> cel_y;
	memset(mat,-1,sizeof(mat));
	mat[kezdo_x][kezdo_y] = 1;
    knight_tour(futar_x, futar_y, kezdo_x,kezdo_y,1, megoldas, cel_x, cel_y);
	cout << megoldas;
	return 0;
}