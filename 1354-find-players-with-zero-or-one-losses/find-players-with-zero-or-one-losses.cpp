class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> lost_map;

        int n = matches.size();

        for(int i = 0; i < n; i++)
        {
            int lost = matches[i][1];
            lost_map[lost]++;
        }
        vector<int> notLost;
        vector<int> lostOnce;

        for(int i = 0; i < n; i++)
        {
            int loser = matches[i][1];
            int winner = matches[i][0];

            if(lost_map.find(winner) == lost_map.end())
            {
                notLost.push_back(winner);
                lost_map[winner] = 2;
            }

            if(1 == lost_map[loser])
            {
                lostOnce.push_back(loser);
            }
        }
        sort(begin(lostOnce), end(lostOnce));
        sort(begin(notLost), end(notLost));
        return {notLost, lostOnce};
    }
};