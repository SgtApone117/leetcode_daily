class Solution {
public:
    void getWord(const vector<string>& keyBoard, vector<string> &result, int digitIdx, const string &digits, string &str)
    {
        if(digitIdx >= digits.length())
        {
            result.push_back(str);
            return;
        } 
        //cout << "Hello" << endl;
        // cout << keyBoard[(digits[digitIdx]-48)] << endl;
        string numbers = keyBoard[digits[digitIdx]-48];
        
        // int n = keyBoard[digits[digitIdx-48]].length();
        for(int i = 0; i < numbers.length(); i++)
        {
            str.push_back(numbers[i]);
            getWord(keyBoard, result, digitIdx+1, digits, str);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        //keyboard mapping to vector
        if(digits == "")
        {
            return {};
        }
        vector<string> result;
        vector<string> keyBoard = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
            };
        int n = digits.length();
        string str = "";
        getWord(keyBoard, result, 0, digits, str);
        return result;
    }
};