class Solution {
public:
    bool hasDuplicate(string str1, string str2)
    {
        int arr[26] = {0};
        for(char &ch : str1)
        {
            if(arr[ch - 'a'] > 0)
            {
                return true;
            }
            arr[ch-'a']++;
        }
        for(char &ch : str2)
        {
            if(arr[ch - 'a'] > 0)
            {
                return true;
            }
        }
        return false;
    }
    int solve(int counter, string temp_var, vector<string>& arr, int size)
    {
        if(counter >= size)
        {
            return temp_var.length();
        }

        int include = 0;
        int exclude = 0;

        if(hasDuplicate(arr[counter], temp_var))
        {
            //exclude
            exclude = solve(counter+1, temp_var, arr, size);
        }
        else
        {
            exclude = solve(counter+1, temp_var, arr, size);
            include = solve(counter+1, temp_var + arr[counter], arr, size);
        }
        return max(include, exclude);
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();

        string temp = "";
        int i = 0;
        return solve(i, temp, arr, n);
    }
};