class Solution {
public:
    
    
    int ms(vector<int>& nums, int low, int high) {
        int cnt = 0;

        if (low >= high)
            return 0;

        int mid = (low + high) / 2;

        cnt += ms(nums, low, mid);
        cnt += ms(nums, mid + 1, high);

        cnt += CountPairs(nums, low,mid,high);

        merge(nums, low, mid, high);

        return cnt;
    }

    void merge(vector<int>& nums, int low, int mid, int high) {
        int left = low;
        int right = mid + 1;
        vector<int> temp;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } 
            else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }

    }

    int CountPairs(vector<int>& nums , int low, int mid, int high) {
        int cnt = 0;
        int right = mid+1;
        for(int i=low; i<=mid; i++) {
            while(right <= high && nums[i] > (long long)nums[right]*2) {
                right++;
            }
            cnt = cnt + right - (mid+1);
        }
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return ms(nums, 0, nums.size() - 1);
    }
    
};

//Optimal

//remember one thing in Big O notation
//log₂(n) = log n
//log₂(n) = exact mathematical value (base 2 because we divide by 2).
//log n = the Big O notation for the same thing (base is not written because changing the base only changes the value by a constant factor, which Big O ignores).

//TC = (O(n) + O(n)) * O(log n) = O(2n * log n) = O(n*log n)
//merge + countpair for log n times
//here we are going to have merge & countpair for each step
//in worst case both merge & count pair would have n steps thus have O(n) TC.
//&here we are going to have log n steps. (why logn step look that in notebook)
//thus merge + countpair for log n times.
//Still dont understand than look in notes of merge sort in notebook

//Auxiliary Space: O(n) (temp used during merging) ..in worst case it has to store n element.
//Recursion Stack: O(log₂(n)) = O(log n)  
//...each step waited to be completed. (so it takes space)
//Each recursive call stores only a few variables (low, high, mid, cnt, etc.), so each call takes O(1) space.
//total step is log n which waited to be completed & each takes O(1) space.
//thus log n * 1 = log n.

//SC = O(n)+O(logn) = O(n)
//when n become too big then log n becomes insignificant compared to n. 
//n grows much faster than log n.
//n = 1000000 , log n = 20.
