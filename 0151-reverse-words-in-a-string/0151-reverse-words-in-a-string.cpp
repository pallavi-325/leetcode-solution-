class Solution {
public:
    string reverseWords(string s) {
        // Step 1: reverse whole string
        reverse(s.begin(), s.end());

        int n = s.size();
        int i = 0, j = 0;

        // Step 2: reverse each word individually
        while (i < n) {
            while (i < n && s[i] == ' ') i++;   // skip spaces
            j = i;
            while (j < n && s[j] != ' ') j++;   // find word end
            reverse(s.begin() + i, s.begin() + j); // reverse word once
            i = j;
        }

        // Step 3: remove extra spaces
        string ans;
        stringstream ss(s);
        string word;
        while (ss >> word) {  // ss >> word ignores multiple spaces
            if (!ans.empty()) ans += " ";
            ans += word;
        }

        return ans;
    }
};
