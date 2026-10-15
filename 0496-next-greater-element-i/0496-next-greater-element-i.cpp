class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int x;
        for(int i=0; i<nums1.size(); i++) {
            for(int j=0; j<nums2.size(); j++) {
                if(nums1[i] == nums2[j]) {
                    x = -1;
                    for(int k=j+1; k<nums2.size(); k++) {
                        if(nums2[k] > nums2[j]) {
                            x = nums2[k];
                            break;
                        }
                    }
                    ans.push_back(x);
                    break;
                }
            }
        }
        return ans;
    }
};