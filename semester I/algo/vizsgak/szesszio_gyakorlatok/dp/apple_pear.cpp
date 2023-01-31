#include <iostream>
#include <vector>

using namespace std;

struct gyumolcs
{
	int a, k;
};

int almakKortek(vector<gyumolcs>& gy, int n)
{
	vector<vector<int>> legjobb(n, vector<int>(2, INT32_MAX));
	legjobb[0][0] = gy[0].a;
	legjobb[0][1] = gy[0].k;
	int m = 0;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			int osszeg = 0;
			if (j > 0)
			{
				osszeg += legjobb[j - 1][1];
			}
			int k = j;
			while (k <= i && ((i - k + 1) * gy[k].a + osszeg) < legjobb[i][0])
			{
				osszeg += ((i - k + 1) * gy[k].a);
				++k;
			}

			if (k > i && osszeg < legjobb[i][0])
			{
				legjobb[i][0] = osszeg;
			}
		}

		for (int j = 0; j <= i; ++j)
		{
			int osszeg = 0;
			if (j > 0)
			{
				osszeg += legjobb[j - 1][0];
			}
			int k = j;
			while (k <= i && ((i - k + 1) * gy[k].k + osszeg) < legjobb[i][1])
			{
				osszeg += ((i - k + 1) * gy[k].k);
				++k;
			}

			if (k > i && osszeg < legjobb[i][1])
			{
				legjobb[i][1] = osszeg;
			}
		}
	}

	return min(legjobb[n - 1][0], legjobb[n - 1][1]);
}

int main()
{
	int n;
	cin >> n;
	vector<gyumolcs> gy(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> gy[i].a;
	}

	for (int i = 0; i < n; ++i)
	{
		cin >> gy[i].k;
	}
	cout << almakKortek(gy, n);
}