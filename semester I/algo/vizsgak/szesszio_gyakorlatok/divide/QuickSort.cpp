#include <iostream>
#include <vector>

using namespace std;

int felosztHoare(vector<int>& a, int bal, int jobb)
{
	int strazsa = a[bal];
	int i = bal - 1, j = jobb + 1;
	do
	{
		do
		{
			++i;
		} while (a[i] < strazsa);

		do
		{
			--j;
		} while (a[j] > strazsa);

		if (i < j)
		{
			swap(a[i], a[j]);
		}
	} while (i < j);

	return j;
}

int felosztLomuto(vector<int>& a, int bal, int jobb)
{
	int strazsa = a[jobb];
	int i = bal - 1;
	for (int j = bal; j < jobb; ++j)
	{
		if (a[j] <= strazsa)
		{
			++i;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[jobb]);
	return i + 1;
}

void quickSort(vector<int>& a, int bal, int jobb)
{
	if (bal < jobb)
	{
		int m = felosztLomuto(a, bal, jobb);
		quickSort(a, bal, m - 1);
		quickSort(a, m + 1, jobb);
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	quickSort(a, 0, n - 1);
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}