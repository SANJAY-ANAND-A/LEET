class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1,0});
        sort(restrictions.begin(), restrictions.end());
        for (int i = 1; i < restrictions.size(); i++) {
            restrictions[i][1] = min(restrictions[i][1],
                                     restrictions[i-1][1] + (restrictions[i][0] - restrictions[i-1][0]));
        }
        for (int i = restrictions.size()-2; i >= 0; i--) {
            restrictions[i][1] = min(restrictions[i][1],
                                     restrictions[i+1][1] + (restrictions[i+1][0] - restrictions[i][0]));
        }
        int maxHt = 0;
        for (int i = 1; i < restrictions.size(); i++) {
            int d = restrictions[i][0] - restrictions[i-1][0];
            int h1 = restrictions[i-1][1];
            int h2 = restrictions[i][1];
            maxHt = max(maxHt, (d + h1 + h2) / 2);
        }
        maxHt = max(maxHt, restrictions.back()[1] + (n - restrictions.back()[0]));
        return maxHt;
    }
} ;
