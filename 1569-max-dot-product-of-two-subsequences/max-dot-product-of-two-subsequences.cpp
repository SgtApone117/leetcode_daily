class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) 
    {
        int arr[505][505];
        int maxi = INT_MIN;
        for(int i = 0; i <= 501; i++)
            arr[0][i] = INT_MIN;
        for(int i = 1; i <= nums1.size(); i++)
        {
            for(int j = 1; j <= nums2.size(); j++)
            {
                if(i == 1)
                {
                    arr[j][i] = max(arr[j-1][i], nums1[i-1]*nums2[j-1]);
                    maxi = max(arr[j][i], maxi);
                }
                else if(j == 1)
                {
                    arr[j][i] = max(arr[j][i-1], nums1[i-1]*nums2[j-1]);
                    maxi = max(arr[j][i], maxi);
                }
                else
                {
                    arr[j][i] = max({arr[j-1][i],arr[j][i-1],nums1[i-1]*nums2[j-1], arr[j-1][i-1],nums1[i-1]*nums2[j-1] + arr[j-1][i-1]});
                    maxi = max(maxi, arr[j][i]);
                }
            }
        }
        return maxi;
    }
};