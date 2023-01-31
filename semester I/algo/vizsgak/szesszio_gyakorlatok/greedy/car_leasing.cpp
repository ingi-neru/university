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


void countSort(vpii &a, int n, int mod)
{
	vector<int> num(10);
	for (int i = 0; i < n; ++i)
	{
		++num[(a[i].second / mod % 10)];
	}
	for (int i = 1; i <= 9; ++i)
	{
		num[i] += num[i - 1];
	}
	vpii b(n);
	for (int i = n - 1; i >= 0; --i)
	{
		b[num[(a[i].second / mod) % 10] - 1] = a[i];
		--num[(a[i].second / mod) % 10];
	}
	a = b;
}

void sortDecreasing(vpii& a, int n)
{
	int mod = 1;
	for (int i = 1; i <= 9; ++i)
	{
		countSort(a, n, mod);
		mod *= 10;
	}
}

void leasing ( int n, vpii cars, vpii &solution ){
    solution.pb(cars[0]);
    for ( int i = 2; i <= n; i++ ){
        if ( solution.back().y < cars[i].x ){
            solution.pb(cars[i]);
        }
    }
}

int main(){
    int n;
    cin >> n;
    vpii cars (n), solution;
    for (int i = 0; i < n; ++i)
	{
		cin >> cars[i].first >> cars[i].second;
	}
    cout << endl;
    sortDecreasing(cars, n);
     for (int i = 0; i < n; ++i)
	{
		cout << cars[i].first << " " << cars[i].second << endl;
	}
    leasing(n, cars, solution);
    cout << endl;

    for(int i = 0; i < solution.size(); i++){
        cout << solution[i].x << " " << solution[i].y << endl;
    }
return 0;
}