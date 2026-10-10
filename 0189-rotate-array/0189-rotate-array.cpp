class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin() , nums.begin() + (n-k));
        reverse(nums.begin()+ (n-k) , nums.begin() + (n));
        reverse(nums.begin() , nums.begin()+(n));
    }
};

//Optimal
//TC = O(2N)
//SC = O(1) ...not using any extra space to solve problem