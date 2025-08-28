class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        

        set <int> st;
        for(int it : nums){
            //st.insert(it);
            if(st.count(it)){
                return true;
                //st.insert(it);
            }
            st.insert(it);
           // else return false;
        }
return false;
    }
};