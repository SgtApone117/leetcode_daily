class Solution {
public:
// 25 64 9 4 100
/*
    25 64 9 4 10 10
    25 8 9 4 10 18
    5 8 9 4 10 22
    5 8 9 4 3 25
*/
    long long pickGifts(vector<int>& gifts, int k) {
        //sort(begin(gifts), end(gifts), greater<int>());
        long long sum = 0;
        priority_queue<int> pq;
        for(int& gift : gifts)
        {
            pq.push(gift);
        }

        while(!pq.empty() && k > 0)
        {
            pq.push(sqrt(pq.top()));
            pq.pop();
            k--;
        }

        while(!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};