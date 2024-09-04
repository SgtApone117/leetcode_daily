class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        cin.tie(NULL);
        ios::sync_with_stdio(false);
        unordered_set<string> st;
        for(vector<int>& obstacle : obstacles)
        {
            string key = to_string(obstacle[0]) + "_" + to_string(obstacle[1]);
            st.insert(key);
        }

        // starting robot location
        int x = 0;
        int y = 0;
        //Initial maximum distance
        int maxDist = 0;

        // initial direction - North
        pair<int,int> dir{0,1};

        for(int i = 0; i < commands.size(); i++)
        {
            if(-2 == commands[i])
            {
                dir = {-dir.second, dir.first};
            }
            else if(-1 == commands[i])
            {
                dir = {dir.second, -dir.first};
            }
            else
            {
                for(int step = 0; step < commands[i]; step++)
                {
                    int newX = x + dir.first;
                    int newY = y + dir.second;

                    string newKey = to_string(newX) + "_" + to_string(newY);
                    if(st.find(newKey) != st.end())
                    {
                        break;
                    }
                    x = newX;
                    y = newY;
                }
            }
            maxDist = max(maxDist, x*x+y*y);
        }

        return maxDist;
    }
};