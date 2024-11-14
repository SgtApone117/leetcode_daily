class Solution {
private:
    bool canDistribute(int mid, vector<int>&quantities, int shops)
    {
        for(int &products : quantities)
        {
            shops -= (products+mid-1)/mid;
            if(shops < 0)
            {
                return false;
            }
        }
        return true;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();

        int l = 1;
        int r = *max_element(begin(quantities), end(quantities));

        int result = 0;

        while(l <= r)
        {
            int mid = (l+r) >> 1;
            if(canDistribute(mid, quantities, n))
            {
                result = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return result;
    }
};