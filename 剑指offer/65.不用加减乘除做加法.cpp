/*
不用加减乘除做加法，按理说只能按照位运算了。

*/
class Solution {
public:
    int add(int a, int b) {
        while(b != 0){
            int c = (unsigned int)(a&b)<<1;
            a = a^b;
            b = c;
        }
        return a;
    }
};
