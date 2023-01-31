#include <iostream>
#include <vector>

using namespace std;

struct koordinata
{
	int x, y;
};

void labirintus(vector<vector<int>>& a, vector<koordinata>& v, int n, int m, int k, int X, int Y, vector<vector<bool>>& volt)
{
	if (a[X][Y] == 1 && !volt[X][Y])
	{
		volt[X][Y] = true;
		v[k] = { X, Y };
		if (X == 1 || X == n || Y == 1 || Y == m)
		{
			for (int i = 0; i <= k; ++i)
			{
				cout << v[i].x << " " << v[i].y << endl;
			}
			cout << endl;
		}
		labirintus(a, v, n, m, k + 1, X + 1, Y, volt);
		labirintus(a, v, n, m, k + 1, X - 1, Y, volt);
		labirintus(a, v, n, m, k + 1, X, Y + 1, volt);
		labirintus(a, v, n, m, k + 1, X, Y - 1, volt);
		volt[X][Y] = false;
	}
}

void labirintus(vector<vector<int>>& a, vector<koordinata>& v, int n, int m, vector<vector<bool>>& volt)
{
	int X, Y;
	cin >> X >> Y;
	labirintus(a, v, n, m, 0, X, Y, volt);
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n + 2, vector<int>(m + 2));
	vector<vector<bool>> volt(n + 2, vector<bool>(m + 2));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> a[i][j];
		}
	}

	vector<koordinata> v(1000);
	labirintus(a, v, n, m, volt);
	return 0;
}