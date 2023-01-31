#include <iostream>
#include <vector>

using namespace std;

struct domino
{
	int e, h;
};

int leghosszabb(vector<domino>& dominok, int n)
{
	vector<vector<int>> sor(n, vector<int>(2));
	sor[0][0] = sor[0][1] = 1;
	int m = 0;
	for (int i = 1; i < n; ++i)
	{
		sor[i][0] = sor[i][1] = 1;
		for (int j = 0; j < i; ++j)
		{
			if (dominok[j].h == dominok[i].e)
			{
				sor[i][0] = max(sor[i][0], sor[j][0] + 1);
			}
			if (dominok[j].e == dominok[i].e)
			{
				sor[i][0] = max(sor[i][0], sor[j][1] + 1);
			}
			if (dominok[j].h == dominok[i].h)
			{
				sor[i][1] = max(sor[i][1], sor[j][0] + 1);
			}
			if (dominok[j].e == dominok[i].h)
			{
				sor[i][1] = max(sor[i][1], sor[j][1] + 1);
			}
		}

		if (sor[i][1] > sor[m][1])
		{
			m = i;
		}

		if (sor[i][0] > sor[m][0])
		{
			m = i;
		}
	}

	return max(sor[m][0], sor[m][1]);
}

int main()
{
	int n;
	cin >> n;
	vector<domino> dominok(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> dominok[i].e >> dominok[i].h;
	}
	cout << leghosszabb(dominok, n);
}