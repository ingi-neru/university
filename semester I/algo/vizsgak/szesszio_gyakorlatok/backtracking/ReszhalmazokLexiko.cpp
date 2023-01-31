#include <iostream>
#include <vector>

using namespace std;

void kiir(vector<int>& v, int n)
{
	for (int i = 1; i <= n; ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

//Felhasznaljuk a particiok feladatot a reszhalmazok feladat megoldasahoz
//Azert, hogy az elemeket novekvo sorrennben kapjuk meg az i - t a v[k - 1] + 1 - tol inditjuk
//Ezert kezdetben a v[0] = 0;
void reszhalmazok(vector<int>& v, int n, int k)
{
	for (int i = v[k - 1] + 1; i <= n; ++i)
	{
		v[k] = i;
		kiir(v, k);
		reszhalmazok(v, n, k + 1);
	}
}

void reszhalmazok(int n)
{
	vector<int> v(n + 1);
	cout << "0" << endl;
	reszhalmazok(v, n, 1);
}
int main()
{
	int n;
	cin >> n;
	reszhalmazok(n);
	return 0;
}