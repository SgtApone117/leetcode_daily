class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto first_occ = word.find_first_of(ch);  
        if(first_occ != string::npos) 
        reverse(word.begin(),word.begin()+  first_occ + 1);
        return word;
    }
};