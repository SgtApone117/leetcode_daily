class Solution {
public:
    typedef pair<int,char> P;
    string longestDiverseString(int a, int b, int c) {
        priority_queue<P, vector<P>> pq;
        if(a > 0)
        {
            pq.push({a, 'a'});
        }
        if(b > 0)
        {
            pq.push({b, 'b'});
        }
        if(c > 0)
        {
            pq.push({c, 'c'});
        }

        string res = "";

        while(!pq.empty())
        {
            int maxCharFreq = pq.top().first;
            char CharVal = pq.top().second;
            pq.pop();
            if(res.length() >= 2 && res[res.length()-1] == CharVal && res[res.length()-2] == CharVal)
            {
                if(pq.empty()) break;
                int second_max_char_freq = pq.top().first;
                int second_char_val = pq.top().second;
                pq.pop();
                res.push_back(second_char_val);
                second_max_char_freq--;
                if(second_max_char_freq > 0)
                    pq.push({second_max_char_freq, second_char_val});
            }
            else
            {
                res.push_back(CharVal);
                maxCharFreq--;
            }
            if(maxCharFreq > 0)
                pq.push({maxCharFreq, CharVal});
        }
        return res;
    }
};