class Solution {
public:
    int findComplement(int num) {
        int x = num; 
        x |= x >> 1;
        x |= x >> 2;
        x |= x >> 4;
        x |= x >> 6;
        x |= x >> 8;
        x |= x >> 12;
        return (x^num);
    }
};