class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<int> st;
        string ans = "";

        if(k==n) {
            return "0";
        }

        for(int i=0; i<n; i++) {
            while(!st.empty() && st.top()-'0' > num[i]-'0' && k>0) {
                st.pop();
                k--;
            }

            st.push(num[i]);
        }
        while(k>0) {
            st.pop();
            k--;
        }
    
    
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    int i=ans.size() - 1;
    while(i >= 0 && ans[i] == '0') {
        ans.pop_back();
        i--;
    }
    reverse(ans.begin(),ans.end());

    if(i<0) return "0";
    return ans;

    }
};