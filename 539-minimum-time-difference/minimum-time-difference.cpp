class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> timeInMinutes(n);

        for(int i = 0; i < n; i++)
        {
            string time = timePoints[i];
            string hourSubstr = time.substr(0, 2);
            string minSubstr = time.substr(3);

            int hourInt = stoi(hourSubstr);
            int minInt = stoi(minSubstr);

            cout << hourInt << " " << minInt << endl;

            timeInMinutes[i] = (60*hourInt)+minInt;
        }

        sort(begin(timeInMinutes), end(timeInMinutes));

        int result = INT_MAX;
        for(int i = 1; i < n; i++)
        {
            result = min(result, timeInMinutes[i]-timeInMinutes[i-1]);
            cout << result << endl;
        }
        cout << ((24*60-timeInMinutes[n-1])+timeInMinutes[0]);
        return min(result, ((24*60-timeInMinutes[n-1])+timeInMinutes[0]));
    }
};