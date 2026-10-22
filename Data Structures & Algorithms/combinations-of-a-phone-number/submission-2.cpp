class Solution {
    vector<string> ans;
    string curr;
    map<int,vector<char>> mp;
    void init(){
        int no = 2;
        for(char ch = 'a'; ch <= 'z'; ){
            vector<char> s;
            for(int a = 0; a < 3; ++a){
                s.push_back(ch);
                ++ch;
            }
            if(ch == 'z'){
                s.push_back(ch);

            }
            if(no == 7){
                s.push_back(ch++);
            }
            mp[no++]=s;
            if(ch == 'z')break;
        }
    }
    void display(){
        for(auto it: mp){
            cout << it.first << "-> ";
            for(auto i: it.second){
                cout << i << ' ';
            }
            cout << endl;
        }
    }
    void helper(const string& digits, int start, int end){
        if(start > end){
            ans.push_back(curr); return;
        }
        vector<char> am = mp[digits[start]-'0'];

        for(char i: am){

            curr.push_back(i);
            helper(digits,start+1,end);
            curr.pop_back();
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n == 0)return ans;
        init();
        // display();
        ans.clear();
        curr.clear();

        
        helper(digits,0,n-1);
        return ans;
    }
};
