#include <iostream>
#include <vector>

using namespace std;

bool sudoku(vector<vector<int>>& negyzetracs, int sor, int oszlop, vector<vector<bool>>& sorok, vector<vector<bool>>& oszlopok, vector<vector<bool>>& negyzetek)
{

	if (sor == 8 && oszlop == 9)
	{
		return true;
	}

	if (oszlop == 9)
	{
		return sudoku(negyzetracs, sor + 1, 0, sorok, oszlopok, negyzetek);
	}

	if (negyzetracs[sor][oszlop] != 0)
	{
		return sudoku(negyzetracs, sor, oszlop + 1, sorok, oszlopok, negyzetek);
	}

	for (int i = 1; i <= 9; ++i)
	{
		if (!sorok[sor][i] && !oszlopok[oszlop][i] && !negyzetek[sor / 3 + oszlop / 3 + 2 * (sor / 3)][i])
		{
			sorok[sor][i] = oszlopok[oszlop][i] = negyzetek[sor / 3 + oszlop / 3 + 2 * (sor / 3)][i] = true;
			negyzetracs[sor][oszlop] = i;
			if (sudoku(negyzetracs, sor, oszlop + 1, sorok, oszlopok, negyzetek))
			{
				return true;
			}
			negyzetracs[sor][oszlop] = 0;
			sorok[sor][i] = oszlopok[oszlop][i] = negyzetek[sor / 3 + oszlop / 3 + 2 * (sor / 3)][i] = false;
		}
	}
	return false;
}

void sudoku(vector<vector<int>>& negyzetracs)
{
	vector<vector<bool>> sorok(9, vector<bool>(10)), oszlopok(9, vector<bool>(10)), negyzetek(9, vector<bool>(10));
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (negyzetracs[i][j] != 0)
			{
				sorok[i][negyzetracs[i][j]] = oszlopok[j][negyzetracs[i][j]] = negyzetek[i / 3 + j / 3 + 2 * (i / 3)][negyzetracs[i][j]] = true;
			}
		}
	}

	sudoku(negyzetracs, 0, 0, sorok, oszlopok, negyzetek);

	cout << endl << endl;

	for (int i = 0; i < 9; ++i)
	{
		if (i % 3 == 0)
		{
			for (int j = 0; j < 18; ++j)
			{
				cout << "_";
			}
			cout << endl;
		}
		for (int j = 0; j < 9; ++j)
		{
			cout << negyzetracs[i][j];
			if ((j + 1) % 3 == 0)
			{
				cout << "|";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}

int main()
{
	vector<vector<int>> negyzetracs(9, vector<int>(9));
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cin >> negyzetracs[i][j];
		}
	}

	sudoku(negyzetracs);
	return 0;
}

/**********
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0
************/