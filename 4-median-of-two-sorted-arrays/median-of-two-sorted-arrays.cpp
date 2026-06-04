class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int m = nums1.size();
       int n = nums2.size();
       vector<int> temp;
       int i=0,j= 0 ;
       while(i<m && j < n){
        if(nums1[i]<nums2[j]){
            temp.push_back(nums1[i++]);
        }
        else{
            temp.push_back(nums2[j++]);
        }
       }
       while(i<m){
            temp.push_back(nums1[i++]);
       } 
       while(j<n){
            temp.push_back(nums2[j++]);
       } 
       int tot = m+n;
       if(tot%2==0){
        return (temp[(tot/2)-1]+temp[tot/2])/2.0;
       }else{
        return temp[tot/2];
       }
    }
};