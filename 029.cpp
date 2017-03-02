class Solution {
public:
    int divide(int dividend, int divisor) {
        assert(divisor);
        if(0 == dividend)
            return 0;
        int flag = 0;
        if(dividend > 0 && divisor < 0)
            flag = 1;
        if(dividend < 0 && divisor > 0)
            flag = 1;

        long long ret = 0;
        long long ddividend = abs(1LL * dividend);
        long long ddivisor = abs(1LL * divisor);
        while(ddividend >= ddivisor) {
            long long tmpdividend = ddividend;
            int c = -1;
            while(tmpdividend >= ddivisor) {
                tmpdividend >>= 1;
                c++;
            }
            ret |= (1LL << c);
            ddividend -= ddivisor << c;
        }
        if(flag)
            ret = -ret;
        const long long limit = (1LL << 31);
        if(ret >= -limit && ret < limit)
            return ret;
        return limit - 1;
    }
};