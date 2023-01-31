#include <iostream>
#include <vector>

using namespace std;

int binSearchIt(vector < int > &a, int left, int right, int searched)
{
	int i = left, j = right, mid;
	bool megvan = false;
	while (i <= j && !megvan)
	{
		mid = (i + j) / 2;
		if (a[mid] < searched)
		{
			i = mid + 1;
		}
		else if (a[mid] > searched)
		{
			j = mid - 1;
		}
		else
		{
			megvan = true;
		}
	}
	if (megvan)
	{
		return mid + 1;
	}
	else
	{
		return -1;
	}
}

int main()
{
	int n, searched;
	cin >> n >> searched;
	vector<int>a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	cout << binSearchIt(a, 0, n - 1, searched);
}