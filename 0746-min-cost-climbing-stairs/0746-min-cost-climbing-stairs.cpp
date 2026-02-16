class Solution {
public:

    vector<int> dp = vector<int>(1001, -1);

    int rec(vector<int> &cost, int ind)
    {
        if(ind < 0) return 0;
        
        if(ind <= 1) 
            return cost[ind];

        if(dp[ind] != -1) 
            return dp[ind];
        
        return dp[ind] = cost[ind] + 
                         min(rec(cost, ind - 1), rec(cost, ind - 2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return min(rec(cost, n - 1), rec(cost, n - 2));
    }
};
