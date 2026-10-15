
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> st;
        unordered_map<int, int> mp;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if (st.empty()) {
                mp[nums2[i]] = -1;
            } else {
                mp[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(mp[nums1[i]]);
        }

        return ans;
    }
};

//TC = O(N2 + N2 + N1)     ...for(nums2) + while + for(nums1)
//...while loop (here by while loop we are just poping element & we know we can pop each element just once from stack & we have total of N2 element. thus we can pop maxm N times. thus while loop can run maxm N times. thus O(N2) for this).

//SC = O(N2 + N1)  ...unoreder_map(which stores next greater element of each alement of nums2 thus O(N2) for this) + ans (in it we are storing next greater element of each element of nums1 thus O(N1) for this)