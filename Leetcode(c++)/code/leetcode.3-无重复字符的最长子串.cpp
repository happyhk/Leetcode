class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      if(s.size() == 0) return 0;
      if(s.size() == 1) return 1;
      int maxLen = 0;
      int left = 0;
      unordered_set<int> st;
      for(int i = 0; i < s.size(); ++i){
        while(st.find(s[i]) != st.end()){
          st.erase(s[left]);
          left++;
        }
        st.insert(s[i]);
        maxLen = max(maxLen, i- left + 1);
      }
      return maxLen;
    }
};
