
/*
  بـسـم اللـه الرحـمـن الرحيـم
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,n,k;
	cin >> t;
	string s;
	for(int f = 0; f < t; f++){
		cin >> n >> k >> s;
		int cnt = 0;
		int m = n/2;
		for(int i=1;i<m+1;i++){
			if(s[i-1] != s[n-i]){
				cnt++;
			}
		}
		if(n != 1)
			cout << "Case #" << f+1<< ": " << abs(k-cnt) << '\n';
		else cout << "Case #" << f+1<< ": " << 0 << '\n';
	}

}
