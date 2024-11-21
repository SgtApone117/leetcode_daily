class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k == 0)
        {
            return 0;
        }
        int n = s.length();
        int freq[3] = {0};
        for(char ch : s)
        {
            freq[ch-'a']++;
        }

        for(int val : freq)
        {
            if(val < k)
            {
                return -1;
            }
        }

        int left;
        left = 0;
        int max_length = 0;
        int right = 0;
        while(right < n)
        {
            freq[s[right]-'a']--;

            while(left <= right && (freq[0] < k || freq[1] < k || freq[2] < k))
            {
                freq[s[left]-'a']++;
                left++;
            }
            max_length = max(max_length, right-left+1);
            right++;
        }
        return n-max_length;
    }
};