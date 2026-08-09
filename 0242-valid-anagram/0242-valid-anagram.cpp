class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
        return false;
        unordered_map <char,int> mp1;
        unordered_map <char,int> mp2;
        for(auto x : s){
            if(mp1.find(x) == mp1.end()){
                mp1[x] = 1;
            }
            else{
                mp1[x]++;
            }
        }
        for(auto x : t){
            if(mp2.find(x) == mp2.end()){
                mp2[x] = 1;
            }
            else{
                mp2[x]++;
            }
        }

        if(mp1 == mp2){
            return true;
        }
        else {
            return false;
        }
    }
};