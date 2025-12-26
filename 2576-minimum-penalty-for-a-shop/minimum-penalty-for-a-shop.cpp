class Solution {
public:
    int bestClosingTime(string customers) {
        int totalY = 0;
        for (char c : customers) {
            if (c == 'Y') totalY++;
        }

        int currPenalty = totalY;   // closing at hour 0
        int minPenalty = totalY;
        int bestHour = 0;

        for (int i = 0; i < customers.size(); i++) {
            if (customers[i] == 'Y')
                currPenalty--;   // one less missed customer
            else
                currPenalty++;   // one extra idle hour

            if (currPenalty < minPenalty) {
                minPenalty = currPenalty;
                bestHour = i + 1;
            }
        }

        return bestHour;
    }
};
