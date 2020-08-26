class Solution {
public:
    int reverse(long int x) {
      int flag = 1;
      if(x < 0) {
        x = -x;
        flag = -1;
      }

      int res = 0;
      while(x != 0){
        if(res > INT_MAX/10) return 0;
        if(res < INT_MIN/10) return 0;
        res *= 10;
        res += x%10;
        x = x/10;
      }
      return flag > 0 ? res: -res;
        
    }
};
