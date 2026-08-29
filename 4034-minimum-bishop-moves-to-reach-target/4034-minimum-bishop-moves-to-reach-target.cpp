class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int sum1 = 0 ;
        int sum2 = 0;
        if(source == target){
            return 0;
        }
        for(int i = 0; i < 2;i++){
            sum1 += source[i];
            sum2 += target[i];
        }
        if((sum1%2) != (sum2%2)){
            return -1;
        }
        if(sum1 == sum2 || source[0]-source[1] == target[0]-target[1]){
            return 1;
        }
        int temp = sum1;
        while (temp > 0){
            temp = temp-2;
            if(temp == sum2){
                return 2;
            }
        }
        temp = sum2;
        while (temp > 0){
            temp = temp-2;
            if(temp == sum1){
                return 2;
            }
        }
        return -1;
    }
};