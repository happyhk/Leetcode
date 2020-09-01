class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      vector<int> res;
      if(nums.size() < k || k <= 0)
      return res;
      for(int i = 0; i <= nums.size()-k;i++)
      {
        int curmax = INT_MIN;
        for(int j = i;j < i+k;j++)
        {
          curmax = max(curmax,nums[j]);
        }
        res.push_back(curmax);
      }
      return res;
    }
};
