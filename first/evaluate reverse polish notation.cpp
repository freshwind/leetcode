class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        vector<int> stack;
        int op1;
        int op2;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+") {
                op1 = stack.back();
                stack.pop_back();
                op2 = stack.back();
                stack.pop_back();
                stack.push_back(op1+op2);
            } else if (tokens[i] == "-") {
                op1 = stack.back();
                stack.pop_back();
                op2 = stack.back();
                stack.pop_back();
                stack.push_back(op2-op1);
            } else if (tokens[i] == "*") {
                op1 = stack.back();
                stack.pop_back();
                op2 = stack.back();
                stack.pop_back();
                stack.push_back(op1*op2);
            } else if (tokens[i] == "/") {
                op1 = stack.back();
                stack.pop_back();
                op2 = stack.back();
                stack.pop_back();
                stack.push_back(op2/op1);
            } else {
                stack.push_back(stoi(tokens[i]));
            }
        }
        return stack[0];
    }
};