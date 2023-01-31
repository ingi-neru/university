#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct targy
{
	int num;
	double value, mass;
};

bool nagyobb(targy a, targy b)
{
	return a.value / a.mass >= b.value / b.mass;
}

void knapsack(vector<targy>& items, int n, double place)
{
	double yield = 0, val[101];
	for (int i = 0; i < n; ++i){
		val[i] = items[i].value;
	}
	sort(items.begin(), items.end(), nagyobb);
	double copy = place;
	vector<double> ratio(n);
	int i = 0;
	while (i < n && copy > 0)
	{
		if (items[i].mass <= copy)
		{
			ratio[items[i].num] = 1;
			copy -= items[i].mass;
		}
		else
		{
			ratio[items[i].num] = copy / items[i].mass;
			copy = 0;
		}
		++i;
	}
	for (int i = 0; i < n; ++i)
	{
		yield += (double)ratio[i] * val[i];
	}
	cout << yield;
}

int main()
{
	int n;
	cin >> n;
	double mass;
	cin >> mass;
	vector<targy> items(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> items[i].mass;
	}

	for (int i = 0; i < n; ++i)
	{
		cin >> items[i].value;
		items[i].num = i;
	}

	knapsack(items, n, mass);
}