class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        for(int i = 0; i < 4; ++i){
            if(nums[i] == 0) {
                count++;
                continue;
            }
            if(nums[i] == nums[i+1]) return false;
            count -= nums[i+1] - nums[i] - 1;
        }
        return count >= 0;
    }
};
