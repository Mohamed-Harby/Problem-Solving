/*
*In the name of allah the most gracious and the most merciful
*/

#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define vi vector<int>

using ll = long long;
using namespace std;

void init() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

}

class Solution {
private:
    const int numbers[13] =    {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const string numerals[13] = {"M","CM", "D", "CD", "C","XC", "L", "XL", "X", "IX", "V", "IV", "I"};
public:
    string intToRoman(int num) {
        string res;
        int i = 0;
        while (num) {
            int div = num / numbers[i];
            if (div != 0) {
                for (int y = 0; y < div; ++y) {
                    res.append(numerals[i]);
                }
                num -= numbers[i] * div;
            }
            i++;
        }
        return res;
    }
};

int main() {
    init();
    Solution s;
    for(int i = 1; i < 51; ++i) {
        string res = s.intToRoman(i);
        cout << i << ' '<< res << endl;
    }
}
/*
Output:
1 I
2 II
3 III
4 IV
5 V
6 VI
7 VII
8 VIII
9 IX
10 X
11 XI
12 XII
13 XIII
14 XIV
15 XV
16 XVI
17 XVII
18 XVIII
19 XIX
20 XX
21 XXI
22 XXII
23 XXIII
24 XXIV
25 XXV
26 XXVI
27 XXVII
28 XXVIII
29 XXIX
30 XXX
31 XXXI
32 XXXII
33 XXXIII
34 XXXIV
35 XXXV
36 XXXVI
37 XXXVII
38 XXXVIII
39 XXXIX
40 XL
41 XLI
42 XLII
43 XLIII
44 XLIV
45 XLV
46 XLVI
47 XLVII
48 XLVIII
49 XLIX
50 L
