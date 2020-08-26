class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      if(nums.size() == 1) return nums[0];
      int maxTemp = nums[0];
      int MAX = nums[0];
      for(int i = 1; i < nums.size(); ++i){
        maxTemp = max(maxTemp+nums[i], nums[i]);
        MAX = max(maxTemp, MAX);
      }
      return MAX;
        
    }
};
