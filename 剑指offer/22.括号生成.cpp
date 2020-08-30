class Solution {
public:
    vector<string> generateParenthesis(int n) {
      int lc = 0, rc = 0;
      vector<string> res;
      helper(res, "", lc, rc, n);
      return res;        
    }
    void helper(vector<string>& res, string path, int lc, int rc, int n){
      if(lc > n || rc > n || rc > lc) return;
      if(lc == rc && lc == n){
        res.push_back(path);
        return;
      }
      helper(res, path + '(', lc+1, rc, n);
      helper(res, path + ')', lc, rc+1, n);
    }
};
