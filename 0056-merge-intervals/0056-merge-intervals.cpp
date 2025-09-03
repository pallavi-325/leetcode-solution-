class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        int n=interval.size();
        sort(interval.begin(),interval.end());
         vector<vector<int>> ans;
         ans.push_back(interval[0]);

         for(int i=0;i<n;i++){
            vector<int> & last = ans.back();

            if(interval[i][0]<=last[1]){
                last[1] = max(interval[i][1],last[1]);

            }else{
                ans.push_back(interval[i]);
            }
         }
         return ans;
    }
};