class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0;
        for(char letter : t){
            //std::cout << letter << "  " << s[idx] <<std::endl;
            if(letter == s[idx]){
                idx++;
            }
        }
        if(idx == s.length()){
            return true;
        }
        else{
            return false;
        }
    }
};