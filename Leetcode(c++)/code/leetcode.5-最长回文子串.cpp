class Solution {
public:
    string longestPalindrome(string s) {
      int len = s.size();
      if(len <= 1) return s;
      int start = 0, maxLen = 1;
      vector<vector<bool>> dp(len, vector<bool>(len, false));
      for(int i = 0; i < len; ++i) dp[i][i] = true;
      for(int i = 1; i < len; ++i){
        for(int j = 0; j < i; ++j){
          if(s[i] == s[j]){
            if(i - j < 3) dp[i][j] = true;
            else 
            dp[i][j] = dp[i-1][j+1];
          }
          if(dp[i][j]){
            if(maxLen < (i-j+1)){
              maxLen = i-j+1;
              start = j;
            }
          }
        }
      }
      return s.substr(start, maxLen);    
    }
};
