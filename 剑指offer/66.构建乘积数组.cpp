/*
    这是个动态规划的问题，很难想到是因为需要人为建立dp数组，用来保存状态值。
*/
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int len = a.size();
        vector<int> res(len, 1);
        if(len <= 1) return res;
        int temp = 1;
        for(int i = 1; i < len; ++i){
            res[i]  = res[i-1] * a[i-1];
        }
        for(int i = a.size()-2; i >= 0; i--){
            temp *= a[i+1];
            res[i] *= temp;
        }
        return res;
    }
};
