#include <iostream>
#include <vector>

using namespace std;

struct koordinata
{
	int x, y;
};

void labirintus(vector<vector<int>>& a, vector<vector<bool>>& volt, vector<koordinata>& v, vector<int>& dx, vector<int>& dy, int n, int m, int x, int y, int k)
{
	for (int i = 0; i < dx.size(); ++i)
	{
		int ujx = x + dx[i];
		int ujy = y + dy[i];
		if (ujx >= 0 && ujx < n && ujy >= 0 && ujy < m)
		{
			if (a[ujx][ujy] == 1 && !volt[ujx][ujy])
			{
				volt[ujx][ujy] = true;
				v[k] = { ujx + 1, ujy + 1 };
				if (ujx == 0 || ujx == n - 1 || ujy == 0 || ujy == m - 1)
				{
					for (int i = 0; i <= k; ++i)
					{
						cout << v[i].x << " " << v[i].y << endl;
					}
					cout << endl;
				}
				labirintus(a, volt, v, dx, dy, n, m, ujx, ujy, k + 1);
				volt[ujx][ujy] = false;
			}
		}
	}
}

void kiir(vector<vector<int>>& eredmeny, int n, int m, int x, int y)
{
	int i = x, j = y;
	while (eredmeny[i][j] != 1)
	{
		cout << i + 1 << " " << j + 1 << endl;
		if (i > 0 && eredmeny[i - 1][j] == eredmeny[i][j] - 1)
		{
			--i;
		}
		else if (i < n - 1 && eredmeny[i + 1][j] == eredmeny[i][j] - 1)
		{
			++i;
		}
		else if (j > 0 && eredmeny[i][j - 1] == eredmeny[i][j] - 1)
		{
			--j;
		}
		else if (j < m - 1 && eredmeny[i][j + 1] == eredmeny[i][j] - 1)
		{
			++j;
		}
	}
	cout << endl;
	//cout << i + 1 << " " << j + 1 << endl << endl;
}

void labirintus2(vector<vector<int>>& a, vector<vector<int>>& eredmeny, vector<int>& dx, vector<int>& dy, int n, int m, int x, int y, int k)
{
	for (int i = 0; i < dx.size(); ++i)
	{
		int ujx = x + dx[i];
		int ujy = y + dy[i];
		if (ujx >= 0 && ujx < n && ujy >= 0 && ujy < m)
		{
			if (a[ujx][ujy] == 1 && eredmeny[ujx][ujy] == 0)
			{
				eredmeny[ujx][ujy] = k;
				if (ujx == 0 || ujx == n - 1 || ujy == 0 || ujy == m - 1)
				{
					kiir(eredmeny, n, m, ujx, ujy);
				}
				labirintus2(a, eredmeny, dx, dy, n, m, ujx, ujy, k + 1);
				eredmeny[ujx][ujy] = 0;
			}
		}
	}
}


void labirintus(vector<vector<int>>& a, int n, int m, int x, int y)
{
	vector<koordinata> v(m * n);
	vector<vector<bool>> volt(n, vector<bool>(m));
	vector<vector<int>> eredmeny(n, vector<int>(m));
	volt[x - 1][y - 1] = true;
	vector<int> dx = { 1, -1, 0, 0 }, dy = { 0, 0, 1, -1 };
	labirintus2(a, eredmeny, dx, dy, n, m, x - 1, y - 1, 0);
}

int main()
{
	int n, m, x, y;
	cin >> n >> m;
	cin >> x >> y;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> a[i][j];
		}
	}
	labirintus(a, n, m, x, y);
}





/*********************



5 5
3 2
1 0 1 1 1
0 1 1 0 1
0 1 1 0 1
1 1 1 1 1
0 0 1 0 0











**********************/