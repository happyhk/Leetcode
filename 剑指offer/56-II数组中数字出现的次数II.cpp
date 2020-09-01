class Solution {
public:
    int singleNumber(vector<int>& nums) {
      unordered_map<int, int> mp;
      for(auto n:nums) mp[n]++;
      int res = 0;
      for(auto p: mp){
        if(p.second == 1){
          res = p.first;
          break;
        }
      }
      return res;

    }
};
