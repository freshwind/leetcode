class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        for (int i = 0; i < path.size(); ++i) {
            // print(stack);
            if (path[i] == '/') {
                ++i;
                while (i<path.size() && path[i] == '/') {
                    ++i;
                }
                --i;
            } else {
                int j = i+1;
                for (; j < path.size() && path[j] != '/'; ++j) {

                }
                // cout <<path.substr(i, j-i) <<endl;
                if (path.compare(i, j-i, "..")==0) {
                    if (!stack.empty()) {
                        stack.pop_back();
                    }
                } else if (path.compare(i, j-i, ".")==0) {

                } else {
                    stack.push_back(path.substr(i, j-i));
                }
                i = j;
            }
        }
        string result;
        for (int i = 0; i < stack.size(); ++i) {
            result.append("/");
            result.append(stack[i]);
        }
        if (result.empty()) {
            result.append("/");
        }
        return result;
    }
};