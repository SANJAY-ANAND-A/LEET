class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        auto max_idx = std::max_element(candies.begin(),candies.end());
        for(int totCan : candies)
        {
            res.push_back((totCan + extraCandies) >= *max_idx );
        }
        return res;
    }
};