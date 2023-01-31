#include <iostream>
#include <vector>

using namespace std;

int minimum(vector < int > &a, int left, int right)
{
	if (left == right)
	{
		return a[left];
	}
	else
	{
		int mid = (left + right) / 2;
		int min1 = minimum(a, left, mid);
		int min2 = minimum(a, mid + 1, right);
		return min(min1, min2);
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

	cout << minimum(a, 0, n - 1);
}