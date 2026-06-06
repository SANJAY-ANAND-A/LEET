class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> lSum(nums.size(),0);
        int sum = 0 , n = nums.size();
        for(int i = 0 ; i < n ; i++ )
        {
            lSum[i] = sum ;
            sum += nums[i];
        }
        for(int i = 0 ; i < n ; i++ )
        {
            sum -= nums[i];
            lSum[i]=std::abs(lSum[i]-sum);
        }  
        return lSum;
    }
};