class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result;
        for (auto &word : words) {
            int sum = 0;
            for (char c : word) {
                sum += weights[c - 'a'];
            }
            int mod = sum % 26;
            char mapped = 'z' - mod;  // reverse alphabetical mapping
            result.push_back(mapped);
        }
        return result;
    }
};
