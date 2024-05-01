class Solution {
public:
    string reversePrefix(string word, char ch) {
        int find_idx = -1;
        int swap_idx = 0;
        for(int i = 0; i < word.length(); i++)
        {
            if(ch == word[i])
            {
                find_idx = i;
                break;
            }
                
        }
        if(find_idx == -1)
            return word;
        while(find_idx > swap_idx)
        {
            char temp = word[find_idx];
            word[find_idx] = word[swap_idx];
            word[swap_idx] = temp;
            find_idx--;
            swap_idx++;
        }
        return word;
    }
};