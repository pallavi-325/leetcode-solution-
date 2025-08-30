class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        map<int, bool> mp;

        // Mark all numbers present
        for(int it : nums) 
            mp[it] = true;

        // Check from 0 to n for the missing number
        for(int i = 0; i <= n; i++) {
            if(!mp[i]) 
                return i;
        }

        return -1; // Just for safety, won't reach here
    }
};
