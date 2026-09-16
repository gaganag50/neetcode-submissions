class Solution {
    bool isOperator(const string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/"; 
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(string& token: tokens) {
            if(isOperator(token)) {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                switch(token[0]) {
                    case '+': stk.push(a + b); break;
                    case '-': stk.push(a - b); break;
                    case '*': stk.push(a * b); break;
                    case '/': stk.push(a / b); break;
                }
                
            } else {
                stk.push(stoi(token));
            }
        }
        return stk.top();
    }
};
