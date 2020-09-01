class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
      //可能连续的序列都是滑动窗口的题目
      vector<vector<int>> res;
      vector<int> layer;
      int l = 1, r = 1;
      while(l <= r && r < target){
        if(sumTarget(l,r) == target) {
          layer = getArr(l,r);
          res.push_back(layer);
          l++;
          r++;
        }
        else if(sumTarget(l,r) < target){
          r++;
        }else {
          l++;
        }
      }
      return res;

    }

    int sumTarget(int l, int r){
      int sum = 0;
      for(int i = l; i <= r; ++i) sum += i;
      return sum;
    }

    vector<int> getArr(int l, int r){
      vector<int> ans;
      for(int i = l; i <= r; ++i)
      ans.push_back(i);
      return ans;
    }
};
