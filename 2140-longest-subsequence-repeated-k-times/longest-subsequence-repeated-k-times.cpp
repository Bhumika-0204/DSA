class Solution 
{
public:
    string longestSubsequenceRepeatedK(string s, int K) 
    {
        int n = s.size();
        vector<vector<int>> nextPos(n + 2, vector<int>(26, n));

        for (int c = 0; c < 26; ++c) 
        {
            nextPos[n][c] = nextPos[n + 1][c] = n;
        }

        for (int i = n - 1; i >= 0; --i) 
        {
            for (int c = 0; c < 26; ++c) 
            {
                nextPos[i][c] = nextPos[i + 1][c];
            }
            nextPos[i][s[i] - 'a'] = i;
        }

        int low = 1;
        int high = n / K;
        string res = "";

        while (low <= high) 
        {
            int mid = (low + high) / 2;

            string candidate = dfsTry(mid, K, 0, string(mid, ' '), s, nextPos);
            if (!candidate.empty()) 
            {
                res = candidate;
                low = mid + 1;
            } 
            else 
            {
                high = mid - 1;
            }
        }

        return res;
    }

    string dfsTry(int len, int K, int idx, string path, const string& s, const vector<vector<int>>& nextPos) 
    {
        if (idx == len) 
        {
            return canExtend(path, len, s, nextPos, K) ? path : "";
        }

        for (int c = 25; c >= 0; --c) 
        {
            path[idx] = 'a' + c;

            if (canExtend(path, idx + 1, s, nextPos, K)) 
            {
                string sub = dfsTry(len, K, idx + 1, path, s, nextPos);
                if (!sub.empty())
                {
                    return sub;
                } 
            }
        }

        return "";
    }

    bool canExtend(const string& path, int d, const string& s, const vector<vector<int>>& nextPos, int K) 
    {
        int pos = 0;
        int n = s.size();

        for (int rep = 0; rep < K; ++rep) 
        {
            for (int i = 0; i < d; ++i) 
            {
                int c = path[i] - 'a';
                if (pos >= n)
                {
                    return false;
                }

                pos = nextPos[pos][c];
                if (pos == n)
                {
                    return false;
                } 

                ++pos;
            }
        }

        return true;
    }
};