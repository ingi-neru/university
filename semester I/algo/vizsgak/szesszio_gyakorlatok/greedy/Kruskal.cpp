#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct el
{
	int u, v, koltseg;
};

bool kisebb(el a, el b)
{
	return a.koltseg < b.koltseg;
}

void kruskal(vector < el > &elek, int n, int m)
{
	vector < el > feszitofa;
	sort(elek.begin(), elek.end(), kisebb);
	vector<int> komp(n);
	for (int i = 0; i < n; ++i)
	{
		komp[i] = i + 1;
	}

	int i = 0, j = 0;
	while (j < m && i < (n - 2))
	{
		if (komp[elek[j].u - 1] != komp[elek[j].v - 1])
		{
			++i;
			feszitofa.push_back(elek[j]);
			int id = komp[elek[j].v - 1];
			for (int k = 0; k < n; ++k)
			{
				if (komp[k] == id)
				{
					komp[k] = komp[elek[j].u - 1];
				}
			}
		}
		++j;
	}

	cout << endl << endl;
	int suly = 0;
	for (int i = 0; i < feszitofa.size(); ++i)
	{
		cout << feszitofa[i].v << " " << feszitofa[i].u << " " << feszitofa[i].koltseg << endl;
		suly += feszitofa[i].koltseg;
	}

	cout << suly << endl;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector < el > elek(m);
	for (int i = 0; i < m; ++i)
	{
		cin >> elek[i].u >> elek[i].v >> elek[i].koltseg;
	}
	kruskal(elek, n, m);
	return 0;
}