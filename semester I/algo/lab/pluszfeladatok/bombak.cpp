#include<iostream>
#include<string>
#include<fstream>
using namespace std;
ifstream f ("bombak.be");
void be ( unsigned long n, unsigned long m, string s[][101] ){
    for ( int i = 1; i <= n; i++ ){
        for ( int j = 1; j <= m; j++ ){
            f >> s[i][j];
        }
    }
}

bool ellenoriz_felrobban ( unsigned long n, unsigned long m, string s[][101] ){
for ( int i = 1; i <= n; i++ ){
    for ( int j = 1; j <= n; j++ ){
        if ( s[i][j] != "1" ) return false;
    }
}
return true;
} 

void felrobbantplusz ( unsigned long n, unsigned long m, string s[][101], unsigned long i, unsigned long j ){
    if ( i > 1 ) {
        if ( s[i - 1][j] == "+" ) felrobbantplusz(n, m, s, i - 1, j);
        else if ( s[i - 1][j] == "*" ) felrobbantcsillag(n, m, s, i - 1, j);
        else s[i - 1][j] = "1";
    }
    if ( i < n ){
        if ( s[i + 1][j] == "+" ) felrobbantplusz(n, m, s, i + 1, j);
        else if ( s[i + 1][j] == "*" ) felrobbantcsillag(n, m, s, i + 1, j);
        else s[i + 1][j] = "1";
    }
    if ( j < m ){
        if ( s[i][j + 1] == "+" ) felrobbantplusz(n, m, s, i, j + 1);
        else if ( s[i][j + 1] == "*" ) felrobbantcsillag(n, m, s, i, j + 1);
        else s[i][j + 1] = "1";
    }
    if ( j > 1 ){
        if ( s[i][j - 1] == "+" ) felrobbantplusz(n, m, s, i, j - 1);
        else if ( s[i][j - 1] == "*" ) felrobbantcsillag(n, m, s, i, j - 1) ;
        else s[i][j - 1] = "1";
    }
    s[i][j] = "1";
}

void felrobbantcsillag ( unsigned long n, unsigned long m, string s[][101], unsigned long i, unsigned long j ){
    felrobbantplusz(n, m, s, i, j);
     if ( i > 1 && j < m ) {
        if ( s[i - 1][j + 1] == "+" ) felrobbantplusz(n, m, s, i - 1, j + 1);
        else if ( s[i - 1][j + 1] == "*" ) felrobbantcsillag(n, m, s, i - 1, j + 1);
        else s[i - 1][j + 1] = "1";
    }
    if ( i < n && j > 1 ){
        if ( s[i + 1][j - 1] == "+" ) felrobbantplusz(n, m, s, i + 1, j - 1);
        else if ( s[i + 1][j - 1] == "*" ) felrobbantcsillag(n, m, s, i + 1, j - 1);
        else s[i + 1][j - 1] = "1";
    }
    if ( i < n && j < m ){
        if ( s[i][j + 1] == "+" ) felrobbantplusz(n, m, s, i + 1, j + 1);
        else if ( s[i][j + 1] == "*" ) felrobbantcsillag(n, m, s, i + 1, j + 1);
        else s[i + 1][j + 1] = "1";
    }
    if ( i > 1 && j > 1 ){
        if ( s[i - 1][j - 1] == "+" ) felrobbantplusz(n, m, s, i - 1, j - 1);
        else if ( s[i - 1][j - 1] == "*" ) felrobbantcsillag(n, m, s, i - 1, j - 1) ;
        else s[i - 1][j - 1] = "1";
    }
    s[i][j] = "1";
}


void vegig ( unsigned long n, unsigned long m, string s[][101] ){
    unsigned long db = 0;
    bool t = false;
    for ( int i = 1; i <= n && !t; i++ ){
        for ( int j = 1; j <= m && !t ; j++ ){
            if ( s[i][j] == "+" ) {
            felrobbantplusz(n, m, s, i, j);
            db++;
            t = ellenoriz_felrobban(n, m, s);
            }
            if ( s[i][j] == "*" && !t ) {
                felrobbantcsillag(n, m, s, i, j);
                db++;
                t = ellenoriz_felrobban(n, m, s);
            }
        }
    }
    cout << db;
}

int main(){
    string s[101][101];
    unsigned long n, m;
    cin >> n >> m;
    vegig(n, m, s);
    return 0;
}