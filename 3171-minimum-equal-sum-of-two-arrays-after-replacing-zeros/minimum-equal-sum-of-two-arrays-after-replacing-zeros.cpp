class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1 = (int)nums1.size();   
        int n2 = (int)nums2.size();
        long long sum1 = 0, sum2 = 0;
        int counter_arr1 = 0, counter_arr2 = 0;
        for(int i = 0; i < n1; i++)
        {
            sum1 += nums1[i];
            if(nums1[i] == 0)
            {
                sum1++;
                counter_arr1++;
            }
        }
        
        for(int i = 0; i < n2; i++)
        {
            sum2 += nums2[i];
            if(nums2[i] == 0)
            {
                sum2++;
                counter_arr2++;
            }
        }
        if(sum1 == sum2)
        {
            return sum1;
        }
        else if((0 == counter_arr1 && sum1 < sum2) || (0 == counter_arr2 && sum2 < sum1))
        {
            return -1;
        }
        else
        {
            return max(sum1,sum2);
        }
        return -1;
    }
    
};