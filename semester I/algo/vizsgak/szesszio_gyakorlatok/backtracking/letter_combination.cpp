// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
// Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below.
// Note that 1 does not map to any letters.


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
#define for(i, a, b) for ( int i = (a); i <= (b); ++i )
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

void backtrack_solutions ( string digits, string numbers[], int n, int k, string solution, bool last[] ){
    if ( k == n ){
        cout << char(34) << solution << char(34);
        for (i, 0, n - 1){
        if ( !last[i] ){
            cout << ",";
            i = n + 1;
        }
        }
    }
    else{
        int recent = int(digits[k]) - 48;
        string str_recent = numbers[recent];
        for ( i, 0, numbers[recent].length() - 1){
            solution += str_recent[i];
            if ( i == numbers[recent].length() - 1 ){
                last[k] = true;
            }
            backtrack_solutions(digits, numbers, n, k + 1, solution, last);
            last[k] = false;
            solution.pop_back();
        }
        
    }
}


int main(){
    bool last[101] = {false};
    int k = 0;
    string digits = "", numbers[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    getline(cin, digits);
    cout << "[";
    backtrack_solutions(digits, numbers, digits.length(), k, "", last);
    cout << "]";
return 0;
}