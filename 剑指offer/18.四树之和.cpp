class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      /*本题思路，采用四个指针，时间复杂度为O(N^3)，设置a = 0, b = a + 1, c = b+1, d = 最后一个值；然后再之前需要对数组进行排序。如果整个数组的大小就小于4的话，那么就可以返回空就行
      */
      vector<vector<int> > res;
      if(nums.size() < 4) return res;
      sort(nums.begin(), nums.end());
      for(int a = 0; a <= nums.size()-4; ++a){
        if(a > 0 && nums[a-1] == nums[a]) continue;
        for(int b = a+1; b <= nums.size()-3; ++b){
          if(b > a+1 && nums[b] == nums[b-1]) continue;
          int c = b+1, d = nums.size()-1;
          while(c < d){
            if(nums[a]+nums[b]+nums[c]+nums[d] < target){
              c++;
            }else if(nums[a]+nums[b]+nums[c]+nums[d] > target){
              d--;
            }else{
              res.push_back({nums[a], nums[b], nums[c], nums[d]});
              while(c < d && nums[c] == nums[c+1]) c++;
              while(c < d && nums[d] == nums[d-1]) d--;
              c++;
              d--;
            }
          }
        }
      }
      return res; 
    }
};
