class Solution {
public:
    int sumSubarrayMins(vector<int> &arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                nse[i] = n;
            } else {
                nse[i] = st.top();
            }

            st.push(i);
        }

        vector<int> pse(n);
        stack<int> st1;

        for (int i = 0; i < n; i++) {
            while (!st1.empty() && arr[st1.top()] > arr[i]) {
                st1.pop();
            }

            if (st1.empty()) {
                pse[i] = -1;
            } else {
                pse[i] = st1.top();
            }

            st1.push(i);
        }
        int mod = 1e9 + 7;
        long long total = 0;
        for(int i=0; i<n; i++) {
            int l = pse[i];
            int r = nse[i];

            int l1 = i-l;
            int r1= r-i;

            long long sum = (long long)l1*r1*arr[i];

            total = (total + sum) % mod;

        }
        return total;
    }
};
