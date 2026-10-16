class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        int n = asteroids.size();

        for(int i=n-1; i>=0; i--) {
            if(st.empty()) {
                st.push(asteroids[i]);
            }

            else if(asteroids[i]<0 ) {
                st.push(asteroids[i]);
            }

            else if(asteroids[i]>0 && st.top()<0 ) {
                if(asteroids[i] > -st.top()) {
                    while(!st.empty() && st.top()<0 && asteroids[i] > -st.top()) {
                        st.pop();
    
                    }
                    if(!st.empty() && asteroids[i] == -st.top()) {
                        st.pop();
                    }
                    else if(!st.empty() && asteroids[i] < -st.top()) {
                        continue;
                    }
                    else {
                        st.push(asteroids[i]);
                    }
                    
                }
                else if(asteroids[i] == -st.top()) {
                    st.pop();
                }
                else if (asteroids[i] < -st.top()) {
                    continue;
                }
            }
            else {
                st.push(asteroids[i]);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};