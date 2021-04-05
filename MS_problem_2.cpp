// In the name of ALLAH the most Gracious the most Merciful

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lol ios_base::sync_with_stdio(0);cin.tie(0);
#define all(v) v.begin(), v.end()
#define vi vector<int>

string solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    /*
    Count number of zombies in every two consequetive levels
    and if the sum is greater than 1 => 'Hopeless'
    */
    map<int, int> level;
    level[0] = -1;
    int max_level = 0;
    for(int i = 0 ; i < int(A.size());i++){
    	level[i] = level[A[i]]+1;
    	max_level = max(max_level, level[i]);
    }
    vector<bool>has_zombie(A.size(), 0);
    for(int i = 0 ; i < int(B.size());i++){
    	has_zombie[B[i]] = true;
    }
    vector<int> sum_in_level(max_level);
    for(int i = 0; i <= max_level; i++){
    	int cnt_cur = 0;
    	for(int k = 0; k < int(A.size()); k++){
    		if(level[k] == i) cnt_cur++;
    	}
    	sum_in_level[i] = cnt_cur;
    }
    for(int i = 1; i < sum_in_level.size(); i++) {
    	if(sum_in_level[i]+sum_in_level[i-1] > 1) return "Hopeless";
    }
    return "Doable";
}





