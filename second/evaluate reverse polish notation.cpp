class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> pool;
        int op1, op2;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+") {
                topTwo(op1, op2, pool);
                pool.push(op1+op2);
            } else if (tokens[i] == "-") {
                topTwo(op1, op2, pool);
                pool.push(op1-op2);
            } else if (tokens[i] == "*") {
                topTwo(op1, op2, pool);
                pool.push(op1*op2);
            } else if (tokens[i] == "/") {
                topTwo(op1, op2, pool);
                pool.push(op1/op2);
            } else {
                pool.push(stoi(tokens[i]));
            }
        }
        return pool.top();
    }

private:
    void topTwo(int &op1, int &op2, stack<int> &pool) {
        op2 = pool.top();
        pool.pop();
        op1 = pool.top();
        pool.pop();
    }
};
