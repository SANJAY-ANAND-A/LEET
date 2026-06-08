class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> greater;
        int  n  = nums.size();
        int j = 0,eq = 0;
        for(int i = 0 ; i < n ; i++ )
        {
            if(nums[i]<pivot)
            {
                nums[j++]= nums[i];
            }
            else if(nums[i]==pivot)
            {
                eq++;
            }
            else
            {
                greater.push_back(nums[i]);
            }
        }
        for(int k = 0 ; k < eq ; k++)
        {
            nums[j++]= pivot;
        }
        for(int great: greater)
        {
            nums[j++]= great;
        }
        return nums;
    }
};