class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int s = flowerbed.size();

        if(n == 0) return true;

        if(s <= 2){
            if(s == 2 && flowerbed[0] == 0 && flowerbed[1] == 0 && n == 1)
                return true;
            else if(s == 1 && flowerbed[0] == 0 && n == 1)
                return true;
            else
                return false;
        }

        if(flowerbed[0] == 0 && flowerbed[1] == 0)
        {
            n--;
            flowerbed[0] = 1;
        }

        for(int i = 1; i < s - 2; i++)
        {
            if(flowerbed[i] == 0 &&
               flowerbed[i+1] == 0 &&
               flowerbed[i+2] == 0)
            {
                n--;
                flowerbed[i+1] = 1;
                i++;
            }

            if(n <= 0)
                return true;
        }

        if(flowerbed[s-2] == 0 && flowerbed[s-1] == 0)
        {
            n--;
            flowerbed[s-1] = 1;
        }

        return n <= 0;
    }
};