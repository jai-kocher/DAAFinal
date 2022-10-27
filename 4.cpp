#include <iostream>
#include <vector>

using namespace std;

int c = 0;

template <typename S>
ostream& operator <<(ostream& out, vector<S> arr) {
    for(auto i: arr) {
        out << i << "\t";
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

int longestCommonSubsequence(string x, string y, int m, int n, vector<vector<int>>& arr) {
    c++;
    if(m == 0 || n == 0) {
        return 0;
    }
    if(x[m - 1] == y[n - 1]) {
        return arr[m][n] = 1 + longestCommonSubsequence(x, y, m - 1, n - 1, arr);
    }
    if(arr[m][n] != -1) {
        return arr[m][n];
    }
    return arr[m][n] = max(longestCommonSubsequence(x, y, m, n - 1, arr), longestCommonSubsequence(x, y, m - 1, n, arr));
}

int main() {
    string x = "BACDB";
    string y = "BDCB";
    int m = x.length(), n = y.length();
    vector<vector<int>> arr(m + 1, vector<int>(n + 1, -1));
    cout << longestCommonSubsequence(x, y, m, n, arr) << endl;
    cout << c << endl;
    return 0;
}