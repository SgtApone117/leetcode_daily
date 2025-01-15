class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int num_2_st_bts = __builtin_popcount(num2);
        int min_xor = INT_MAX;
        int min_val = 0;
        int num_1_st_bts = __builtin_popcount(num1);
        if(num_1_st_bts == num_2_st_bts) return num1;
        while(num_1_st_bts > num_2_st_bts)
        {
            num1 = (num1&(num1-1));  
            num_1_st_bts--;
            //num_1_st_bts = __builtin_popcount(x);
        }
        while(num_1_st_bts < num_2_st_bts)
        {
            num1 = (num1|(num1+1));  
            num_1_st_bts++;
            //num_1_st_bts = __builtin_popcount(x);
        }
        // if(num_1_st_bts == num_2_st_bts)
        // {
        //     return num1;
        // }
        // else if(num_1_st_bts > num_2_st_bts)
        // {
        //     return (num1&(num1-1));
        // }
        // else
        // {
        //     return (num1|(num1+1));
        // }
        return num1;
    }
};