#include <iostream>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i){
            map[target - nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(map[nums[i]] && map[nums[i]] != i){
                ans.push_back(i);
                ans.push_back(map[nums[i]]);
                return ans;
            }
        }
        return ans;
    }
};

