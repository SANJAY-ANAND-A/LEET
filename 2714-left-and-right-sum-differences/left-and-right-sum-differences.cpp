class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> res(nums.size());
        vector<int> lSum(nums.size(),0);
        vector<int> rSum(nums.size(),0);
        int sum = 0 , n = nums.size();
        for(int i = 0 ; i < n ; i++ )
        {
            lSum[i] = sum ;
            sum += nums[i];
        }
        for(int i = 0 ; i < n ; i++ )
        {
            sum -= nums[i];
            rSum[i] = sum;
        }
        for(int i = 0 ; i < n ; i++ )
        {
            res[i] = std::abs(lSum[i]-rSum[i]);
        }
        rSum.clear();
        rSum.shrink_to_fit();
        lSum.clear();
        lSum.shrink_to_fit();
        return res;
    }
};