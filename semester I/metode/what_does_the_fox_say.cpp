#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void tokenize(string const &str, const char delim, vector<string> &out)
{
    stringstream ss(str);
 
    string s;
    while (getline(ss, s, delim)) {
        out.push_back(s);
    }
}

void searching ( string sounds[], string imitation, bool fox[], long n ){
    for ( long i = 1; i <= n; i++ ){
        if ( imitation == sounds[i] ) {
            fox[i] = false;
        }
    }
}

void whatDoesTheFoxSay ( string sounds[], long n ){
    bool t = true, fox[1001];
    for ( long i = 1; i <= n; i++ ){
        fox[i] = true;
    }

    string animal, imitation;
    while ( t ){
        getline(cin, animal);
        if ( animal == "what does the fox say?" ){
            t = false;
        }
        else{
        const char delim = ' ';
 
        vector<string> out;
        tokenize(animal, delim, out);
 
        for (auto &s: out) {
            imitation = s;
        }
        searching(sounds, imitation, fox, n);
        }

    }
        for ( long i = 1; i <= n; i++ ){
        if ( fox[i] ) {
            cout << sounds[i] << " ";
        }
     
    }
    cout << endl;
  
}

void input( string sounds[], long &n, long i ){
    string soundsOfTheForest;
    getline(cin, soundsOfTheForest);

    const char delim = ' ';
 
    vector<string> out;
    tokenize(soundsOfTheForest, delim, out);
    for (auto &s: out) {
        sounds[n] = s;
        n++;
    }
    if ( n != 1 ) n--;
}

int main(){
    string sounds[101];
    long n, cases;
    cin >> cases;
    cin.ignore();
    for ( long i = 1; i <= cases; i++ ){
    n = 1;
    input(sounds, n, i);
    whatDoesTheFoxSay(sounds, n);
    }
    return 0;
}