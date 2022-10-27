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

int travellingSalesmanProblem(vector<vector<int>> graph, int s)
{
	vector<int> vertices;
	for (int i = 0; i < 4; i++) {
        if (i != s) {
            vertices.push_back(i);
        }
    }

	int min_path = INT_MAX;
	do {
		int current_pathweight = 0;
		int k = s;
		for (int i = 0; i < vertices.size(); i++) {
			current_pathweight += graph[k][vertices[i]];
            cout << k << " " << vertices[i] << endl;
			k = vertices[i];
		}
		current_pathweight += graph[k][s];
		min_path = min(min_path, current_pathweight);

	} while(next_permutation(vertices.begin(), vertices.end()));

	return min_path;
}

int main()
{

	vector<vector<int>> graph = {{0, 10, 15, 20},
					             {10, 0, 35, 25},
					             {15, 35, 0, 30},
					             {20, 25, 30, 0}};

	int s = 0;
	cout << travellingSalesmanProblem(graph, s) << endl;
	return 0;
}
