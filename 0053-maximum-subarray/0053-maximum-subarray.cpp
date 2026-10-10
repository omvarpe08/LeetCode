class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int mxsum = INT_MIN;
        int sum =0;
        for(int i=0; i<n; i++) {

            sum+=nums[i];
            mxsum = max(sum,mxsum);

            if(sum < 0) {
                sum = 0;
            }
        }
        return mxsum;
    }
};

//Optimal - Kadane's Algorithm
//TC = O(n)
//SC = O(1)