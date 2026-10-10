class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int vecsum = 0;
        int n = nums.size();
        int sum = (n*(n+1))/2;

        for(int i=0; i<n; i++) {
            vecsum+=nums[i];
        }

        return sum - vecsum;
    }

};

//Optimal 
//TC = O(n)
//SC = O(1)
//XOR soln is better than this bcoz here some time sum variable has to store too big value so we have to change its datatype to long like this in XOR soln we dont have to store any kind of big value