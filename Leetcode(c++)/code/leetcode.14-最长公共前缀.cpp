class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      if(strs.size() == 0) return "";
      string ans = strs[0];
      int index = 0, minLen = strs[0].size();
      for(int i = 0; i < strs.size(); ++i){
        int len = strs[i].size();
        minLen = min(minLen, len);
      }
      for(int i = 1; i < strs.size(); ++i){
        int j = 0;
        for(; j < ans.size() && j < minLen; ++j){
          if(strs[0][j] != strs[i][j]){
            break;
          }
        }
        ans = strs[0].substr(0,j);
      }
      return ans; 
    }
};
