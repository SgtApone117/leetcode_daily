class Solution {
public:
    int getMsb_pos(int num)
    {
        int msb = -1;
        while(num)
        {
            num = num >> 1;
            msb++;
        }
        return msb;
    }
    int rangeBitwiseAnd(int left, int right) 
    {
        int res = 0, msb_num1, msb_num2;
        while(left && right)
        {
            msb_num1 = getMsb_pos(left);
            msb_num2 = getMsb_pos(right);
            if(msb_num1 != msb_num2)
                break;
            int msb_val = 1 << msb_num1;
            res = res + msb_val;
            left -= msb_val;
            right -= msb_val;
        }
        return res;
    }
};