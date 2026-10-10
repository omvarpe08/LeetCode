class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum=0;
        int cnt = 0;
        map<int,int> mpp;

        for(int i=0; i<n; i++) {
            sum += nums[i];

            // mpp[0] = 1;
            if(sum == k) {                                        
                cnt++;
            }                           

            int rem = sum - k;

            if(mpp.find(rem) != mpp.end()) {
                cnt += mpp[rem];
            }

            mpp[sum]++;

        }
        return cnt;
    }
};

//OPtimal
//TC = O(n * logn)   ...for map
//TC = O(n * 1)   ...for unordered map (Best & Avg Case) 
//TC = O(n^2)   ...for unordered map (Worst Case) 
//SC = O(n)