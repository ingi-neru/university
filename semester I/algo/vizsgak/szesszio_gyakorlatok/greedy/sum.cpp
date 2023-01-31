#include <iostream>
#include <vector>

using namespace std;

void sum(vector < int > &v, int n)
{
	int max = v[0];
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		if (v[i] > max)
		{
			max = v[i];
		}
		if (v[i] > 0)
		{
			sum += v[i];
		}
	}
	if (sum == 0)
	{
		cout << max;
	}
	else
	{
		cout << sum;
	}
}

int main()
{
	int n;
	cin >> n;
	vector < int > v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	sum(v, n);
}