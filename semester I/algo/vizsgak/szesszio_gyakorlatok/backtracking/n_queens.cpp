#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void kiir(vector<int>& v, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (j == v[i])
			{
				cout << "Q";
			}
			else
			{
				cout << ".";
			}
		}
		cout << endl;
	}
	cout << endl;
}


bool nemTamad(vector<int>& v, int k)
{
	bool nem = true;
	int i = 0;
	while (i < k && nem)
	{
		if ((v[i] == v[k]) || ((k - i) == abs(v[k] - v[i])))
		{
			nem = false;
		}
		else
		{
			++i;
		}
	}
	return nem;
}

//A k kiralyno mindig a k-ik sorba fog kerulni
//Megnezzuk, melyik oszlopba tehetjuk ugy, hogy egy kiralynot se tamadjon a sakktablan
//Ket kiralyno, akkor tamadja egymast ha teljesul a kovetkezo feltetelek kozul valamelyik j = k vagy (k - j) = abs(v[k] - v[j]) barmely j = 1, k - 1
//A v[i] azt tartalmazza, hogy az i-ik sorban a kiralyno melyik oszlopba kerult
void kiralynok(vector<int>& v, int n, int k)
{
	for (int i = 0; i < n; ++i)
	{
		v[k] = i;
		if (nemTamad(v, k))
		{
			if (k < n - 1)
			{
				kiralynok(v, n, k + 1);
			}
			else
			{
				kiir(v, n);
			}
		}
	}
}

void kiralynok(int n)
{
	vector<int> v(n);
	kiralynok(v, n, 0);
}

int main()
{
	int n;
	cin >> n;
	kiralynok(n);
	return 0;
}