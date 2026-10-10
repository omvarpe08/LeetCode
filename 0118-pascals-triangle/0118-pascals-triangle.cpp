class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> vec;
        vector<int> v;
        int ans;

        for(int i=0; i<n; i++) {
            ans = 1;
            v.push_back(ans);
            for(int j=1; j<=i; j++) {
                ans *= (i-j+1);
                ans /= j;
                v.push_back(ans);
            }
            vec.push_back(v);
            v.clear();
        }

        return vec;
    }
};

//Optimal
//TC = O(n^2)

//SC = AS + OS
//Auxiliary Space: O(1)
//Output Space: O(n^2)

//here actual SC would O(n^2) AS SC = AS + OS but here we mostly tell SC as O(1) as we dont use any space to solve problem just use space to return answer.but stilll depend on interviwer how he ask question.