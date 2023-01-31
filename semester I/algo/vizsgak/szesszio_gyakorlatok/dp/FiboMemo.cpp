#include <iostream>
#include <vector>

using namespace std;

int fiboMemo(vector<int>& dp, int n)
{

	if (dp[n] != -1)
	{
		return dp[n];
	}

	dp[n] = fiboMemo(dp, n - 1) + fiboMemo(dp, n - 2);
	return dp[n];
}

int main()
{
	int n;
	cin >> n;
	vector<int> dp(n + 1, -1);
	dp[0] = 0, dp[1] = 1;
	cout << fiboMemo(dp, n) << endl;
}

