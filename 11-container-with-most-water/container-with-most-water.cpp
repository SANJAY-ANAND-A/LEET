class Solution {
    private:
    int Carea(int st, int end , int i , int j)
    {
        int a= (min(st,end)*(j-i));
        return a;
    }
public:
    int maxArea(vector<int>& height) {
        int area =0;
        int i = 0;
        int j = height.size()-1;
        while(i<j)
        {
           int tarea = Carea(height[i],height[j],i,j);
           area = max(area , tarea);
        if(height[i]<height[j])
        {
            i++;
        }else{j--;}
        }
        return area;
    }
};