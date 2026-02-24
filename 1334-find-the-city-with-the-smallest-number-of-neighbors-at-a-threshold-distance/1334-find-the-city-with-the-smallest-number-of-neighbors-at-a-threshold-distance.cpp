class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(n, INF));
        
        
        for(int i = 0; i < n; i++)
            dist[i][i] = 0;
        
    
        for(auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }
        
        
        for(int via = 0; via < n; via++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(dist[i][via] + dist[via][j] < dist[i][j]) {
                        dist[i][j] = dist[i][via] + dist[via][j];
                    }
                }
            }
        }
        
        int result = -1;
        int minReachable = n;
        
        for(int i = 0; i < n; i++) {
            int count = 0;
            
            for(int j = 0; j < n; j++) {
                if(i != j && dist[i][j] <= distanceThreshold)
                    count++;
            }
            

            if(count <= minReachable) {
                minReachable = count;
                result = i;
            }
        }
        
        return result;
    }
};