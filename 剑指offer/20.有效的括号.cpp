class Solution {
public:
    bool isValid(string s) {
      if(s.size() == 0) return true;
      stack<char> stk;
      for(int i = 0; i < s.size(); ++i){
        if(!stk.empty()){
          char ch = stk.top();
          if(s[i] == '}' && ch == '{'){
            stk.pop();
          }else if(s[i] == ']' && ch == '['){
            stk.pop();
          }else if(s[i] == ')' && ch == '('){
            stk.pop();
          }else{
            stk.push(s[i]);
          }
        }else{
          stk.push(s[i]);
        }
      }
      return stk.empty();
    }
};
