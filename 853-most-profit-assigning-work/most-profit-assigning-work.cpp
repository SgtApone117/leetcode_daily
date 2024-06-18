class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> jobProfile;
        jobProfile.push_back({0, 0});
        int n = difficulty.size();

        for(int i = 0; i < n; i++)
        {
            jobProfile.push_back({difficulty[i], profit[i]});
        }

        sort(begin(jobProfile), end(jobProfile));

        for(int i = 0; i < n - 1; i++)
        {
            jobProfile[i + 1].second = max(jobProfile[i].second, jobProfile[i + 1].second);
        }

        int totalProfit = 0;
        int m = worker.size();
        for(int i = 0; i < m; i++)
        {
            int workDuration = worker[i];

            int low = 0, high = jobProfile.size() - 1, perJobProfit = 0;
            while(low <= high)
            {
                int mid = (low+high)/2;
                if(jobProfile[mid].first <= workDuration)
                {
                    perJobProfit = max(perJobProfit, jobProfile[mid].second);
                    low = mid + 1; 
                }
                else
                {
                    high = mid - 1;
                }
                
            }
            totalProfit += perJobProfit;
        }
        return totalProfit;
    }
};