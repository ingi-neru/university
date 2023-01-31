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

//Nem tamad fuggveny hozzad a kiralynos feladat idobonyolultsagahoz egy n-szeres szorzot, de megoldhato hatekonyabban is a feladat
//A permmutaciohoz hasonloan itt is hasznalhatunk logikai tombot
//Itt 3 logikai tombre lesz szukseg: az elsore azert, hogy megjegyezzuk melyik oszlopokban van kiralyno
//									 a masodikra, hogy melyik foatlokban
//								     a harmadikra, hogy melyik mellekatlokban
//A oszlop sorszama egyenlo az i-ben levo aktualis ertekkel
//A foatlo sorszama egyenlo n - (k - i) (osszes sor szama - aktualis sor szama + aktualis oszlop szama
//A mellekatlo sorszama egyenlo i + k (aktualis oszlop szama + aktualis sor szama)
void kiralynok(vector<int>& v, vector<bool>& oszlop, vector<bool>& foatlo, vector<bool>& mellekatlo, int n, int k)
{
	for (int i = 0; i < n; ++i)
	{
		v[k] = i;
		if (!oszlop[v[k]] && !foatlo[n - (k - i) - 1] && !mellekatlo[i + k])
		{
			oszlop[v[k]] = foatlo[n - (k - i) - 1] = mellekatlo[i + k] = true;
			if (k < n - 1)
			{
				kiralynok(v, oszlop, foatlo, mellekatlo, n, k + 1);
			}
			else
			{
				kiir(v, n);
			}
			oszlop[v[k]] = foatlo[n - (k - i) - 1] = mellekatlo[i + k] = false;
		}
	}
}

void kiralynok(int n)
{
	vector<int> v(n);
	vector<bool> oszlop(n), foatlo(2 * n - 1), mellekatlo(2 * n - 1);
	kiralynok(v, oszlop, foatlo, mellekatlo, n, 0);
}

int main()
{
	int n;
	cin >> n;
	kiralynok(n);
}