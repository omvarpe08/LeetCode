class Solution {
public:
    void bfs(int i, vector<vector<int>> isConnected , vector<int>& visited, int n) {
        queue<int> q;
        q.push(i);
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(int j=0; j<n; j++) {
                if(isConnected[node-1][j]==1 && !visited[j+1]) {
                    q.push(j+1);
                    visited[j+1] = 1;
                }
            }
        }

    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n+1, 0);
        int cnt = 0;
        for(int i=1; i<=n; i++){
            if(!visited[i]) {
                cnt++;
                bfs(i, isConnected, visited, n);
            }
        }
        return cnt;
    }
};