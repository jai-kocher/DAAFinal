#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

long int c = 0;
template <typename S>
ostream& operator <<(ostream& out, vector<S> arr) {
    for(auto i: arr) {
        out << i << " ";
    }
    out << endl;
    return out;
}

long long int fib_1(long int n, vector<long long int>& arr) {
    long long int result;
    c++;
    if(arr[n] != 0) {
        return arr[n];
    }
    if(n == 1 || n == 2) {
        result = 1;
    }
    else  {
        result = fib_1(n - 1, arr) + fib_1(n - 2, arr);
        arr[n] = result;
    }
    return result;
}

long long int fib_2(int n) {
    long long int result;
    c++;
    if(n == 1 || n == 2) {
        result = 1;
    }
    else  {
        result = fib_2(n - 1) + fib_2(n - 2);
    }
    return result;
}

long long int fib_3(long int n) {
    if(n == 1 || n == 2) {
        return 1;
    }
    vector<long long int> arr(n + 1, 0);
    arr[1] = 1;
    arr[2] = 1;
    for(int i = 3; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n];
}



int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "\nIterative\n";
    auto start = high_resolution_clock::now();
    cout << fib_3(n) << endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Time: " << duration.count() << endl;
    cout << "Count: " << c << endl << endl;

    vector<long long int> mem(n + 1, 0);
    c = 0;
    cout << "Dynamic\n";
    start = high_resolution_clock::now();
    cout << fib_1(n, mem) << endl;
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "Time: " << duration.count() << endl;
    cout << "Count: " << c << endl << endl;
}