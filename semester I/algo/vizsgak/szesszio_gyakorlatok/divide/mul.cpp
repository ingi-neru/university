#include <iostream>
#include <vector>

using namespace std;

int mul(vector < int > &a, int left, int right)
{
	if (left == right)
	{
		return a[left];
	}
	else
	{
		int kozep = (left + right) / 2;
		int sz1 = mul(a, left, kozep);
		int sz2 = mul(a, kozep + 1, right);
		return sz1 * sz2;
	}
}

int main()
{
	int n;
	cin >> n;
	vector < int > a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	cout << mul(a, 0, n - 1);
}