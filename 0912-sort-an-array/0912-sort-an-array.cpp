class Solution {
public:
    vector<int> sortArray(vector<int>& a) {
        int n = a.size();

        for(int i = 0; i < n-1; i++){
            int ind = i;
            for(int j = i+1; j < n; j++){
                if(a[j] < a[ind])
                    ind = j;
            }
            swap(a[i], a[ind]);
        }
        return a;
    }
};