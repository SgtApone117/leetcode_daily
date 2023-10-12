/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    int returnPeak(MountainArray &arr)
    {
        int n = arr.length();
        int res = -1;
        int l = 0, r = n - 1;
        while(l < r)
        {
            int mid = l + (r-l)/2;
            if(arr.get(mid) < arr.get(mid+1))
            {
                l = mid + 1;
                res = mid+1;
            }
            else
                r = mid;
        }
        return res;
    }

    int binarySearch(MountainArray arr, int target, int arr_size, int l, int r, int flag)
    {
        int res = -1;
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(arr.get(mid) == target)
            {
                res = mid;
                if(flag)
                {
                    l = mid+1;
                }
                else
                {
                    r = mid-1;
                }
            }
            else if(target < arr.get(mid))
            {
                if(flag)
                {
                    l = mid+1;
                }
                else
                {
                    r = mid-1;
                }
            }
            else
            {
                if(flag)
                {
                    r = mid-1;
                }
                else
                {
                    l = mid+1;
                }
            }
        }
        return res;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) 
    {
        int peak = returnPeak(mountainArr);
        int n = mountainArr.length();
        if(n < 3) return -1;
        int left = binarySearch(mountainArr, target, n, 0, peak, 0);
        if(left != -1) return left;

        int right = binarySearch(mountainArr, target, n, peak, n-1, 1);
        return right;
    }
};