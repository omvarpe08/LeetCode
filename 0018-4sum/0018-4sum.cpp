class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int k,l;


        for(int i=0; i<n; i++) {
            if(i>0 && nums[i] == nums[i-1]) {
                continue;
            }
            for(int j=i+1; j<n; j++) {
                if(j>i+1 && nums[j] == nums[j-1]) {
                    continue;
                }
                k=j+1;
                l=n-1;
                while(k<l) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l] ;
                    if(sum > target) {
                        l--;
                    }
                    else if(sum < target) {
                        k++;
                    }
                    else {
                        vector<int> temp = {nums[i] , nums[j] , nums[k] , nums[l]};
                        ans.push_back(temp);

                        l--;
                        k++;

                        while(k<l && nums[k] == nums[k-1]) {
                            k++;
                        }

                        while(k<l && nums[l] == nums[l+1]) {
                            l--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

//Optimal
//TC = O(n^2 * n) 
//SC = O(m) ...m = no. of quadruplet