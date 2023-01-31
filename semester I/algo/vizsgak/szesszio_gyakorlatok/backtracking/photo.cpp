#include <iostream>
#include <vector>

using namespace std;

void fill(vector<vector<int>>& a, vector<int>& dx, vector<int>& dy, int x, int y, int& meret)
{
	if (a[x][y] != 1)
	{
		return;
	}
	a[x][y] = 2;
	++meret;
	for (int i = 0; i < dx.size(); ++i)
	{
		fill(a, dx, dy, x + dx[i], y + dy[i], meret);
	}
}

void fenykep(vector < vector < int > > &a, int m, int n)
{
	vector < int > dx = {0, -1, -1, -1, 0, 1, 1, 1};
	vector < int > dy = {-1, -1, 0, 1, 1, 1, 0, -1};
	int meret;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (a[i][j] == 1)
			{
				meret = 0;
				fill(a, dx, dy, i, j, meret);
				cout << i << " " << j << " " << meret << endl;
			}
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector < vector < int > > a(n + 2, vector < int > (m + 2));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> a[i][j];
		}
	}
	fenykep(a, m, n);
}