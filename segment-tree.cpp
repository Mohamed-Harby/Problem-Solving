//			بِسْمِ اللَّـهِ الرَّحْمَـٰنِ الرَّحِيم

#include <bits/stdc++.h>

using namespace std;
#define all(v) begin(v), end(v)
#define fast_io                            \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(0);
#define PREC(n) cout << fixed << setprecision(n);
#define eps 1E-10
#define pi 2 * acos(0.0)
#define inf 1.797E308
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define qi queue<int>
#define pii pair<int, int>
#define ss second
#define ff first
#define oo int(1e9);

const int N = 2e6;
const int MAX = 4194304; // 1 << ((int) ceil(log2(N)) + 1);
bool lucky[N + 9];
int intervals[MAX + 9];

vector<int> v; // given values --> frequency of the i's element
int st = 1, en = N;

int build(int s = st, int e = en, int p = 1) {
    if (s == e)
        return intervals[p] = v[s];
    return intervals[p] = build(s, (s + e) >> 1, 2 * p) +
                          build(1 + ((s + e) >> 1), e, 2 * p + 1);
}

void insert(int val, int s = st, int e = en, int p = 1) { // O(log(n))
    intervals[p]++; // increment each interval contains val
    if (s == e)
        return;
    if (val <= (s + e) >> 1)
        return insert(val, s, (s + e) >> 1, 2 * p);
    return insert(val, 1 + ((s + e) >> 1), e, 2 * p + 1);
}

int order(int val, int s = st, int e = en, int p = 1) { // O(log(n)) // return the order of the last inserted val
    if (s == e)
        return intervals[p];
    if (val <= (s + e) >> 1)
        return order(val, s, (s + e) >> 1, 2 * p);
    return intervals[2 * p] + order(val, 1 + ((s + e) >> 1), e, 2 * p);
}

int get_kth(int k, int s = st, int e = en, int p = 1) {
    if (s == e)
        return s;
    if (k <= intervals[2 * p])
        return get_kth(k, s, ((s + e) >> 1), 2 * p);
    return get_kth(k - intervals[2 * p], 1 + ((s + e) >> 1), e, 2 * p + 1);
}

void del_kth(int k, int s = st, int e = en, int p = 1) {
    intervals[p]--;
    if (s == e)
        return;
    if (k <= intervals[2 * p]) {
        return del_kth(k, s, ((s + e) >> 1), 2 * p);
    }
    return del_kth(k - intervals[2 * p], 1 + ((s + e) >> 1), e, 1 + (2 * p));
}

void remove(int val, int s = st, int e = en, int p = 1) { // O(log(n))
    intervals[p]--;
    if (s == e)
        return;
    if (val <= (s + e) >> 1)
        return insert(val, s, (s + e) >> 1, 2 * p);
    return insert(val, (1 + (s + e)) >> 1, e, 2 * p);
}

void display(int s = st, int e = en, int p = 1) { // O(log(n))
    if (s == e) {
        int cnt = intervals[p];
        while (cnt--)
            cout << s << ' ';
        return;
    }
    display(s, (s + e) >> 1, 2 * p);
    display(1 + ((s + e) >> 1), e, 2 * p + 1);
}

//int cnt_range(int l, int r, int s = st, int e = en, int p = 1) {
//    if (s >= l && e <= r) // interval is contained
//        return intervals[p];
//    else if (l >= s) {
//        return cnt_range(l, e,s,e, )
//    }
//}

int main() {
//    freopen("out.txt", "w", stdout);
    return 0;
}
