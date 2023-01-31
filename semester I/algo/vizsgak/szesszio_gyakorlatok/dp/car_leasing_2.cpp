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
	for (int i = 1; i <= n; ++i)
	{
		++num[(a[i].second / mod % 10)];
	}
	for (int i = 1; i <= 9; ++i)
	{
		num[i] += num[i - 1];
	}
	vpii b(n);
	for (int i = n; i >= 1; --i)
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

void leasing ( int n, vpii cars ){
    int max_day[101], previous[101] = {0}, solution = 0;
    max_day[1] = 1;
    for(int i = 1; i <= n; i++){
        max_day[i] = 0;
        for(int j = 1; j < i; j++){
            if ( cars[i].x >= cars[j].y ){
                max_day[i] = max(max_day[i], max_day[j]);
            }
        }
        max_day[i] += cars[i].y - cars[i].x + 1;
        solution = max(solution, max_day[i]);
    }
    cout << solution << endl;
}

void in ( int n, vpii &arr ){
for(int i = 1; i <= n; i++){
    cin >> arr[i].x;
    cin >> arr[i].y;
}
}

int main(){
    int n;
    cin >> n;
    vpii a(n);
    in(n, a);
    sortDecreasing(a, n);
    leasing(n, a);
return 0;
}