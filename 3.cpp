#include <iostream>
#include <vector>

using namespace std;

bool frogJumpRecursive(vector<int> stones, int last, int current) {
    if(current == stones.size() - 1) {
        return true;
    }
    int lastJump = stones[current] - stones[last];
    int next = current + 1;
    while(next < stones.size() && stones[next] <= stones[current] + lastJump + 1) {
        int nextJump = stones[next] - stones[current];
        int jump = nextJump - lastJump;

        if(jump >= -1 && jump <= 1) {
            if(frogJumpRecursive(stones, current, next)) {
                return true;
            }
        }
        next++;
    }
}

bool frogJump(vector<int> stones) {
    return frogJumpRecursive(stones, 0, 1);
}

int main() {
    vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 18};
    vector<int> stones2 = {0,1,2,3,4,8,9,11};
    cout << frogJump(stones2) << endl;
    return 0;
}