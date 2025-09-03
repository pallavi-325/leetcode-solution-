class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int candidate = 0;

        for(int n : nums){
            if(count ==0) candidate = n;
            if(n == candidate) count ++;
            else count --;
        }

       return candidate;
    }
};