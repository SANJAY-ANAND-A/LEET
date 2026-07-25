class Solution {
public:
    int maxProduct(int n) {
        vector<int> arr;
        while( n > 0)
        {
            arr.push_back(n%10);
            n /= 10;
        }
        // quickSort(arr,0,n.size()-1);
        sort(arr.begin(),arr.end());
        return (arr[arr.size()-1])*(arr[arr.size()-2]);
    }
    
};