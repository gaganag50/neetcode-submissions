class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> stk;
        for(int i = 0; i < n; ++i){
            char ch = s[i];
            if(ch == ')' || ch == '}' || ch == ']') {
                if(stk.empty())return false;
                if(ch == ')')if(stk.top() != '(') return false;
                if(ch == '}')if(stk.top() != '{') return false;
                if(ch == ']')if(stk.top() != '[') return false;
                stk.pop();
            } else {

                stk.push(ch);
            }
        }

        return stk.empty();
    }
};
