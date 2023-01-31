#include <iostream>
#include <vector>

using namespace std;

//A naiv megoldas altalanositott verzioja
//A naiv algoritmus egymasba agyazott for ciklusokkal oldotta meg a feladatot
//Ezzal az a baj, hogy minden n lehetseges ertekre n darab egymasba agyazott ciklusra lenne szukseg
//Ennek kikuszobolesere felhasznalunk egy i tombot, amiben a ciklusvaltozokat taroljuk, illetve egy k szamot, amely azt mutatja, hogy mennyi az eppen aktualis ciklus sorszama
void descartesIterativ(int n, int m)
{
	vector<int> i(n);
	int k = 0;
	while (k >= 0)
	{
		if (k == n)
		{
			for (int j = 0; j < n; ++j)
			{
				cout << i[j] << " ";
			}
			cout << endl;
			--k;
		}
		else if (i[k] < m)
		{
			i[k] += 1;
			++k;
		}
		else
		{
			i[k] = 0;
			--k;
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	descartesIterativ(n, m);
}