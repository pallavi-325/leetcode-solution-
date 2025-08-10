class Solution {
public:
    void rotate(vector<int>& a, int k) {
        int n=a.size();
        k=k%n;
        reverse(a.begin(), a.end());
        reverse(a.begin(), a.begin()+k);
        reverse(a.begin()+k,a.end());

    }
};