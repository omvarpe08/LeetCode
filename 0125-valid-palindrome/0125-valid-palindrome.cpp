class Solution {
public:
    bool isPalindrome(string s) {

        string s1="";

        for(int i=0; i<s.length(); i++) {
            
            if(isalnum(s[i])) {
                s1.push_back(tolower(s[i]));
            }
        }
        
        
        for(int i=0; i<s1.length()/2; i++) {
            if((s1[i]) != (s1[s1.length() - i -1])) return false;
            }
            
        return true;

        // int l=0;
        // int r=s1.length() - 1;
        // while(l<r) {
        //     if(s1[l] != s1[r]) return false;

        //     l++; r--;

        // }
        // return true;



    }
};