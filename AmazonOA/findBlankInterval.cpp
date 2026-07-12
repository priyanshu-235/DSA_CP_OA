#include <bits/stdc++.h>
using namespace std;

int toMinutes(const string &t) {
    int h = stoi(t.substr(0, 2));
    int m = stoi(t.substr(3, 2));
    return h * 60 + m;
}

string toTimeStr(int m) {
    int h = m / 60;
    int mm = m % 60;
    char buf[6];
    sprintf(buf, "%02d:%02d", h, mm);
    return string(buf);
}

string getEarliestMeetTime(vector<string> &events, int k) {
    vector<int> busy(1441, 0); // difference array

    // mark busy intervals
    for (auto &e : events) {
        stringstream ss(e);
        string name, action, start, end; // this is how you take stream of characters.
        ss >> name >> action >> start >> end;
        int s = toMinutes(start);
        int en = toMinutes(end);
        busy[s] += 1;
        if (en + 1 <= 1440) busy[en + 1] -= 1;
    }

    // prefix sum to get actual busy status
    for (int i = 1; i <= 1440; i++) {
        busy[i] += busy[i - 1];
    }

    // scan for earliest free slot of length k
    int freeCount = 0;
    for (int i = 0; i < 1440; i++) {
        if (busy[i] == 0) {
            freeCount++;
        } else {
            freeCount = 0;
        }
        if (freeCount == k) {
            return toTimeStr(i - k + 1);
        }
    }

    return "-1";
}

int main() {
    vector<string> events = {
        "Alex sleep 00:00 08:00",
        "Sam sleep 07:00 13:00",
        "Alex lunch 12:30 13:59"
    };
    int k = 60;
    cout << getEarliestMeetTime(events, k) << endl; // Output: 14:00
    return 0;
}
