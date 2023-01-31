#include <iostream>
#include <vector>

using namespace std;

void kiir(vector<int>& v, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (v[i] == 1)
		{
			cout << i + 1 << " ";
		}
	}
	cout << endl;
}

//OLyan mint a descartes szorzatot, csak itt 1-tol 2-ig megyunk m helyett
//Ha v[i] = 1, azt jelenti, hogy az i elemet beletettuk a reszhalmazba
//Ha v[i] = 2, akkor nem tettuk be a reszhalmazba
void reszhalmazok(vector<int>& v, int n, int k)
{
	for (int i = 1; i <= 2; ++i)
	{
		v[k] = i;
		if (k < n - 1)
		{
			reszhalmazok(v, n, k + 1);
		}
		else
		{
			kiir(v, n);
		}
	}
}

void reszhalmazok(int n)
{
	vector<int> v(n);
	reszhalmazok(v, n, 0);
}

int main()
{
	int n;
	cin >> n;
	reszhalmazok(n);
}