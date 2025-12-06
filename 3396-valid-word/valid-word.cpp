class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }

    bool isValid(string s) {
        if (s.length() < 3) return false;

        bool hasVowel = false, hasConsonant = false;

        for (char c : s) {

            if (!isalnum(c)) return false;

            if (isalpha(c)) {
                if (isVowel(c)) hasVowel = true;
                else hasConsonant = true;
            }
        }

        return hasVowel && hasConsonant;
    }
};
