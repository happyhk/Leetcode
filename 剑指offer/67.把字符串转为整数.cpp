class Solution {
public:
    int strToInt(string str) {
        if(str.size() == 0) return 0;
        int i = 0;
        while(str[i] == ' ') i++;
        int flag = 1;
        if(str[i] == '-') flag = -1;
        if(str[i] == '-' || str[i] == '+') i++;
        int res = 0;
        while(i != str.size() && isdigit(str[i])){
            int temp = str[i] - '0';
            if((res > INT_MAX/10) || (res == INT_MAX/10 && temp > 7)){
                return flag > 0 ? INT_MAX:INT_MIN;
            }
            res = res * 10 + temp;
            i++;
        }
        return flag > 0 ? res : -res;

    }
};
