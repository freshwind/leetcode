// #include "stdlib.h"
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// class Algorithm {

// public:
//     int KMP(string main, string pattern) {
//         int *b = new int[pattern.size()+1];
//         b[0] = -1;
//         b[1] = 0;
//         for (int i = 2, j = 1; i <= pattern.size(); ++i, ++j) {
//             while(j>=0 && pattern[j-1] != pattern[i-1]) {
//                 j = b[j-1];
//             }
//             b[i] = j;
//         }
//     }
// };

int main() {
    vector<TreeNode *> test(2, NULL);
    return 1;
}