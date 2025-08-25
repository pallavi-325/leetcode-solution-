class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n!=m) return false;

        vector<int> frq(26,0);
        for(char c : s){
            frq[c - 'a']++;
        }

        for(char c : t){
            frq[c - 'a']--;
        }


        for ( int count : frq){
            if(count != 0) return false;
        }
        return true;
    }
};