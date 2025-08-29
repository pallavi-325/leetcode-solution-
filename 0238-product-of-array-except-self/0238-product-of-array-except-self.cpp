class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> prifix(n) , sufix(n);

        prifix[0] = 1;
        for(int i=1;i<n;i++){
            prifix[i] = prifix[i-1]*nums[i-1];
        }
         sufix[n-1] =1;
        for(int i=n-2;i>=0;i--){
            sufix[i]=sufix[i+1]*nums[i+1];
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = prifix[i]*sufix[i];
        }
        return ans;
    }
};