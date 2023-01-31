// Laszlo Kazmer
// 512
// Lab6/7
// Legyen két számsorozat 𝐴 = [𝑎1,𝑎2,...,𝑎𝑚] és 𝐵 = [𝑏1,𝑏2,...,𝑏𝑛]. 
//Válasszuk ki a 𝐵 sorozatból azon 𝑋 = [𝑥1, 𝑥2, . . . , 𝑥𝑚] elemeket,
// amelynek megfelelően az 𝐸 = 𝑎1𝑥1 + 𝑎2𝑥2 + . . . + 𝑎𝑚𝑥𝑚 kifejezés értéke a lehető legnagyobb.
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

void beszurorendezes ( long long n, long long tomb[] ){
    for ( long long j = 2; j <= n; j++ ){
    long long seged = tomb[j], i = j - 1;
    while ( i > 0 && tomb[i] < seged ){
        tomb[i + 1] = tomb[i];
        i--;
    }
    tomb[i + 1] = seged;
    }
}

void be( long long &n, long long &m, long long A[], long long B[] ){
    cin >> m;
    for ( long long i = 1; i <= m; i++ ){
        cin >> A[i];
    }
    cin >> n;
    for ( long long i = 1; i <= n; i++ ){
        cin >> B[i];
    }
}

string str_osszeg(string eredmeny, string reszeredmeny)
{
    if(eredmeny.size() < reszeredmeny.size())
        swap(eredmeny, reszeredmeny);

    int j = eredmeny.size()-1;
    for(int i=reszeredmeny.size()-1; i>=0; i--, j--)
        eredmeny[j]+=(reszeredmeny[i]-'0');

    for(int i=eredmeny.size()-1; i>0; i--)
    {
        if(eredmeny[i] > '9')
        {
            int d = eredmeny[i]-'0';
            eredmeny[i-1] = ((eredmeny[i-1]-'0') + d/10) + '0';
            eredmeny[i] = (d%10)+'0';
        }
    }
    if(eredmeny[0] > '9')
    {
        string k;
        k+=eredmeny[0];
        eredmeny[0] = ((eredmeny[0]-'0')%10)+'0';
        k[0] = ((k[0]-'0')/10)+'0';
        eredmeny = k+eredmeny;
    }
    return eredmeny;
}

string str_kivonas(string eredmeny, string reszeredmeny)
{
    if(eredmeny.size() < reszeredmeny.size())
        swap(eredmeny, reszeredmeny);

    int j = eredmeny.size()-1;
    for(int i=reszeredmeny.size()-1; i>=0; i--, j--)
        eredmeny[j]+=(reszeredmeny[i]-'0');

    for(int i=eredmeny.size()-1; i>0; i--)
    {
        if(eredmeny[i] > '9')
        {
            int d = eredmeny[i]-'0';
            eredmeny[i-1] = ((eredmeny[i-1]-'0') + d/10) + '0';
            eredmeny[i] = (d%10)+'0';
        }
    }
    if(eredmeny[0] > '9')
    {
        string k;
        k+=eredmeny[0];
        eredmeny[0] = ((eredmeny[0]-'0')%10)+'0';
        k[0] = ((k[0]-'0')/10)+'0';
        eredmeny = k+eredmeny;
    }
    return eredmeny;
}

void kiszamolMaximum( long long n, long long m, long long A[], long long B[], string &eredmeny ){
long long hossz = 0, ut_A = m, ut_B = n, reszeredmeny;
while ( A[ut_A] <= 0 && B[ut_B] <= 0 ){
    hossz++;
    reszeredmeny = A[ut_A] * B[ut_B];
    stringstream convert;
    convert << reszeredmeny;
    string str_reszeredmeny = convert.str();
    eredmeny = str_osszeg(eredmeny, str_reszeredmeny);
    ut_A--;
    ut_B--;
}
for ( long long i = 1; i <= m - hossz; i++ ) {
    reszeredmeny = A[i] * B[i];
    stringstream convert;
    convert << reszeredmeny;
    string str_reszeredmeny = convert.str();
    eredmeny = str_osszeg(eredmeny, str_reszeredmeny);

}
    cout << eredmeny;
}

int main(){
    long long n, m, A[10001], B[10001];
    string eredmeny = "0";
    be(n, m, A, B);
    beszurorendezes(m, A);
    beszurorendezes(n, B);
    kiszamolMaximum(n, m, A, B, eredmeny);
    return 0;
}