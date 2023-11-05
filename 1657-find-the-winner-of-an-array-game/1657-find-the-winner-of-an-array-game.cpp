class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int max_ele = *max_element(begin(arr),end(arr));
        if(k >= n)
        {
            return max_ele;
        }

        int winner = arr[0];
        int streak = 0;
        for(int i = 1; i < n; i++)
        {
            if(arr[i] > winner)
            {
                streak = 1;
                winner = arr[i];
            }
            else
            {
                streak++;
            }
            if(streak == k || winner == max_ele)
            {
                return winner;
            }
        }
        return winner;
    }
};