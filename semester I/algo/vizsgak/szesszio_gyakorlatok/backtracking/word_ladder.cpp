// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. 
// Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <bitset>
#include <stack>
#include <list>

#include <numeric>
#include <algorithm>
#include <random>
#include <chrono>

#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <climits>

#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>

using namespace std;

#define ull unsigned long long
#define ll long long
#define pii pair <int, int>
#define pll pair <long, long>
#define vb vector <bool>
#define vi vector <int>
#define vll vector <ll>
#define vd vector <double>
#define vs vector <string>
#define vpii vector < pair<int, int> >
#define vvi vector <vi>
#define vvb vector <vb>
#define si set <int>
#define usi unordered_set <int>
#define mii map <int, int>
#define umii unordered_map <int, int>
#define ms multiset
#define us unordered_set
#define um unordered_map
#define ums unordered_multiset
#define umm unordered_multimap

#define forn(i, n) for( int i = 0; i < (n); ++i )
// #define for(i, a, b) for ( int i = (a); i <= (b); ++i )
#define ford for( int i = (a); i>= (b); --i )

#define sz size()
#define bg begin()
#define en end()
#define cl clear()
#define x first
#define y second
#define rs resize
#define pb push_back
#define all(x) x.begin(), x.end()
#define ins insert
#define er erase
#define cnt count

void tokenize(string const &str, const char delim, vector<string> &out)
{
    stringstream ss(str);
 
    string s;
    while (getline(ss, s, delim)) {
        out.push_back(s);
    }
}

void input( vs &wordList, int &n, bool &possible, int len, string endWord ){
    bool findEndWord = false;
    string soundsOfTheForest;
    getline(cin, soundsOfTheForest);

    const char delim = ' ';

    vector<string> out;
    tokenize(soundsOfTheForest, delim, out);
    for (auto &s: out) {
        wordList.pb(s);
        if ( wordList.back().length() - 1 != len  ){
            possible = false;
        }
        if ( wordList.back() == endWord ){
            findEndWord = true;
        }
        n++;
    }
    if ( n != 1 ) n--;
    if ( !findEndWord ){
        possible = false;
    }
}

bool continuation ( string recent, string last ){
        int num = 0;
    for ( int i = 0; i < last.length(); i++ ){
        if ( recent[i] != last[i] ){
            num++;
        }
        if ( num > 1 ) return 0;
    }
    if ( num == 0 ) return 0;
    else return 1;
}

void backtrack_ladders ( int k, string solutions[], vs wordList, string beginWord, string endWord, bool was[], string final[], int &final_size, int &recent ){
    if ( solutions[k - 1] == endWord ){
        if ( final_size > k ){
            final_size = k;
            recent = 1;
            final[recent] = solutions[0];
        for(int i = 1; i <= k - 1; i++ ){
            final[recent] += " " + solutions[i];
        }
        }
        else if ( final_size == k ){
            recent++;
            final[recent] = solutions[0];
            for(int i = 1; i <= k - 1; i++ ){
            final[recent] += " " + solutions[i];
        }
        }
    }
    else{
        bool found = false;
        for ( int i = 0; i <= wordList.size(); i++ ){
            if ( !was[i] && continuation(wordList[i], solutions[k - 1]) ){
                found = true;
                solutions[k] = wordList[i];
                was[i] = true;
                backtrack_ladders(k + 1, solutions, wordList, beginWord, endWord, was, final, final_size, recent);
                was[i] = false;
            }
        }
        if ( !found || k > final_size ){
            return;
        }
    }
}


int main(){
    int n = 0, len, final_size = INT_MAX, recent = 0;
    bool possible = true, was[101] = {false};
    string beginWord, endWord, solutions[101], final[101];
    cin >> beginWord;
    len = beginWord.length() - 1;
    cin.ignore();
    getline(cin, endWord);
    vs wordList;
    input(wordList, n, possible, len, endWord);
    solutions[0] = beginWord;
    if ( endWord.length() - 1 != len || !possible ){
        cout << "not possible";
    }
    else{
        backtrack_ladders(1, solutions, wordList, beginWord, endWord, was, final, final_size, recent);
        for ( int i = 1; i <= recent; i++ ){
            cout << final[i] << endl;
        }
    }
return 0;
}