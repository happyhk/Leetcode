/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        if(s.size() == 0) return max_len;
        int begin = 0;
        int end = 0;
        int cur_max = 0;
        while(begin < s.size()){
            for(int index = end; index < begin; index++){
                if(s[index] == s[begin]){
                    end = index + 1;
                    cur_max = begin - end;
                    break;
                }     
            }
            begin++;
            cur_max++;
            max_len = max(max_len, cur_max);
        }
        return max_len;
    }
};
// @lc code=end

