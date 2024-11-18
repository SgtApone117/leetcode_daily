class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);
        vector<int> sum_arr(n);
        if(k == 0)
        {
            return res;
        }
        else if(k > 0)
        {
            int count = 0;
            for(int i = 1; i <= k; i++)
            {
                count += code[i];
            }
            res[0] = count;
            for(int i = 1; i < n; i++)
            {
                count = res[i-1]-code[i]+code[(i+k)%n];
                res[i] = count;
            }
        }
        else
        {
            int count = 0;
            for(int i = n-1; i >= n+k; --i)
            {
                count += code[i];
            }
            res[0] = count;
            for(int i = 1; i < n; i++)
            {
                res[i] = res[i-1]+code[i-1]-code[((n+i-abs(k)-1)%(n))];
            }
        }
        return res;
    }
};