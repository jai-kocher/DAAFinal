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

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(vector<int> weights, vector<int> values, int capacity) {
    int n = weights.size();
    vector<vector<int>> ks(n + 1, vector<int>(capacity));
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= capacity; j++) {
            if(i == 0 || j == 0) {
                ks[i][j] = 0;
            }
            else if(weights[i - 1] <= capacity) {
                ks[i][j] = max(values[i - 1] + ks[i - 1][j - weights[i - 1]], ks[i - 1][j]);
            }
            else {
                ks[i][j] = ks[i - 1][j];
            }
        }
    }
    cout << ks;
    return ks[n][capacity];
}

int main() {
    vector<int> weights = {10, 20, 30};//{12, 7, 11, 8, 9};
    vector<int> values = {60, 100, 120};//{24, 13, 23, 15, 16};
    int capacity = 50;
    cout << knapsack(weights, values, capacity) << endl;
}