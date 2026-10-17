class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        
        int n = asteroids.size();

        for(int asteroid : asteroids) {
            if(asteroid > 0) {
                st.push_back(asteroid);
            }
            else {
                while(!st.empty() && st.back() > 0 && st.back() < -asteroid) {
                    st.pop_back();
                }
                if(!st.empty() && st.back() == -asteroid) {
                    st.pop_back();
                }
                else if(st.empty() || st.back() < 0) {
                    st.push_back(asteroid);
                }
            }
        }
        return st;
    }
};

//TC = O(N + N) = O(2N)   ...for + while (we are doing pop in while & we can push maxm n element in stack thus we can pop maxm n element thus while can run maxm n times thus O(N))

//SC = O(N) ...st