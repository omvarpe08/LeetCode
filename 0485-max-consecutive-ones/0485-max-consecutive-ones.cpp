class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int c1=0;
        int mxc1 = 0;
        for(int i=0; i<n; i++) {
            if(nums[i]==1) {
                c1++; 
                mxc1 = max(mxc1 , c1);
            }
            else c1=0;

            // if(mxc1 < c1) mxc1=c1;
        }
        return mxc1;
    }
};

//Optimal
//TC = O(n) 