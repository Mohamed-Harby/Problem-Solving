// In the name of ALLAH the most Gracious the most Merciful
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lol ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MAX 101
ll fib(int n){
	if(n <= 1)  return n;

	return fib(n-1)+fib(n-2);
}

vector<int>FIB(MAX);

ll fast_fib(int n){
	if(n <= 1) return n;
	if(FIB[n] != 0) return FIB[n];
	FIB[n] = fast_fib(n-1) + fast_fib(n-2);
	return FIB[n];
}

int gcd(int a,int b){
	if(b == 0) return a;
	return gcd(b, a % b);
}
/*
int gcd(int a, int b){
	return b ? gcd(b, a % b) : a; // if b is not zero ==> return gcd, else return a
}
*/

	//O(log(n))
	// 10^16
	//10^8
	//10^4
	//10^2
	//10

//O(n)
// 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10

ll pow(int a,int b){ // O(log(b)) base 2
	if(b == 0) return 1;
	ll res = pow(a,b/2);
	res *= res;
	if(b & 1) res *= a; // in case b is odd and when b = 1;
	return res;
}
// a^1 + a^2 + a^3 + a^4 + a^5 + a^6 + a^7
// a* [a^1 + a^2 + a^3 + a^3 (a^1 + a^2 + a^3)]
// a* [(a^1 + a^2 + a^3)(1 + a^3)]
// a* [(a^1 + a^2 + a^3)(1 + (a^1 + a^2 + a^3) - (a^1 + a^2))]
ll rangeSum(ll a, ll k){
	if(k == 0) return 0;
	if(k & 1) return a * (1 + rangeSum(a, k - 1));
	ll half = rangeSum(a, k/2);

	return half*(1+half- rangeSum(a, (k/2) -1));
}
ll rangeSum_iterative(ll a, ll k){
	ll res = 0;
	for(int i=1;i<=k;i++){
		res+= pow(a, i);
	}
	return res;
}
int bin_gcd(int a, int b) {
	if (!a || !b) return a | b;

	unsigned shift = __builtin_ctz(a | b);
	a >>= __builtin_ctz(a);

	do {
		b >>= __builtin_ctz(b);

		if (a > b) swap(a, b);
		b -= a;
	}while (b);

	return a << shift;
}

ll lcm(int a,int b){
	ll res = a * b / gcd(a,b);
	return res;
}


















