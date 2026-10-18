class Solution {
public:
    vector<int> nse(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if (st.empty()) {
                ans[i] = n;
            } else {
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    vector<int> pse(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    vector<int> nle(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if (st.empty()) {
                ans[i] = n;
            } else {
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }


    vector<int> ple(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }


    long long subArrayRanges(vector<int> &nums) {
        int n = nums.size();
        long long mod = 1e9 + 7;
        long long sum_l = 0;
        long long sum_s = 0;

        vector<int> next_s = nse(nums);
        vector<int> prev_s = pse(nums);
        vector<int> next_l = nle(nums);
        vector<int> prev_l = ple(nums);

        for (int i = 0; i < n; i++) {
            long long left = i - prev_s[i];
            long long right = next_s[i] - i;

            long long contribution = (long long)nums[i] * left * right;
            sum_s = (sum_s + contribution);

            left = i - prev_l[i];
            right = next_l[i] - i;

            contribution = (long long)nums[i] * left * right;
            sum_l = (sum_l + contribution);
        }

        return sum_l-sum_s;
    }
};

