class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      map<int, int> mp;
      vector<int> res;

      for(int i = 0; i < nums.size(); ++i){
        if(mp.find(nums[i]) == mp.end()){
          int temp = target - nums[i];
          mp.insert(pair<int, int>(temp, i));
        }else{
          res.push_back(i);
          res.push_back(mp[nums[i]]);
          break;
        }
      }
      return res;
    }
};
