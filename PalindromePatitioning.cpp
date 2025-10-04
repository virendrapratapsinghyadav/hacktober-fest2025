class Solution {


public:
    bool isPalindrome(const string& s, int left, int right) {
        while (left <=right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }   

public:
    void partition(int index, vector<string>& temp, vector<vector<string>>& result, string& s){

        //base case
        if(index==s.length()){
            result.push_back(temp);
            return;
        }

        for(int i=index; i<s.length(); i++){
            if(isPalindrome(s, index, i)){
                temp.push_back(s.substr(index, i-index+1));
                partition(i+1, temp, result, s);
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string>temp;
        partition(0, temp, result, s);
        return result;
    }
};
