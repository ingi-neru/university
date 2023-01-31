#include <iostream>
#include <vector>

using namespace std;

//Ugyanaz, mint az iterativ valtozot, csak sokkal rovidebb, atlathatobb es erthetobb
void descartesRekurziv(vector<int>& i, int n, int m, int k)
{
	if (k == n)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << i[j] << " ";
		}
		cout << endl;
	}
	else
	{
		for (int j = 1; j <= m; ++j)
		{
			i[k] = j;
			descartesRekurziv(i, n, m, k + 1);
		}
	}
}

void descartesRekurziv(int n, int m)
{
	vector<int> i(n);
	descartesRekurziv(i, n, m, 0);
}

int main()
{
	int n, m;
	cin >> n >> m;
	descartesRekurziv(n, m);
}