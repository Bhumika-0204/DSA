#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // 1. Sort meetings by start time
        sort(meetings.begin(), meetings.end());

        // Count of meetings per room
        vector<int> bookingCount(n, 0);

        // Min-heap for unused rooms (stores room index)
        priority_queue<int, vector<int>, greater<int>> unusedRooms;
        for (int i = 0; i < n; i++) unusedRooms.push(i);

        // Min-heap for engaged rooms (stores {endTime, roomIndex})
        // We use long long for endTime to prevent overflow
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> engagedRooms;

        for (auto& meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];
            long long duration = end - start;

            // 2. Free up rooms that finished before this meeting starts
            while (!engagedRooms.empty() && engagedRooms.top().first <= start) {
                unusedRooms.push(engagedRooms.top().second);
                engagedRooms.pop();
            }

            // 3. Allocate a room
            if (!unusedRooms.empty()) {
                // Room is available immediately
                int room = unusedRooms.top();
                unusedRooms.pop();
                bookingCount[room]++;
                engagedRooms.push({end, room});
            } else {
                // No room available, wait for the earliest one to finish
                auto [earliestEnd, room] = engagedRooms.top();
                engagedRooms.pop();
                bookingCount[room]++;
                // New end time is (earliest room free time + duration)
                engagedRooms.push({earliestEnd + duration, room});
            }
        }

        // 4. Find the room with the maximum bookings
        int maxBookings = -1;
        int resultRoom = 0;
        for (int i = 0; i < n; i++) {
            if (bookingCount[i] > maxBookings) {
                maxBookings = bookingCount[i];
                resultRoom = i;
            }
        }

        return resultRoom;
    }
};