class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count_5 = 0, count_10 = 0;
        for(int& bill : bills)
        {
            switch(bill)
            {
                case 5:
                    count_5++;
                    break;
                case 10:
                    if(count_5)
                    {
                        count_5--;
                        count_10++;
                        break;
                    }
                    return false;
                case 20:
                    if(count_5 && count_10)
                    {
                        count_5--;
                        count_10--;
                        break;
                    }
                    if(count_5 >= 3)
                    {
                        count_5 -= 3;
                        break;
                    }
                    return false;
            }
        }
        return true;
    }
};