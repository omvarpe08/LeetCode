class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        
        int n = asteroids.size();

        for(int i=0; i<n; i++) {
            if(asteroids[i] > 0) {
                st.push_back(asteroids[i]);
            }
            else {
                while(!st.empty() && st.back() > 0 && st.back() < -asteroids[i]) {
                    st.pop_back();
                }
                if(!st.empty() && st.back() == -asteroids[i]) {
                    st.pop_back();
                }
                else if(st.empty() || st.back() < 0) {
                    st.push_back(asteroids[i]);
                }
            }
        }
        return st;
    }
};

//TC = O(N + N) = O(2N)   ...for + while (we are doing pop in while & we can push maxm n element in stack thus we can pop maxm n element thus while can run maxm n times thus O(N))

//SC = O(N) ...st