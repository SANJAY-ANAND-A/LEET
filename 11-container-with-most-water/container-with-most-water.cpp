class Solution {
public:
long long getArea(int l ,int i, int j)
{
    long long b = (long long)j-i;
    return l*b;
}
    int maxArea(vector<int>& height) {
        
        int maxht=0;
        int tarea,area = 0;
        int i=0;
        int j = height.size()-1;
        while(i<j)
        {
        int h = min(height[i],height[j]);
         tarea = getArea(h,i,j);
        if(tarea > area)
        {
            area = tarea;
        }
        if(height[i]<height[j])
        {
            i++;
        }
        else{
            j--;
        }
        }
        return area;
    }
};