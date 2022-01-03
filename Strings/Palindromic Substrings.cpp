class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        
        for(int i=0; i<s.length();i++){
            ans+= countPalindrome(s, i, i);
            ans+= countPalindrome(s, i, i+1);
        }
        
        return ans;
    }
    
    int countPalindrome(const string& s, int l, int h){
        int ans = 0;
        
        while(l>=0 and h<s.length()){
            if(s[l]!=s[h])
                break;
            
            l--;
            h++;
            ans++;
        }
        
        return ans;
    }
};