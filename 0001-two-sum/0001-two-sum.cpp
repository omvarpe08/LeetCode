class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int n = nums.size();
       map<int,int> mpp;
       

       for(int i=0; i<n; i++) {

            if(mpp.find(target - nums[i]) != mpp.end() ) {
                return {i, mpp[target - nums[i]]};    
            }

            mpp[nums[i]]=i;

       }

       return {};
    }   
};

//Optimal
//if we use map - loop is ruuning n times & each time happening one map operation & any map operation takes O(log n) TC.
//TC = O(n * Log n) 

//if we use unorderedmap - loop is ruuning n times & each time happening one map operation & any map operation takes O(1) TC in best & avg case and O(n) TC in worst case.
//TC = O(n)   ...in best & avg case O(n*1).
//TC = O(n*n) ...in worst case

//SC = O(n)