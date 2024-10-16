class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res = "";
        int counta = 0, countb = 0, countc = 0;
        int totalCount = a+b+c;
        while(totalCount)
        {
            if(a >= b && a >= c && counta != 2)
            {
                res += 'a';
                a--;
                counta += 1;   
                countb = 0;
                countc = 0;
            }
            else if(b >= a && b >= c && countb != 2)
            {
                res += 'b';
                b--;
                counta = 0;
                countb += 1;
                countc = 0;
            }
            else if(c >= a && c >= b && countc != 2)
            {
                res += 'c';
                c--;
                counta = 0;
                countb = 0;
                countc += 1;
            }
            else
            {
                if(((a >= b && a < c) || (a >= c && a < b)) && counta != 2 && a > 0)
                {
                    res += 'a';
                    a--;
                    counta += 1;   
                    countb = 0;
                    countc = 0;
                }
                else if(((b >= a && b < c) || (b >= c && b < a)) && countb != 2 && b > 0)
                {
                    res += 'b';
                    b--;
                    counta = 0;
                    countb += 1;
                    countc = 0;
                }
                else if(countc != 2 && c > 0)
                {
                    res += 'c';
                    c--;
                    counta = 0;
                    countb = 0;
                    countc += 1;
                }
            }
            totalCount--;
        }
        return res;
    }
};