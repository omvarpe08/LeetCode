class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long mod = 1e9 + 7;
        long long sum = 0;

        stack<int> st;
        vector<int> nse(n);
        vector<int> pse(n);

        // Next Smaller Element (NSE)
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

        while (!st.empty()) {
            st.pop();
        }

        // Previous Smaller Element (PSE)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                pse[i] = -1;
            } else {
                pse[i] = st.top();
            }

            st.push(i);
        }

        // Calculate each element's contribution
        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;

            long long contribution = arr[i] * left * right;
            sum = (sum + contribution) % mod;
        }

        return sum;
    }
};

//TC = O(5N) ...NSE(for+while)(N+N) + PSE(for+while)(N+N) + for(N)
//SC = O(3N) ...NSE + PSE + st