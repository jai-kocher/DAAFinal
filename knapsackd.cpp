#include <iostream>
#include <vector>
using namespace std;

template <typename S>
ostream& operator <<(ostream& out, vector<S> arr) {
    for(auto i: arr) {
        out << i << " ";
    }
    out << endl;
    return out;
}

template <typename S>
ostream& operator <<(ostream& out, vector<vector<S>> arr) {
    for(auto i: arr) {
        out << i << endl;
    }
    out << endl;
    return out;
}

int knapSackRec(int W, vector<int> wt, vector<int> val, int i, vector<vector<int>>& dp)
{
	if (i < 0)
		return 0;
	if (dp[i][W] != -1)
		return dp[i][W];

	if (wt[i] > W) {
		dp[i][W] = knapSackRec(W, wt, val, i - 1, dp);
		return dp[i][W];
	}
	else {
		dp[i][W] = max(val[i] + knapSackRec(W - wt[i], wt, val, i - 1, dp), knapSackRec(W, wt, val, i - 1, dp));
		return dp[i][W];
	}
}

int knapSack(int W, vector<int> wt, vector<int> val, int n)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
	int ret = knapSackRec(W, wt, val, n - 1, dp);
    cout << dp << endl;
    return ret;
}

int main()
{
	vector<int> val = { 60, 100, 120 };
	vector<int> wt = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(val) / sizeof(val[0]);
	cout << knapSack(W, wt, val, n) << endl;
	return 0;
}
