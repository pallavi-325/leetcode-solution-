class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int min=INT_MAX;
       int profit =0;

       for(int p : prices){
        if(p<min) min =p;
        else {
            profit= max(profit , p-min);
        }
       } 
       return profit;
    }
};