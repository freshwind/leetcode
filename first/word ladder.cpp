class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> visited;
        vector<string> ladder;
        vector<string> next_ladder;
        ladder.push_back(start);
        string temp;
        int len = 1;
        unordered_set<string>::const_iterator got;
        while (!ladder.empty()) {
            for (int i = 0; i < ladder.size(); ++i) {
                if (ladder[i] == end) {
                    return len;
                }
                temp = ladder[i];
                got = visited.find(temp);
                if (got == visited.end()) {
                    // cout <<temp <<endl;
                    visited.insert(temp);
                    for (int j = 0; j < temp.size(); ++j) {
                        for (char k = 'a'; k <='z'; ++k) {
                            temp = ladder[i];
                            if (k != temp[j]) {
                                temp[j] = k;
                                got = dict.find(temp);
                                if (got != dict.end()) {
                                    // cout <<*got <<"," <<k <<"," <<temp <<endl;
                                    next_ladder.push_back(*got);
                                }
                            }
                        }
                    }
                }
            }
            len++;
            ladder = next_ladder;
            next_ladder.clear();
        }
        return 0;
    }
};