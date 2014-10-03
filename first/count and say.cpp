class Solution {
public:
    string countAndSay(int n) {
        string old_string, new_string;
        if (n == 0) {
            return "";
        }
        old_string = "1";
        for (int i = 1; i != n; ++i) {
            int old_probe = old_string[0];
            int probe_index = 1;
            int number = 1;
            while (probe_index < old_string.size()) {
                if (old_probe == old_string[probe_index]) {
                    number++;
                } else {
                    //add to new
                    new_string.push_back('0'+number);
                    new_string.push_back(old_probe);
                    //initialize old_probe, number
                    old_probe = old_string[probe_index];
                    number = 1;
                }
                probe_index++;
            }
            new_string.push_back('0'+number);
            new_string.push_back(old_probe);
            old_string = new_string;
            new_string = "";
        }
        return old_string;
    }
};