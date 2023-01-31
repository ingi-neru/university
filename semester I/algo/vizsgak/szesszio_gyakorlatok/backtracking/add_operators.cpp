// Given a string num that contains only digits and an integer target,
// return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num 
// so that the resultant expression evaluates to the target value.

// Note that operands in the returned expressions should not contain leading zeros.
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

void input_and_arrange_in_array ( vi &nums, int &n, ll &target ){
    string input;
    cin >> input;
    cin >> target;
    n = input.length() - 1;
    for ( i, 0, n){
        nums.pb(int(input[i]) - 48);
    }
}

void addOperators ( int k, vi nums, int n, ll target, int solutions[], ll current ){
    if ( k == n ){
        if ( current == target ){
        for(i, 0, n - 1){
            cout << nums[i];
            if ( solutions[i] == 0 ){
                cout << "+";
            }
            if ( solutions[i] == 1 ){
                cout << "-";
            }
            if ( solutions[i] == 2 ){
                cout << "*";
            }
        }
        cout << nums[n] << endl;
        }
        else{
            return;
        }
    }
    else{
                solutions[k] = 0;
                current += nums[k + 1];
                addOperators(k + 1, nums, n, target, solutions, current);
                current -= nums[k + 1];
                solutions[k] = 1;
                current -= nums[k + 1];
                addOperators(k + 1, nums, n, target, solutions, current);
                current += nums[k + 1];
                solutions[k] = 2;
                current *= nums[k + 1];
                addOperators(k + 1, nums, n, target, solutions, current);
                current /= nums[k + 1];
    }
}

int main(){
    vi nums;
    int n, solutions[11];
    ll target, current;
    input_and_arrange_in_array(nums, n, target);
    addOperators(0, nums, n, target, solutions, nums[0]);
return 0;
}