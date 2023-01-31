// Laszlo Kazmer
// 512
// Lab6/6
// Szeptember 15-én az iskola igazgatója felkéri az első osztályos gyermekeket, hogy forduljanak arccal felé, majd abból a célból, 
// hogy felvezethesse őket az osztálytermekbe, kiadja a parancsot: “Balra át!”.
// A gyermekek bizonytalanok. Van, aki balra fordul, van, aki jobbra. 
// Aki szemben találja magát a mellette állóval, azt hiszi, hogy rosszul fordult és egy időegység alatt egyszer sarkon fordul. 
// Adott egy bizonyos kezdeti konfiguráció, amely a “Balra át!” parancs után alakult ki. 
// Állapítsuk meg, hány időegység alatt „nyugszik meg” a sor.

#include<iostream>
using namespace std;

unsigned long balra ( string input, unsigned long j ){
    long long i = j, index = i;
    char eredeti = input[i];
    if ( i == 0 ) return 0;
    i--;
    while ( i > 0 && eredeti != input[i] ){
    i--;
    }
    return index - i;
}

unsigned long jobbra ( string input, unsigned long j ){
    long long i = j, index = i, hossz = input.length();
    char eredeti = input[i];
    if ( i == hossz - 1 ) return 0;
    i++;
    while ( i < hossz - 1 && eredeti != input[i] ){
    i++;
    }
    return i - index;
}

void rendezJobbBal ( string &input, unsigned long i, unsigned long &turns ){
    unsigned long hossz = input.length();
    bool nyugodt = false;
    while ( !nyugodt ){
    unsigned long seged = turns;
    long long j;
    for ( long long i = 0; i <= hossz; i++ ){
    j = i;
    if( input[i] == 'j' && input[i + 1] == 'b' ){
    if( balra(input, i + 1) < jobbra(input,i) ){
    while ( input[j] == 'j' && j >= 0 ){
    input[j] = 'b';
    input[j + 1] = 'j';
    j--;
    turns++;
    }
    }
    else{
    j++;
    while ( input[j] == 'b' && j < hossz ){
    input[j] = 'j';
    input[j - 1] = 'b';
    j++;
    turns++;
    }    
    }
    }   

    }
    if ( seged == turns ){
        nyugodt = true;
    }
    else{
        j = 0;
    cout << input << endl;
    }
    }
}

unsigned long numOfTurns ( string input, unsigned long &turns ){
    unsigned long j_darab = 0, b_darab = 0, valtas = 0, hossz = input.length();
for ( unsigned long i = 0; i < hossz; i++ ){
if( input[i] == 'j' ){
    j_darab++;
}
rendezJobbBal(input, i, turns);
}
return min(turns, j_darab);
}
int main(){
    string input;
    unsigned long turns = 0;
    cin >> input;
    cout << numOfTurns(input, turns);
}