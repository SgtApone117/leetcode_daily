class Solution {
public:

    int countSetBits(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        else
        {
            return (n & 1) + countSetBits(n >> 1);
        }
    }

    bool merge(vector<int>& nums, int low, int high, int mid)
    {
        vector<int> aux;
        int i, j;
        i = low, j = mid+1;
        while(i <= mid && j <= high)
        {
            if(nums[i] <= nums[j])
            {
                aux.push_back(nums[i]);
                i++;
            }
            else
            {
                for(int start = i; start <= mid; start++)
                {
                    int left_bit  = countSetBits (nums[start]);
                    int right_bit = countSetBits (nums[j]);
                    if(left_bit != right_bit)
                    {
                        return false;
                    }
                }
                aux.push_back(nums[j]);
                j++;
            }
        }

        for(; i <= mid; i++)
        {
            aux.push_back(nums[i]);
        }
        for(; j <= high; j++)
        {
            aux.push_back(nums[j]);
        }
        for(int x = low; x <= high; x++)
        {
            nums[x] = aux[x-low];
        }
        return true;
    }

    bool mergeSort(vector<int>& nums, int low, int high)
    {
        if(low == high)
        {
            return true;
        }
            
        int mid = low+(high-low)/2;
        if(!mergeSort(nums, low, mid))
        {
            return false;
        }
        if(!mergeSort(nums, mid+1, high))
        {
            return false;
        }
        return merge(nums,low,high,mid);
    }

    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        bool res = mergeSort(nums, 0, n-1);
        return res;
    }
};