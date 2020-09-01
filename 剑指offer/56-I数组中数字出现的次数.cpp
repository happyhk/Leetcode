//这道题太巧妙了，很难想到啊，只能背下来了。
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
      int s = 0;
      for(auto num:nums){
        s ^= num;
      }
      int k = s & (-s);
      vector<int> res(2, 0);
      for(auto p:nums){
        if(p&k) {
          res[0] ^= p;
        }else {
          res[1] ^= p;
        }
      }
      return res;
    }
};
