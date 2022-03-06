//		بِسْمِ اللَّـهِ الرَّحْمَـٰنِ الرَّحِيمِ

#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<int> solution(vector<int> &A) {
    sort(A.begin(), A.end());
    map<int, int> freq;
    int n = A.size();
    if (n & 1) // size is odd
        return {};
    for (int i: A) {
        freq[i]++;
    }
    vector<int> x;
    for (int i: A) {
        if (freq[i] == 0)
            continue;
        if (freq[i] <= freq[i * 2]) {
            x.push_back(i);
            freq[i]--, freq[i * 2]--;
        } else {
            return {};
        }
    }
    sort(x.begin(), x.end());
    if (x.size() == n / 2) {
        return x;
    } else {
        return {};
    }
}


bool solution(vector<int> &A, int Y, int Z) {
    int E = A.size() / Y;
    int grid[E][Y];
    int x = 0;
    for (int i =0; i < E; ++i){
        for(int j = 0; j < Y; ++j) {
            grid[i][j] = A[x++];
        }
    }
    int max_mask = 1 << E;
    for (int mask = 1; mask <= max_mask; ++mask) {
        if (__builtin_popcount(mask) != Z)
            continue;

        vector<int> skills(Y);
        for (int sh = 0; sh < 32; ++sh) {
            if (mask & (1 << sh)) {
                for (int i =0; i < Y; ++i) {
                    skills[i] += grid[sh][i];
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < Y; ++i) {
            if (skills[i] > 0) {
                cnt++;
            }
        }
        if (cnt == Y)
            return true;
    }
    return false;
}





int main() {
    vector<int> v = {1, 0, 1, 1, 0, 0, 0, 0, 1};
    int Y = 3, Z = 2;
    cout << solution(v, Y, Z);
    return 0;
}
