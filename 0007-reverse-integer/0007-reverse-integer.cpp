class Solution {
public:
    int reverse(int x) {

        int ld;
        int num=0;

        while(x!=0){
            ld = x%10;

            if(num > INT_MAX/10 ) return 0;
            if(num < INT_MIN/10 ) return 0;

            num = num*10+ld;
            x=x/10;
        } 

        if(num > INT_MAX || num < INT_MIN ) return 0;
        return num;
    }
};