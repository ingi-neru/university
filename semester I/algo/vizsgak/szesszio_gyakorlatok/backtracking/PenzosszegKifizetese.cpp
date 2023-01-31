#include <iostream>
#include <vector>

using namespace std;

void kiir(int darab[], int b[], int eredeti, int n)
{
	cout << eredeti << "=";
	for (int i = 0; i < n - 1; ++i)
	{
		if (darab[i] > 0)
		{
			cout << darab[i] << "*" << b[i] << "+";
		}
	}
	if (darab[n - 1] > 0)
	{
		cout << darab[n - 1] << "*" << b[n - 1] << endl;
	}
}

void penzosszeg(int s, int eredeti, int k, int n, int darab[], int b[])
{
	if (k == n + 1)
	{
		if (s % b[k] == 0)
		{
			darab[k] = s / b[k];
			kiir(darab, b, eredeti, n);
		}
	}
	else
	{
		for (int i = 0; i <= s / b[k]; ++i)
		{
			darab[k] = i;
			int maradt = s - darab[k] * b[k];
			if (maradt == 0)
			{
				kiir(darab, b, eredeti, k + 1);
			}
			else
			{
				penzosszeg(maradt, eredeti, k + 1, n, darab, b);
			}
		}
	}
}

void penzosszeg(int n, int s, int b[])
{
	int *darab = new int[n + 1]; 
	penzosszeg(s, s, 1, n, darab, b);
}
int main()
{
	int s, n;
	cin >> n;
	
	int b[101];
	for ( int i = 1; i <= n; i++ ){
		cin >> b[i];
	}
	cin >> s;
	penzosszeg(n, s, b);
}