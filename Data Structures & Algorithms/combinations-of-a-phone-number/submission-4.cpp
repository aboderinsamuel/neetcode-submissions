class Solution {
private:
    vector<string> digitToLetters = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
    };

    void backtrack(string& digits, int idx, string& current, vector<string>& result){
        if(idx == digits.size()){
            result.push_back(current);
            return;
        }
        int digit = digits[idx] - '0';
        string letters = digitToLetters[digit];

        for(char letter : letters){
            current.push_back(letter);
            backtrack(digits, idx+1, current, result);
            current.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string current = "";
        if(digits.empty()){
            return result;
        }
        backtrack(digits, 0, current, result);
        return result;
    }
};
