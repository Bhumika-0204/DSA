class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for(char c : tasks) freq[c - 'A']++;

        int maxFreq = 0, countMax = 0;
        for(int i = 0; i < 26; i++)
            maxFreq = max(maxFreq, freq[i]);

        for(int i = 0; i < 26; i++)
            if(freq[i] == maxFreq)
                countMax++;

        int frames = maxFreq - 1;
        int slotsPerFrame = n - (countMax - 1);
        int emptySlots = frames * slotsPerFrame;
        int remaining = tasks.size() - maxFreq * countMax;

        int idle = max(0, emptySlots - remaining);
        return tasks.size() + idle;
    }
};
