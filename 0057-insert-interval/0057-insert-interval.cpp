class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
         

         intervals.push_back(newInterval);
         sort(intervals.begin(),intervals.end());
          vector<vector<int>> ans;
          for(auto& x : intervals){
            if(!ans.empty() && ans.back()[1] >= x[0]){
            ans.back()[1] = max(ans.back()[1],x[1]);
          }
          else{
            ans.push_back(x);
          }
    }

     return ans;

    }
};