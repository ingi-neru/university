#include <iostream>
#include <vector>

using namespace std;

int palindrom(string& s, int n)
{
	vector < vector < int > > maxPalindrom(n, vector < int > (n));

	for (int i = 0; i < n; ++i)
	{
		maxPalindrom[i][i] = 1;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			if (s[i] == s[j])
			{
				maxPalindrom[i][j] = 2 + maxPalindrom[i + 1][j - 1];
			}
			else
			{
				maxPalindrom[i][j] = max(maxPalindrom[i + 1][j], maxPalindrom[i][j - 1]);
			}
		}
	}
	return maxPalindrom[n - 1][n - 1];
}

int main()
{
	string s;
	cin >> s;
	int n = s.size();
	cout << palindrom(s, n);
}