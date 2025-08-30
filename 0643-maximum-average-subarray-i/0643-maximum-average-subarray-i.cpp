class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();

        double maxi=-1e9;
        double sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];

            maxi=sum;
           // maxi=max(sum,maxi);
        }

        for(int i=k;i<n;i++){
            //sum=sum-nums[i]+nums[i-k];
               sum = sum - nums[i-k] + nums[i];
             maxi=max(sum,maxi);
        }
        return maxi / k;
    }
};