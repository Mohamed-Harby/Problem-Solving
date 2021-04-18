#include <bits/stdc++.h>

#pragma GCC target ("sse4.2")   // to accelerate __builtin_popcount https://codeforces.com/blog/entry/59268?#comment-428632

using namespace std;


void print_bin(int n) {
    string s;
    while (n > 0) {
        s += (n & 1) == 1 ? '1' : '0';  // n % 2 ==> x % (2 ^ n) == x & (2^n - 1)
        n >>= 1;    // divide by 2
    }
    reverse(s.begin(), s.end());
    cout << s;
}

void print_bin_rec(int n) {
    if (!n) return;

    print_bin_rec(n >> 1);  // head recursion
    cout << (n & 1);
}

bool getBit(int num, int index) {
    return (num & (1 << index));
}

int setBit_to_1(int num, int index) {
    return num | (1 << index);     // 110101 or 001000 --> 111101
}

int setBit_to_0(int num, int index) {
    return num & ~(1 << index);    // 110101 and ~000001 --> 110101 and 111110 --> 110100 (~ is for NOT)
}

int flipBit(int num, int index) {
    return num ^ (1 << index);
}

// Exercise: rotate a bit to right. 0000000000000000000011001101110 -> rotate 5 -> 0111000000000000000000000110011
int rotate_right(int num, int val) {
    int temp = num;
    for (int i = 0; i < 31; i++) {
        bool curr = getBit(temp, i);
        if (curr == 1) {
            num = setBit_to_1(num, (i - val & 31)); // (i-val) & 31 ==> (i-val) % 32
        } else
            num = setBit_to_0(num, (i - val & 31)); // (i-val) & 31 ==> (i-val) % 32
    }
    return num;
}

int rotate_left(int num, int val) {
    int temp = num;
    for (int i = 0; i < 31; i++) {
        bool curr = getBit(temp, i);
        if (curr == 1) {
            num = setBit_to_1(num, (i + val & 31)); // (i-val) & 31 ==> (i-val) % 32
        } else
            num = setBit_to_0(num, (i + val & 31)); // (i-val) & 31 ==> (i-val) % 32
    }
    return num;
}


int popcount(int n) {   // __builtin_popcount is faster
    int cnt = 0;
    while (n != 0) {
        n &= n - 1;
        cnt++;
    }
    return cnt;
}

void generate_binary_perm(int length) {
    for (int mask = 0; mask < (1 << length); ++mask) {
        for (int i = length - 1; i >= 0; --i) {
            cout << bool(mask & (1 << i));
        }
        cout << '\n';
    }
}

/*  gray code : is a binary numerical system that makes sure that the absolute diff of popcount between any consecutive is 1
    see https://en.wikipedia.org/wiki/Gray_code


Decimal	    Binary	Gray	Gray Decimal    popcount
   0		 0000	0000		 0				0           0000 ^ 0000 -->	0000
   1		 0001	0001		 1				1           0001 ^ 0000 -->  0001
   2		 0010	0011		 3				2           0010 ^ 0001 -->	0011
   3		 0011	0010		 2				1           0011 ^ 0001 -->	0010
   4		 0100	0110		 6				2
   5		 0101	0111		 7				3
   6		 0110	0101		 5				2
   7		 0111	0100		 4				1
   8		 1000	1100		 12				2
   9		 1001	1101		 13				3
   10		 1010	1111		 15				4
   11		 1011	1110		 14				3
   12		 1100	1010		 10				2
   13		 1101	1011		 11				3
   14		 1110	1001		 9				2
   15		 1111	1000		 8				1           1111 ^ 0111	--> 1000



*/
int getGray(int num) {
    return num ^ (num >> 1);    // the (i)th mask in gray code is the (i)th mask ^ (i)th mask >> 1 in binary code
}

void print_4bit(int n) {
    bitset<4> x(n);
    for (int i = 3; i >= 0; --i) {
        cout << x[i];
    }
}

void generate_gray(int len) {   // see https://en.wikipedia.org/wiki/Gray_code
    cout << "Decimal	    Binary	Gray	Gray Decimal    popcount\n";
    for (int mask = 0; mask < (1 << len); ++mask) {
        cout << "   " << mask << "\t\t ";
        print_4bit(mask);
        cout << "\t";

        int gray = getGray(mask);
        print_4bit(gray);
        cout << "\t\t ";
        cout << gray;
        cout << "\t\t\t\t";
        cout << __builtin_popcount(gray) << '\n';
    }
}


int main() {
    generate_gray(4);
    return 0;
}

