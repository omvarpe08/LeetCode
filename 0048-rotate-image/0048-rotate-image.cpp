class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i=0; i<n-1;i++) {
            for(int j=i+1; j<n; j++) {
                swap(matrix[i][j] , matrix[j][i]);
            }
        }

        for(int i=0; i<n; i++) {
            reverse(matrix[i].begin() , matrix[i].end());
        }
    }  
    
};

//optimal
//TC = O(n^2/2) + O(n^2) = O(n^2/2 + n^2) = O(3*n^2 / 2) = O(n^2)
//sc = O(1)