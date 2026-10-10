class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int j=n;
        for(int i=0; i<n; i++) {
            if(nums[i]==0) {
                j=i;
                break;
            }
        }
        for(int i=j+1; i<n; i++) {
            if(nums[i] != 0) {
                swap(nums[i] , nums[j]);
                j++;
            }
        }
    }
};

//Optimal
//TC = O(n)  
//...1st for loop + 2nd for loop = 0th index to index till we get zero + index at which we get zero + 1 to last index.

//SC = O(1) ...we are definately using our given vector modifying it but we are not using any extra vector.