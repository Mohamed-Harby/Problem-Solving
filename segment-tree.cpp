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

const int N = 3e6;
const int MAX = 8388608; // 1 << ((int) ceil(log2(3e6)) + 1);

int interval[MAX + 9];

vector<int> v; // given values --> frequency of the i's element
int st = 0, en = MAX;

int build(int s = st, int e = en, int p = 1) {
    if (s == e)
        return interval[p] = v[s];
    return interval[p] = build(s, (st + en) >> 1, 2 * p) +
                         build(1 + ((st + en) >> 1), en, 2 * p + 1);
}

void insert(int val, int s = st, int e = en, int p = 1) { // O(log(n))
    interval[p]++; // increment each interval contains val
    if (s == e)
        return;
    if (val <= (st + en) >> 1)
        return insert(val, s, (st + en) >> 1, 2 * p);
    return insert(val, (1 + (st + en)) >> 1, e, 2 * p);
}

int order(int val, int s = st, int e = en, int p = 1) { // O(log(n)) // return the order of the last inserted val
    if (s == e)
        return interval[p];
    if (val <= (st + en) >> 1)
        return order(val, s, (st + en) >> 1, 2 * p);
    return interval[2 * p] + order(val, 1 + ((st + en) >> 1), e, 2 * p);
}

int get_kth(int k, int s = st, int e = en, int p = 1) {
    if (s == e)
        return s;
    if (k > interval[2 * p])
        return get_kth(k - interval[2 * p], 1 + ((st + en) >> 1), e, 1 + 2 * p);
    return get_kth(k, s, ((st + en) >> 1), 2 * p);
}

void del_kth(int k, int s = st, int e = en, int p = 1) {
    interval[p]--;
    if (s == e)
        return;
    if (k > interval[2 * p])
        return del_kth(k - interval[2 * p], 1 + ((st + en) >> 1), e, 1 + 2 * p);
    return del_kth(k, s, ((st + en) >> 1), 2 * p);
}

void remove(int val, int s = st, int e = en, int p = 1) { // O(log(n))
    interval[p]--;
    if (s == e)
        return;
    if (val <= (st + en) >> 1)
        return insert(val, s, (st + en) >> 1, 2 * p);
    return insert(val, (1 + (st + en)) >> 1, e, 2 * p);
}

void display(int s = st, int e = en, int p = 1) { // O(log(n))
    if (s == e) {
        int cnt = interval[p];
        while(cnt--)
            cout << s << ' ';
        return;
    }
    display(s, (st + en) >> 1, 2 * p);
    display((1 + (st + en)) >> 1, e, 2 * p);
}

int main() {
    return 0;
}
