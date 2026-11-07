class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> idle;

        for (int i = 0; i < (int)servers.size(); i++) {
            idle.push({servers[i], i});
        }

        long long ts = 0;
        vector<int> ans(tasks.size());

        auto release = [&](long long time) {
            while (!busy.empty() && busy.top().first <= time) {
                int idx = busy.top().second;
                busy.pop();
                idle.push({servers[idx], idx});
            }
        };

        for (int i = 0; i < (int)tasks.size(); i++) {
            ts = max(ts, (long long)i);
            release(ts);
            if (idle.empty()) {
                ts = busy.top().first;
                release(ts);
            }

            int idx = idle.top().second;
            idle.pop();
            ans[i] = idx;
            busy.push({ts + tasks[i], idx});
        }

        return ans;
    }
};