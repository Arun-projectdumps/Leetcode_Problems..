class Solution {
public:
    int maxProduct(int n) {
        int max1 = -1;
        int max2 = -2;
        if (n < 9){
            return n;
        }
        while (n > 0)
        {
            if(max1 < n%10  ){
                if(max1 != -1){
                    max2 = max1;
                    max1 = max(max1,n%10);
                }
                else{
                max1 = max(max1,n%10);
                }
            }
            else if (max2 < n%10 )
            {
                max2 = max(max2,n%10);
            }
            n /= 10;
        }
        return max1*max2;
    }
};