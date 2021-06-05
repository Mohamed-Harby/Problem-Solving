// Problem Statement: https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> temp = matrix;
        int n = temp.size()-1;
        for(int i = 0; i <= n; ++i) {
            for(int s = 0; s <= n; ++s) {
                temp[s][n-i] = matrix[i][s];
            }
        }
        matrix = temp;
    }
};
