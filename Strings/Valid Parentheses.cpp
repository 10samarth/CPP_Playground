class Solution {
public:
    bool isValid(string s) {
        stack<char> sym;
        
        for (char c : s){
            if(c=='('){
                sym.push(')');
            }
            else if(c=='{'){
                sym.push('}');
            }
            else if(c=='['){
                sym.push(']');
            }
            else{
                if(sym.empty()||sym.top()!=c){
                    return false;
                }
                sym.pop();
            }
            
        }
        
        return sym.empty();
    }
};