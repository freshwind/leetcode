class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string fold;
        for (int i = 0; i < path.size();) {
            if (path[i] == '/') {
                while(++i < path.size() && path[i] == '/');
                while(i < path.size() && path[i] != '/') {
                    fold.push_back(path[i++]);
                }
                if (fold.empty()) {
                    break;
                } else if (fold == "..") {
                    if (!stack.empty()) stack.pop_back();
                } else if (fold != ".") {
                    stack.push_back(fold);
                }
                fold.clear();
            }
        }
        string result;
        for (int i = 0; i < stack.size(); ++i) {
            result = result + "/" + stack[i];
        }
        if (stack.empty()) {
            return "/";
        }
        return result;
    }
};
