class Solution {
public:
    bool isPalindrome(int x) {
        int num=x;
        
        long rev=0;
        int ld;
        while(x>0) {
            ld = x%10;
            x=x/10;
            rev = rev*10+ld;
        }
        if(num==rev) return true;
        return false;
    }
};