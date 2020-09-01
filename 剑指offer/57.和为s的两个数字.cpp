class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       //双指针
       vector<int> res;
       int left = 0;
       int right = nums.size()-1;
       while(left < right)
       {
         if(nums[left]+nums[right] < target)
         left++;
         else if(nums[left]+nums[right] > target)
         right--;
         else
         break;
       }
       res.push_back(nums[left]);
       res.push_back(nums[right]);
       return res;
    }
};
