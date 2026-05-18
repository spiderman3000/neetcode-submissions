class Solution {
    bool isPair(char b1, char b2){
        if(b1 == '[' && b2 == ']'){
            return true;
        } else if(b1 == '{' && b2 == '}'){
            return true;
        } else if(b1 == '(' && b2 == ')'){
            return true;
        }
        return false;
    }
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if((s[i] == '}' || s[i] == ']' || s[i] == ')')){
                if(st.empty()) return false;
                if(!isPair(st.top(), s[i])) return false;
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};
