class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int e = extraCandies;
        int max =-1;
        for(auto a : candies)
        {
            if(a>max) max = a;
        }
        vector<bool> ans(n);
        int i = 0;
        for(auto a:candies)
        {
            if(a+e >= max) ans[i]=true;
             i++;
        }
        return ans;
    }
};