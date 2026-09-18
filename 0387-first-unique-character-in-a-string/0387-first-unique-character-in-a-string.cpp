class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int,int> cnt;
        for(int i = 0 ; i < s.length();i++){
            cnt[s[i]]++;
        }
        for(int i = 0 ;i<s.length();i++){
            if(cnt[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};