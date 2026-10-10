class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int el = nums[0];
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                el = nums[i];
                cnt++;
            } else if (nums[i] == el) {
                cnt++;
            } else {
                cnt--;
            }
        }
        return el;
    }
};

// Optimal - Moore's Voting Algorithm.
// TC = O(n)
// SC = O(1)