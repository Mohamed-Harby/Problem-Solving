//		بِسْمِ اللَّـهِ الرَّحْمَـٰنِ الرَّحِيمِ

#include <bits/stdc++.h>

using namespace std;
#define ll long long

int s, n;
vector<pair<int, int>> items;

int dp[1000][100];

int solve(int c, int i) { // recursive dp
    if (c == 0 or i == n)
        return 0;

    int &curr_max = dp[c][i];
    if (curr_max != -1)
        return curr_max;

    if (c >= items[i].first) {
        curr_max = max(curr_max, solve(c - items[i].first, i + 1) + items[i].second);
    }
    curr_max = max(curr_max, solve(c, i + 1));
    return curr_max;
}

int main() {
    cin >> n >> s;
    items = vector<pair<int, int>>(n);
    for (int i = 0; i < n; ++i) {
        cin >> items[i].second >> items[i].first;
    }
    //----------- iterative dp ----------//
    int dp[s + 1][n];
    memset(dp, 0, sizeof dp);

    int curr_weight, curr_price;
    for (int i = 0; i < n; ++i) { // remaining = 0
        if (items[i].first == s)
            dp[0][i] = items[i].second;
    }

    if (s > items[0].first) {
        dp[s - items[0].first][0] = items[0].second; // on choosing the first -> dp[rem] = price
    }
    for (int c = s; c >= 1; c--) {
        for (int i = 1; i < n; ++i) {
            curr_weight = items[i].first;
            curr_price = items[i].second;
            if (c + curr_weight <= s) {
                dp[c][i] = max(dp[c][i - 1], dp[c + curr_weight][i - 1] + curr_price);
            } else {
                dp[c][i] = dp[c][i - 1];
            }
        }
    }
    int res = 0;
    for (int c = 0; c <= s; ++c) {
        for (int i = 0; i < n; ++i) {
            res = max(res, dp[c][i]);
        }
    }
    cout << res << '\n';
}
/*
4 5
1 8
2 4
3 0
2 5
2 3

13
 */
