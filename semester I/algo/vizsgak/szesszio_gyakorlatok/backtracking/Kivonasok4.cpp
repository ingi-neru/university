#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int min(int a, int b)
{
	return a <= b ? a : b;
}

void szamjegyekHalmaza(vector<int>& halmaz, int n)
{
	int masolat = n;
	while (n != 0)
	{
		if (n % 10 > 0)
		{
			halmaz.push_back(n % 10);
		}
		n /= 10;
	}
}

void rendezCsokkenobe(vector<int>& halmaz, int n)
{
	vector<int> darab(10);
	for (int i = 0; i < n; ++i)
	{
		++darab[halmaz[i]];
	}

	for (int i = 8; i >= 1; --i)
	{
		darab[i] += darab[i + 1];
	}

	vector<int> b(n);
	for (int i = n - 1; i >= 0; --i)
	{
		b[darab[halmaz[i]] - 1] = halmaz[i];
		--darab[halmaz[i]];
	}
	halmaz = b;
}

void kivonasok(int n, int& megoldas, int lepesek)
{
	if (lepesek + (n / 9) >= megoldas)
	{
		return;
	}

	if (n == 0)
	{
		megoldas = lepesek;
	}
	else
	{
		vector<int> halmaz;
		szamjegyekHalmaza(halmaz, n);
		rendezCsokkenobe(halmaz, halmaz.size());
		for (int i = 0; i < halmaz.size(); ++i)
		{
			kivonasok(n - halmaz[i], megoldas, lepesek + 1);
		}
	}
}

void kivonasok(int n)
{
	int megoldas = INT32_MAX;
	kivonasok(n, megoldas, 0);
	cout << megoldas << endl;
}

int main()
{
	int n;
	cin >> n;
	kivonasok(n);
	return 0;
}