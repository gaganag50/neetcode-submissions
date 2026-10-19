class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0){
            return {};
        }
        if(n == 1){
            return {"()"};
        }
        vector<string> curr = generateParenthesis(n-1);
        set<string> ans;
        for(int i = 0; i <= n - 1; ++i){
            
            for(auto it: curr){
                string s;
                int j;
                for(j = 0; j < i; ++j){
                    s.push_back(it[j]);
                }
                s += "()";
                while(j < it.size()){
                    s.push_back(it[j]);
                    ++j;
                }
                ans.insert(s);
            }
        }
        return vector<string>(ans.begin(), ans.end());

        /*
            n == 2
            ()()
            (())


            n == 3
            ()()()
            (())()
            ()()()

            ()(())
            (()())
            ((()))
        */
    }
};
