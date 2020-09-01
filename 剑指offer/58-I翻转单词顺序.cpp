class Solution {
public:
    string reverseWords(string s) {
      stack<string> stk;
      string curstring = "";
      string ans = "";

      for(int i = 0;i < s.size();i++)
      {
        if(s[i] != ' ')
        {
          curstring += s[i];
        }
        else
        {
          if(curstring.size() != 0)
          {
            stk.push(curstring);
            curstring.clear();
          }
          
        }
      }
      if(curstring.size() != 0)
      {
        stk.push(curstring);
      }

      if(!stk.empty())
      {
        ans += stk.top();
        stk.pop();
      }
      while(!stk.empty())
      {
        ans += ' ';
        ans += stk.top();
        stk.pop();
      }
      
      return ans;
    }
};
