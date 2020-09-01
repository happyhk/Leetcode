class Solution {
public:
    string reverseLeftWords(string s, int n) {
      if(s.size() < n) return s;
      int index = 0;
      for(int i = 0; i < n; ++i){
        s += s[i];
        index++;
      }
      return s.substr(index);

    }
};
