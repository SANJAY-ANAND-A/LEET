class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        if (indexDiff <= 0 || valueDiff < 0) return false;

        unordered_map<long long, long long> buckets;
        long long width = (long long)valueDiff + 1;

        for (int i = 0; i < (int)nums.size(); i++) {
            long long val = nums[i];
            long long id = (val >= 0) ? (val / width) : ((val + 1) / width - 1);

            if (buckets.count(id)) return true;
            if (buckets.count(id - 1) && llabs(val - buckets[id - 1]) <= valueDiff) return true;
            if (buckets.count(id + 1) && llabs(val - buckets[id + 1]) <= valueDiff) return true;

            buckets[id] = val;

            if (i >= indexDiff) {
                long long oldVal = nums[i - indexDiff];
                long long oldId = (oldVal >= 0) ? (oldVal / width) : ((oldVal + 1) / width - 1);
                buckets.erase(oldId);
            }
        }
        return false;
    }
};