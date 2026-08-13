class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;

        while(left < right){
            if(left < right && !isalnum(s[left])){
                left++;
            }else if(left < right && !isalnum(s[right])){
                right--;
            }else if(tolower(s[left]) != tolower(s[right])){
                return false;
            }else{
                left++;
                right--;
            }
        }
        return true;
    }
};
