#include<iostream>
#include<climits>
using namespace std;

void beszurorendezes_hossz ( int n, string tomb[] ){
    for ( int j = 2; j <= n; j++ ){
    string seged = tomb[j];
    int i = j - 1;
    while ( i > 0 && tomb[i].length() < seged.length() ){
        tomb[i + 1] = tomb[i];
        i--;
    }
    tomb[i + 1] = seged;
    }
}

void beszurorendezes_lexgrafikus ( int n, string tomb[] ){
    for ( int j = 2; j <= n; j++ ){
    string seged = tomb[j];
    int i = j - 1;
    while ( i > 0 && tomb[i] > seged ){
        tomb[i + 1] = tomb[i];
        i--;
    }
    tomb[i + 1] = seged;
    }
}


void kiir ( string megoldasok[], int hossz ){
            cout << hossz << endl;
            for ( int j = 1; j <= hossz; j++ ){
                    cout << megoldasok[j] << endl;
            }
}

bool megoldas( string szavak[], int ered[], int h, int k , bool megvolt[] ){
    int darab = 0;
            for ( int j = 1; j <= k; j++ ){
                if ( ered[j] == 1 ){
                    string l = szavak[j];
                    int l_hossz = l.length();
                    for ( int z = 0; z < l_hossz; z++ ){
                        int index = (int)l[z] - 96;
                        if ( megvolt[index] ) return false;
                        else {
                            megvolt[index] = true;
                            darab++;
                        }
                    }
                }
            }
    if ( darab == 26 ) return true;
    else return false;
}

int megallapitHossz ( int ered[], int k ){
    int db = 0;
    for ( int i = 1; i <= k; i++ ){
        if ( ered[i] == 1 ) db++;
    }
    return db;
}

void Particiok( int n, int ered[], int h, int k, bool megvolt[], string szavak[], int &maxi, string megoldasok[] ){
   
    if ( k > n ){
        for ( int i = 1; i <= 26; i++ ) megvolt[i] = false;
        int hossz = megallapitHossz(ered, k);
        if ( hossz < maxi && hossz != 0 ) {
        if ( megoldas(szavak, ered, h, k, megvolt) ){
                maxi = hossz;
                int z = 1;
                for ( int j = 1; j <= k && z <= hossz; j++ ){
                    if ( ered[j] == 1 ) {
                        megoldasok[z] = szavak[j];
                        z++;
                    }                
                }
            }
        }
    }
    else{
        for ( int i = 1; i <= h + 1; i++ ){
        ered[k] = i;
        Particiok(n, ered, h, k + 1, megvolt, szavak, maxi, megoldasok);
        }
    }
}

int main(){
    int n, ered[201], h = 1, k = 1, maxi = 27;
    bool megvolt[27] = {0};
    string szavak[201], megoldasok[201];
    cin >> n;
    for ( int i = 1; i <= n; i++ ) cin >> szavak[i];
    beszurorendezes_hossz(n, szavak);
    Particiok(n, ered, h, k, megvolt, szavak, maxi, megoldasok);
    beszurorendezes_lexgrafikus(maxi, megoldasok);
    if ( maxi <= 26 ) kiir(megoldasok, maxi);
    else cout << -1;
    return 0;
}