class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<1)
            return "";
        
        int start =0, end=0;
        
        for(int i=0; i<s.length(); i++){
            int len1 = expandCenter(s,i,i);
            int len2 = expandCenter(s,i,i+1);
            
            int len = max(len1,len2);
            
            if(len>end-start){
                start = i-(len-1)/2;
                end = i+ len/2;
            }
        }
        
        return s.substr(start,(end+1-start));
    }
    
    int expandCenter(const string& s, int left, int right){
        int l = left, r = right;
        
        while(l>=0 and r<s.length() and s.at(l)==s.at(r)){
            l--;
            r++;
        }
        
        return r-l-1;
    }
};