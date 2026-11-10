
class Solution {
public:
    void bfs(int i, vector<vector<int>>& isConnected, vector<int>& vis, int n) {
        queue<int> q;
        q.push(i);
        vis[i] = 1;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int j = 0; j < n; j++) {
                if(isConnected[node][j] == 1 && !vis[j]) {
                    vis[j] = 1;
                    q.push(j);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> vis(n, 0);
        int provinces = 0;

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                provinces++;
                bfs(i, isConnected, vis, n);
            }
        }

        return provinces;
    }
};

//TC = O(N + N^2) = o(N^2)  ...for + we call bfs multiple time through for loop but in total by while & for loop of bfs we take O(N^2) of TC.
//SC = O(N) + O(N) = O(2N) = O(N)  ..vis + queue

//we can also do it by DFS 