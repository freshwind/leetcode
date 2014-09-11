#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <queue>
#include <list>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

template<class T>
vector<vector<T> > constructMatrix(T *m, int width, int height) {
    vector<vector<T> > results;
    vector<T> temp;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            temp.push_back(*(m+i*width+j));
        }
        results.push_back(temp);
        temp.clear();
    }
    return results;
}

bool cmp(const Interval &a,const Interval &b){
    return a.start<b.start;
}

vector<vector<char> > convert(vector<string> &data) {
    vector<vector<char> > results(data.size(), vector<char>{});
    for (int i = 0; i < data.size(); ++i) {
        for (int j = 0; j < data[i].size(); ++j) {
            results[i].push_back(data[i][j]);
        }
    }
    return results;
}

ListNode * constructList(vector<int> nums) {
    if (nums.size() == 0) return NULL;
    ListNode *head = new ListNode(nums[0]);
    ListNode *probe = head;
    for(int i = 1; i < nums.size(); ++i) {
        probe->next = new ListNode(nums[i]);
        probe = probe->next;
    }
    return head;
}

void print (vector<Interval> intervals) {
    for (int i = 0; i < intervals.size(); ++i) {
        cout <<"[" <<intervals[i].start <<","
             <<intervals[i].end <<"]" << ", ";
    }
    cout <<endl;
}

vector<Interval> constructInterval(vector<int> nums) {
    Interval temp;
    vector<Interval> results;
    if (nums.size() % 2 != 0) {
        cout <<"Invalid numbers" <<endl;
        return results;
    }
    for (int i = 0; i < int(nums.size())-1; i+=2) {
        temp.start = nums[i];
        temp.end = nums[i+1];
        results.push_back(temp);
    }
    return results;
}

void print(ListNode *head) {
    if (head == NULL) {
        cout <<"{ }";
        return;
    }
    ListNode *probe = head;
    int size = 1;
    cout <<"{";
    while(probe->next != NULL) {
        size++;
        cout <<probe->val <<", ";
        probe = probe->next;
    }
    cout <<probe->val <<"}; Size = " <<size <<endl;
}

template<class T> void print(vector<vector<T> > data) {
    cout <<"{\n";
    for (int i = 0; i != data.size(); ++i) {
        if (data[i].size() == 0) {
            cout <<"{ }\n";
        } else {
            cout <<"{";
            int j = 0;
            for (; j < data[i].size()-1; ++j) {
                cout <<data[i][j] <<", ";
            }
            cout <<data[i][j] <<"}\n";
        }
    }
    cout <<"}" <<endl;
}

void print(bool b) {
    if (b) cout <<"true" <<endl;
    else cout <<"false" <<endl;
}
template<class T> void print(vector<T> data) {
    cout <<"s = " <<data.size() <<"; ";
    if (data.size() == 0) {
        cout <<"{ }\n";
    } else {
        cout <<"{";
        int i = 0;
        for (; i < data.size()-1; ++i) {
            cout <<data[i] <<", ";
        }
        cout <<data[i] <<"}\n";
    }
}

void subsetRecur(vector<int> &unique_numbers, vector<int> &appear_times,
                 int current, vector<int> result,
                 vector<vector<int> > &results) {
    if (current == unique_numbers.size()) {
        results.push_back(result);
    } else {
        subsetRecur(unique_numbers, appear_times, current+1, result, results);
        for (int i = 0; i != appear_times[current]; ++i) {
            result.push_back(unique_numbers[current]);
            subsetRecur(unique_numbers, appear_times, current+1, result,
                        results);
        }
    }
}

vector<vector<int> > subsetsWithDup(vector<int> &S) {
    vector<vector<int> > results;
    vector<int> result;
    if (S.size() == 0) {
        return results;
    }
    sort(S.begin(), S.end());
    vector<int> unique_numbers;
    vector<int> appear_times;
    unique_numbers.push_back(S[0]);
    appear_times.push_back(1);
    int probe = 0;
    for (int i = 1; i != S.size(); ++i) {
        if (S[i] == unique_numbers[probe]) {
            appear_times[probe]++;
        } else {
            unique_numbers.push_back(S[i]);
            appear_times.push_back(1);
            probe++;
        }
    }
    print(unique_numbers);
    print(appear_times);
    subsetRecur(unique_numbers, appear_times, 0, result, results);
    return results;
}



TreeNode *buildTreeRecur(vector<int> &inorder, vector<int> &postorder,
                         int in_start, int in_end,
                         int post_start, int post_end) {
    if (in_start == in_end) {
        TreeNode *new_node = new TreeNode(inorder[in_start]);
        return new_node;
    }
    if (in_start > in_end) {
        return NULL;
    }
    TreeNode *new_node = new TreeNode(postorder[post_end]);
    //find middle in inorder
    int middle = in_start;
    for (; inorder[middle] != postorder[post_end]; middle++) {

    }
    int left_size = middle - in_start - 1;
    int right_size = in_end - middle - 1;
    new_node->left = buildTreeRecur(inorder, postorder, in_start, middle-1,
                                    post_start, post_start+left_size);
    new_node->right = buildTreeRecur(inorder, postorder, middle+1, in_end,
                      post_start+left_size+1, post_end-1);
    return new_node;
}
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode *buildTree2(vector<int> &inorder, vector<int> &postorder) {
    return buildTreeRecur(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
}

TreeNode *buildTreeRecur2(vector<int> &preorder, vector<int> &inorder,
                          int pre_start, int pre_end,
                          int in_start, int in_end) {
    if (in_start > in_end) return NULL;
    if (in_start == in_end) {
        TreeNode *new_node = new TreeNode(inorder[in_start]);
        return new_node;
    }
    int middle = in_start;
    for (; inorder[middle] != preorder[pre_start]; ++middle) {

    }
    TreeNode *new_node = new TreeNode(inorder[middle]);
    int left_size = middle - 1 - in_start;
    new_node->left = buildTreeRecur2(preorder, inorder,
                                     pre_start+1, pre_start+left_size+1,
                                     in_start, middle-1);
    new_node->right = buildTreeRecur2(preorder, inorder,
                                      pre_start+left_size+2, pre_end,
                                      middle+1, in_end);
    return new_node;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return buildTreeRecur2(preorder, inorder, 0, inorder.size()-1, 0, preorder.size()-1);
}

// class Solution {
// public:
//     vector<vector<string>> partition(string s) {

//     }
// };



int threeSumClosest(vector<int> &num, int target) {
    sort(num.begin(), num.end());
    int sum;
    int closest_sum = 10000;
    for (int i = 0; i <=  num.size()-3; ++i) {
        int k = num.size()-1;
        for (int j = i+1; j != k; ++j) {
            int num_ij = num[i]+num[j];
            while (target < num_ij+num[k] && k > j) {
                --k;
            }

            if (k == num.size()-1 && target-num_ij-num[k] <= closest_sum) {
                    closest_sum = target-num_ij-num[k];
                    sum = num_ij + num[k];
            } else if (k != num.size()-1){
                ++k;
                if (num_ij+num[k]-target <= closest_sum) {
                    closest_sum = num_ij+num[k]-target;
                    sum = num_ij + num[k];
                }
                if (k != j+1 && target-num_ij-num[k-1] <= closest_sum) {
                    closest_sum = target-num_ij-num[k-1];
                    sum = num_ij + num[k-1];
                }
            }
        }
    }
    cout <<"closest_sum:" <<closest_sum <<endl;
    return sum;
}

ListNode *partition(ListNode *head, int x) {
    if (head == NULL) {
        return NULL;
    }
    ListNode *small_head = new ListNode(0);
    ListNode *large_head = new ListNode(0);
    ListNode *small_probe = small_head;
    ListNode *large_probe = large_head;
    ListNode *probe = head;
    while (probe != NULL) {
        if (probe->val < x) {
            small_probe->next = probe;
            small_probe = small_probe->next;
        } else {
            large_probe->next = probe;
            large_probe = large_probe->next;
        }
        probe = probe->next;
    }
    small_probe->next = large_head->next;
    return small_head->next;
}

bool isPalindrome(const string &s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
void partitionRecur(const string &s, int start, int end,
                    vector<string> &result,
                    vector<vector<string> > &results) {
    if (start > end) {
        results.push_back(result);
    } else {
        for (int i = start; i <= end; ++i) {
            if (isPalindrome(s, start, i)) {
                result.push_back(s.substr(start, i-start+1));
                partitionRecur(s, i+1, end, result, results);
                result.pop_back();
            }
        }
    }
}

vector<vector<string> > partition(string s) {
    vector<vector<string> > results;
    vector<string> result;
    partitionRecur(s, 0, s.size()-1, result, results);
    return results;
}



// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void nextPermutation(vector<int> &num) {
    int start;
    int end = num.size()-1;
    int probe = num.size()-2;
    for (; probe >= 0 && num[probe] >= num[probe+1]; --probe) {
    }
    if (probe == num.size()-2) {
        start = probe;
    } else if (probe == -1) {
        start = 0;
    } else {
        int swap_index = probe+1;
        for(; swap_index <= num.size()-1 && num[swap_index]>num[probe];
            ++swap_index){
        }
        swap_index--;
        swap(num[probe], num[swap_index]);
        start = probe+1;
    }
    while (start < end) {
        swap(num[start], num[end]);
        start++;
        end--;
    }
}

// There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

// Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

// Note:
// The solution is guaranteed to be unique.
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int L = gas.size();
    if (L == 0) return -1;
    int start = L-1; //start location of the circle
    int end = start; //current end location
    int tank_gas = 0; //tank_gas and end location from start
    while (end != start+L) {
        if (tank_gas >= 0) {
            while (end != start+L && tank_gas >= 0) {
                tank_gas = tank_gas - cost[end%L] + gas[end%L];
                end++;
            }
            if (end == start+L && tank_gas >= 0) return start;
        } else {
            while (end != start+L && tank_gas < 0) {
                start--;
                tank_gas = tank_gas - cost[start] + gas[start];
            }
            if (end == start+L && tank_gas >= 0) return start;
        }
    }
    return -1;
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL) {
            return head;
        }
        ListNode *probe = head->next;
        ListNode *sorted_head = new ListNode(-1);
        sorted_head->next = head;
        ListNode *sorted_probe;
        head->next = NULL;
        while (probe != NULL) {
            print(sorted_head->next);
            sorted_probe = sorted_head->next;
            if (probe->val <= sorted_probe->val) {//insert at start
                sorted_head->next = probe;
                probe = probe->next;
                sorted_head->next->next = sorted_probe;
            } else {
                while (sorted_probe->next != NULL &&
                       sorted_probe->next->val <= probe->val) {
                    sorted_probe = sorted_probe->next;
                }
                if (sorted_probe->next == NULL) { //insert at last
                    sorted_probe->next = probe;
                    probe = probe->next;
                    sorted_probe->next->next = NULL;
                } else { //insert at middle
                    ListNode *temp_node = probe->next;
                    probe->next = sorted_probe->next;
                    sorted_probe->next = probe;
                    probe = temp_node;
                }
            }
        }
        return sorted_head->next;
    }



    void combinationSum2Recur(vector<int> &sorted_num, vector<int> &num_time, int current,
    int target, vector<int> result, vector<vector<int> > &results) {
        if (target == 0) {
            results.push_back(result);
        } else if (target > 0 && current < sorted_num.size()) {
            combinationSum2Recur(sorted_num, num_time, current+1, target, result, results);
            for(int i = 1; i <= num_time[current]; ++i) {
                int temp_target = target - i*sorted_num[current];
                if (temp_target < 0) {
                    break;
                }
                result.push_back(sorted_num[current]);
                combinationSum2Recur(sorted_num, num_time, current+1, temp_target, result, results);
            }
        }
    }

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<int> result;
        vector<vector<int> > results;
        if (num.size() == 0) return results;

        //get sorted_num and num_time
        sort(num.begin(), num.end());
        vector<int> sorted_num;
        vector<int> num_time;
        sorted_num.push_back(num[0]);
        num_time.push_back(1);
        int current = 0;
        for (int i = 1; i < num.size(); ++i) {
            if (num[i] == sorted_num[current]) {
                num_time[current]++;
            } else {
                sorted_num.push_back(num[i]);
                num_time.push_back(1);
            }
        }

        //run recursion
        combinationSum2Recur(sorted_num, num_time, 0, target, result, results);

        return results;
    }

    int jump(int A[], int n) {
        if (n < 2) return 0;
        vector<int> jump_num(n, 2*n);
        jump_num[0] = 0;
        for (int i = 0; i < n; ++i) { //for each index
            if (i+A[i] >= n-1) { //if jump extend n-1
                if (jump_num[n-1] >= jump_num[i]+1) {
                    jump_num[n-1] = jump_num[i] + 1;
                }
            }
            if (jump_num[i]+2 < jump_num[n-1]) { //if jump_num[i]+1
                for (int j = i+A[i]; jump_num[i]+1<jump_num[j]; --j) {
                    jump_num[j] = jump_num[i] + 1;
                }
            }
        }
        if (jump_num[n-1] == 2*n) {
            return -1;
        } else {
            return jump_num[n-1];
        }
    }

// Given this linked list: 1->2->3->4->5

// For k = 2, you should return: 2->1->4->3->5

// For k = 3, you should return: 3->2->1->4->5

    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k < 1) return head;
        ListNode *fake_head = new ListNode(-1);
        fake_head->next = head;
        ListNode *group_tail = fake_head;
        ListNode *probe = group_tail;
        ListNode *reverse_start;
        ListNode *reverse_probe;
        ListNode *temp;
        while (probe != NULL) {
            //search new group_tail
            int i = 0;
            for(; i < k && probe != NULL; ++i) {
                probe = probe->next;
            }

            //if not found
            if (probe == NULL) {
                return fake_head->next;
            } else {//if found
                reverse_start = group_tail->next;
                group_tail->next = probe;
                group_tail = reverse_start;
                reverse_probe = reverse_start->next;
                reverse_start->next = probe->next;
                temp = reverse_probe->next;
                reverse_probe->next = reverse_start;
                for(int j = 0; j < k-2; ++j) {
                    reverse_start = reverse_probe;
                    reverse_probe = temp;
                    temp = temp->next;
                    reverse_probe->next = reverse_start;
                }
                probe = group_tail;
            }
        }
        return fake_head->next;
    }

// Given 1->2->3->3->4->4->5, return 1->2->5.
// Given 1->1->1->2->3, return 2->3.
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return head;
        ListNode *fake_head = new ListNode(-1);
        fake_head->next = head;
        ListNode *anchor = fake_head;
        ListNode *probe = head->next;
        ListNode *temp;
        bool to_delete = false;
        while (probe != NULL) {
            if (anchor->next->val != probe->val) {
                if (to_delete) {
                    temp = anchor->next;
                    anchor->next = probe;
                    probe = probe->next;
                    delete temp;
                    to_delete = false;
                } else {
                    anchor = anchor->next;
                    probe = probe->next;
                }
            } else {
                to_delete = true;
                temp = probe;
                probe = probe->next;
                delete temp;
            }
        }
        if (to_delete) {
            temp = anchor->next;
            anchor->next = NULL;
            delete temp;
        }
        return fake_head->next;
    }

//     Given a collection of numbers that might contain duplicates, return all possible unique permutations.

// For example,
// [1,1,2] have the following unique permutations:
// [1,1,2], [1,2,1], and [2,1,1].
    void permuteUniqueRecur(vector<vector<int> > &results,
                            vector<int> &result,
                            vector<int> &unique_numbers,
                            vector<int> &num_time,
                            const int &L) {
        if (result.size() == L) {
            results.push_back(result);
        } else {
            for (int i = 0; i < unique_numbers.size(); ++i) {
                if (num_time[i] > 0) {
                    result.push_back(unique_numbers[i]);
                    num_time[i]--;
                    permuteUniqueRecur(results, result,
                                       unique_numbers, num_time, L);
                    result.pop_back();
                    num_time[i]++;
                }
            }

        }
    }

    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<int> unique_numbers;
        vector<int> num_time;
        vector<vector<int> > results;
        vector<int> result;
        if (num.size() == 0) return results;

        int L = num.size();

        //generate unique_numbers, and num_time
        sort(num.begin(), num.end());
        int current = 0;
        unique_numbers.push_back(num[0]);
        num_time.push_back(1);
        for(int i = 1; i < num.size(); ++i) {
            if (num[i] == unique_numbers[current]) {
                num_time[current]++;
            } else {
                unique_numbers.push_back(num[i]);
                num_time.push_back(1);
                current++;
            }
        }

        print(unique_numbers);
        print(num_time);
        permuteUniqueRecur(results, result, unique_numbers, num_time, L);
        return results;
    }


// Two elements of a binary search tree (BST) are swapped by mistake.

// Recover the tree without changing its structure.

// Note:
// A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

    void recoverTree(TreeNode *root) {

    }

// A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

// Return a deep copy of the list.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        unordered_map<int, RandomListNode *> node_map;
        unordered_map<int, RandomListNode *>::const_iterator got;
        RandomListNode *new_head = new RandomListNode(head->label);
        RandomListNode *new_probe = new_head;
        RandomListNode *probe = head;
        RandomListNode *new_temp;
        node_map.insert({new_head->label, new_head});
        while (probe != NULL) { //copy pointer of current probe
            if (probe->next != NULL) {
                //copy probe->next
                got = node_map.find(probe->next->label);
                if (got == node_map.end()) {
                    new_temp = new RandomListNode(probe->next->label);
                    new_probe->next = new_temp;
                    node_map.insert({new_temp->label, new_temp});
                } else {
                    new_probe->next = got->second;
                }
            }
            if (probe->random != NULL) {
                //copu probe->random
                got = node_map.find(probe->random->label);
                if (got == node_map.end()) {
                    new_temp = new RandomListNode(probe->random->label);
                    new_probe->random = new_temp;
                    node_map.insert({new_temp->label, new_temp});
                } else {
                    new_probe->random = got->second;
                }
            }
            probe = probe->next;
            new_probe = new_probe->next;
        }
        return new_head;
    }

    bool isScrambleRecur(string &s1, string &s2, int s1_start, int s1_end,
                         int s2_start, int s2_end) {
        //if size == 1
        if (s1_start == s1_end) {
            if (s1[s1_start] == s2[s2_start]) {
                return true;
            } else {
                return false;
            }
        }

        //if same
        int i = s1_start;
        int j = s2_start;
        for (; i <= s1_end && s1[i] == s2[j]; ++i, ++j) {
        }
        if (i == s1_end+1) return true;

        //if not same chars
        unordered_map<char, int> hash_map;
        unordered_map<char, int>::iterator got;
        //create hash map by s1
        for (i = s1_start; i <= s1_end; ++i) {
            got = hash_map.find(s1[i]);
            if (got == hash_map.end()) {//if not found
                //add new
                hash_map.insert({s1[i],1});
            } else {
                got->second++;
            }
        }

        //check set of chars in s1 is same as s2
        for (j = s2_start; j <= s2_end; ++j) {
            got = hash_map.find(s2[j]);
            if (got == hash_map.end()) {
                return false;
            } else if (got->second == 1) {
                hash_map.erase(got);
            } else {
                got->second--;
            }
        }

        //now the condition is s1 has same char as s2, but not in same order
        for (i = 0; s1_start+i+1 <= s1_end; ++i) {
            if (isScrambleRecur(s1, s2, s1_start, s1_start+i,
                                s2_start, s2_start+i) &&
                isScrambleRecur(s1, s2, s1_start+i+1, s1_end,
                                s2_start+i+1, s2_end)) {
                return true;
            }
            if (isScrambleRecur(s1, s2, s1_start, s1_start+i,
                                s2_end-i, s2_end) &&
                isScrambleRecur(s1, s2, s1_start+i+1, s1_end,
                                s2_start, s2_end-i-1)) {
                return true;
            }
        }
        return false;
    }

    bool isScramble(string s1, string s2) {
        return isScrambleRecur(s1, s2, 0, s1.size()-1, 0, s2.size()-1);
    }

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
    string getPermutation(int n, int k) {
        vector<char> nums;
        vector<int> factorial(n+1, 1);
        for (int i = 1; i <= n; ++i) {
            factorial[i] = factorial[i-1]*i;
            nums.push_back(i+'0');
        }
        string result;
        int insert_index;
        k = k-1;
        for (int i = 1; i < n; ++i) {
            insert_index = k / factorial[n-i];
            result.push_back(nums[insert_index]);
            nums.erase(nums.begin()+insert_index);
            k = k % factorial[n-i];
        }
        result.push_back(nums[0]);
        return result;
    }

// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete at most two transactions.

// Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

    int maxProfit(vector<int> &prices) {
        if (prices.size()<2) return 0;
        int first_buy = 1000;
        int first_sell = 1000;
        int second_buy = 1000;
        int second_sell = 1000;
        int min = 1000;
        int profit_com_fs;
        int profit_com_sc;
        int profit_del_f;
        int profit_del_s;
        int profit_del_c;
        if (prices[0] < prices[1]) {
            second_buy = prices[0];
            second_sell = prices[1];
            min = second_sell;
        } else {
            min = prices[1];
        }
        for (int i = 2; i < prices.size(); ++i) {
            if (prices[i] <= min) { // current smaller than min
                min = prices[i];
            } else {
                profit_del_c = first_sell+second_sell-first_buy-second_buy;
                profit_com_fs = second_sell - first_buy + prices[i] - min;
                profit_com_sc = first_sell- first_buy + prices[i] - second_buy;
                profit_del_f = second_sell - second_buy + prices[i] - min;
                profit_del_s = first_sell -first_buy + prices[i] - min;
                //test
                // cout <<profit_del_c <<endl;
                if (profit_com_fs > profit_del_c &&
                    profit_com_fs >= profit_com_sc &&
                    profit_com_fs >= profit_del_f &&
                    profit_com_fs >= profit_del_s) {
                    first_sell = second_sell;
                    second_buy = min;
                    second_sell = prices[i];
                    min = prices[i];
                } else if (profit_com_sc > profit_del_c &&
                           profit_com_sc >= profit_com_fs &&
                           profit_com_sc >= profit_del_s &&
                           profit_com_sc >= profit_del_f) {
                    second_sell = prices[i];
                    min = prices[i];
                } else if (profit_del_f > profit_del_c &&
                           profit_del_f >= profit_com_fs &&
                           profit_del_f >= profit_com_sc &&
                           profit_del_f >= profit_del_s) {
                    first_buy = second_buy;
                    first_sell = second_sell;
                    second_buy = min;
                    second_sell = prices[i];
                    min = prices[i];
                } else if (profit_del_s > profit_del_c &&
                           profit_del_s >= profit_com_fs &&
                           profit_del_s >= profit_com_sc &&
                           profit_del_s >= profit_del_f) {
                    second_buy = min;
                    second_sell = prices[i];
                    min = prices[i];
                }
            }
        }
        return first_sell+second_sell-first_buy-second_buy;
    }

    ListNode *rotateRight(ListNode *head, int k) {
        ListNode *probe = head;
        int length = 0;
        while (probe != NULL) {
            probe = probe->next;
            length++;
        }
        if (length < 2) return head;
        k = k % length;
        if (k == 0) return head;

        //search for new head
        ListNode *new_head;
        probe = head;
        for (int i = 1; i < length-k; ++i) {
            probe = probe->next;
        }
        new_head = probe->next;
        probe->next = NULL;
        probe = new_head;
        for (int i = 1; i < k; ++i) {
            probe = probe->next;
        }

        probe->next = head;
        return new_head;
    }

    bool listNodeCompare (ListNode *a, ListNode *b) {
        return (a->val < b->val);
    }

    int findPosition (vector<ListNode *> &sorted_vector, ListNode *t) {
        int begin = 0;
        int end = sorted_vector.size();
        int middle;
        while (begin < end) {
            middle = (begin+end)/2;
            if (sorted_vector[middle]->val == t->val) {
                return middle;
            } else if (sorted_vector[middle]->val < t->val) {
                begin = middle+1;
            } else {
                end = middle;
            }
        }
        return begin;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) return NULL;
        if (lists.size() == 1) return lists[0];
        ListNode *fake_head = new ListNode(-1);
        ListNode *probe = fake_head;
        ListNode *temp;
        int index;
        vector<ListNode *> sorted_temp;
        for (int i = 0; i < lists.size(); ++i) {
            sorted_temp.push_back(lists[i]);
        }

        sort(sorted_temp.begin(), sorted_temp.end(), listNodeCompare);
        while(!sorted_temp.empty()) {
            probe->next = sorted_temp[0];
            probe = probe->next;
            temp = sorted_temp[0]->next;
            sorted_temp.erase(sorted_temp.begin());
            if (temp != NULL) {
                index = findPosition(sorted_temp, temp);
                sorted_temp.insert(sorted_temp.begin()+index, temp);
            }
        }
        return fake_head->next;
    }

    char *strStr(char *haystack, char *needle) {
        int result = 0;
        while (1) {
            int j = 0;
            int i = result;
            for (; needle[j] != '\0'; ++i, ++j) {
                if (haystack[i] == '\0' || haystack[i] != needle[j]) {
                    break;
                }
            }
            if (needle[j] == '\0') {
                return haystack+result;
            }
            if (haystack[i] == '\0') {
                return NULL;
            }
            result++;
        }
    }

    //***********************************
    // void recoverTree(TreeNode *root) {
    //     vector<TreeNode *> swapped;

    // }

// ["01101","11010","01110","11110","11111","00000"]

    int getArea(vector<vector<char> > &matrix, int t, int begin, int end) {
        int height = 1;
        //2 1 3
        //search up
        for (int i = t-1; i >= 0; --i) {
            int j = begin;
            for (; j <= end && matrix[i][j] == '1'; ++j) {
            }
            if (j == end+1) {
                height++;
            } else {
                break;
            }
        }
        //search down
        for (int i = t+1; i < matrix.size(); ++i) {
            int j = begin;
            for (; j <= end && matrix[i][j] == '1'; ++j) {
            }
            if (j == end+1) {
                height++;
            } else {
                break;
            }
        }
        return height*(end-begin+1);
    }
//Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
    // int maximalRectangle(vector<vector<char> > &matrix) {
    //     if (matrix.size() == 0) return 0;
    //     int height;
    //     int width;
    //     int begin;
    //     int end;
    //     int area = 0;
    //     int temp_area;
    //     for (int i = 0; i < matrix.size(); ++i) {
    //         for (int j = 0; j < matrix[0].size(); ++j) {
    //             if (matrix[i][j] == '1') {
    //                 begin = j;
    //                 ++j;
    //                 while(j < matrix[0].size() && matrix[i][j] == '1') {
    //                     ++j;
    //                 }
    //                 end = j-1;
    //                 if ((end-begin+1)*matrix.size() > area) {
    //                     temp_area = getArea(matrix, i, begin, end);
    //                     if (temp_area > area) {
    //                         area = temp_area;
    //                     }
    //                 }
    //                 //now find intersection
    //                 if (i != 0 && begin != end) {
    //                     // cout <<"test\n";
    //                     //left link
    //                     int k = begin;
    //                     for (; k <= end && matrix[i-1][k] == '1'; ++k) {

    //                     }
    //                     if (k != begin && k != end+1 &&
    //                         (k-begin)*matrix.size() > area) {
    //                         // cout <<"test\n";
    //                         temp_area = getArea(matrix, i, begin, k-1);
    //                         area = max(area, temp_area);
    //                     }
    //                     //right link
    //                     k = end;
    //                     for (; k >= begin && matrix[i-1][k] == '1'; --k) {

    //                     }
    //                     if (k != end && k != begin-1 &&
    //                         (end-k)*matrix.size() > area) {
    //                         temp_area = getArea(matrix, i, k+1, end);
    //                         area = max(area, temp_area);
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     return area;
    // }


    // vector<Interval> merge(vector<Interval> &intervals) {

    // }

    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        //find first interval
        //find the first number that newInterval.begin is smaller than
        int begin_i = 0;
        int begin_v = 0;
        int end_i = 0;
        int end_v = 0;
        int overlapping = 1;
        for (; begin_i != intervals.size(); ++begin_i) {
            if (intervals[begin_i].start >= newInterval.start) {
                begin_v = newInterval.start;
                break;
            }
            if (intervals[begin_i].end >= newInterval.start) {
                begin_v = intervals[begin_i].start;
                break;
            }
        }

        //if not overlapping
        if (begin_i == intervals.size()) {
            intervals.push_back(newInterval);
            return intervals;
        }

        //find second interval
        end_i = begin_i;
        for (; end_i != intervals.size(); ++end_i) {
            if (intervals[end_i].start >= newInterval.end) {
                end_v = newInterval.end;
                end_i--;
                break;
            }
            if (intervals[end_i].end >= newInterval.end) {
                end_v = intervals[end_i].end;
                break;
            }
        }

        //if extend to end
        if (end_i == intervals.size()) {
            end_i--;
            end_v = newInterval.end;
        }
        //if not overlapping
        if (end_i < begin_i) {
            intervals.insert(intervals.begin()+begin_i, newInterval);
        } else if (end_i != begin_i) {
            //del shared intervals from begin_i to end_i
            intervals.erase(intervals.begin()+begin_i,intervals.begin()+end_i);
            //insert new interval<begin_v, end_v> at begin_i
            Interval temp(begin_v, end_v);
            intervals.insert(intervals.begin()+begin_i, temp);
        }

        return intervals;
    }

    // void solveSudoku(vector<vector<char> > &board) {

    // }

    // vector<vector<int> > fourSum(vector<int> &num, int target) {

    // }

    // vector<string> wordBreak(string s, unordered_set<string> &dict) {

    // }

    // bool wordBreak(string s, unordered_set<string> &dict) {

    // }

    // vector<string> restoreIpAddresses(string s) {

    // }

    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> results;
        if (matrix.size() == 0) return results;
        int left = 0;
        int right = matrix[0].size()-1;
        int up = 0;
        int down = matrix.size()-1;
        while (up <= down) {
            for (int j = left; j <= right; ++j) {
                results.push_back(matrix[up][j]);
            }
            up++;
            if (left <= right) {
                for (int i = up; i <= down; ++i) {
                    results.push_back(matrix[i][right]);
                }
                right--;
            }
            if (up <= down) {
                for (int j = right; j >= left; --j) {
                    results.push_back(matrix[down][j]);
                }
                down--;
            }
            if (left <= right) {
                for (int i = down; i > up; --i) {
                    results.push_back(matrix[i][left]);
                }
            }
        }
        return results;
    }

    // string multiply(string num1, string num2) {

    // }
    // ListNode *quickSortRecur(ListNode *head, ListNode *tail) {
    //     //if len <= 1
    //     if (head == NULL) return NULL;
    //     if (head->next == tail) return head;
    //     int len = 0;
    //     ListNode *p = head;
    //     while(p != tail) {
    //         len++;
    //         p = p->next;
    //     }
    //     int index = rand() % len;
    //     ListNode *equal = head;
    //     p = head;
    //     for (int i = 1; i < index; ++i) {
    //         p = p->next;
    //     }
    //     equal = p->next;
    //     p->next =
    // }
    ListNode *quickSortRecur(ListNode *head, ListNode *tail) {
        if (head == NULL) return NULL;
        if (head->next == tail) return head;
        ListNode *p = head;
        int len = 0;
        // print
        while(p != tail) {
            cout <<p->val <<",";
            len++;
            p = p->next;
        }
        cout <<endl;
        int random = rand() % len;
        ListNode *small = new ListNode(-1);
        ListNode *big = new ListNode(-1);
        p = head;
        for (int i = 2; i < random; ++i) {
            p = p->next;
        }
        ListNode *equal = p->next;
        p->next = equal->next; //take out the probe node
        ListNode *small_probe = small;
        ListNode *big_probe = big;
        ListNode *equal_probe = equal;
        ListNode *probe = head;
        // small(small_probe)->NULL
        // big(big_probe)->NULL
        // equal(some_node)(equal_probe)->NULL
        // probe = head
        while (probe != tail) {
            if (probe->val == equal->val) {
                equal_probe->next = probe;
                equal_probe = equal_probe->next;
            } else if (probe->val > equal->val) {
                big_probe->next = probe;
                big_probe = big_probe->next;
            } else {
                small_probe->next = probe;
                small_probe = small_probe->next;
            }
            probe = probe->next;
        }
        small_probe->next = equal;
        if (small_probe != small) {
            small->next = quickSortRecur(small->next, equal);
        }
        if (big_probe != big) {
            big_probe->next = tail;
            equal_probe->next = quickSortRecur(big->next, tail);
        } else {
            equal_probe->next = tail;
        }
        return small->next;
    }

    ListNode *sortList(ListNode *head) {
        srand(unsigned(time(0)));
        //quick sort
        return quickSortRecur(head, NULL);
    }

    vector<Interval> merge(vector<Interval> &intervals) {
        int i = 0;
        int begin_i;
        int end_i;
        int end_v;
        int begin_v;
        sort(intervals.begin(), intervals.end(), cmp);
        while (i < intervals.size()-1) {
            if (intervals[i].end >= intervals[i+1].start) {
                begin_i = i;
                end_i = i+1;
                end_v = max(intervals[i].end, intervals[end_i].end);
                begin_v = intervals[begin_i].start;
                ++i;
                while (i < intervals.size()-1 && end_v >= intervals[i+1].start) {
                    end_i = i+1;
                    end_v = max(end_v, intervals[end_i].end);
                    ++i;
                }
                intervals.erase(intervals.begin()+begin_i, intervals.begin()+end_i+1);
                Interval temp(begin_v, end_v);
                intervals.insert(intervals.begin()+begin_i, temp);
                i = begin_i+1;
            } else {
                ++i;
            }
        }
        return intervals;
    }

    int largestRectangleArea(vector<int> &height) {
        if (height.size() == 0) return 0;
        vector<int> stack;
        int largest = height[0];
        int temp;
        int j;
        for (int i = 0; i < height.size(); ++i) {
            if (stack.empty() || height[stack.back()] <= height[i]) {
                stack.push_back(i);
            } else if (height[stack.back()] > height[i]) {
                while (stack.size() > 1 && height[stack.back()] > height[i]) {
                    j = stack.size()-1;
                    temp = (i - stack[j-1]-1)*height[stack[j]];
                    if (temp > largest) largest = temp;
                    stack.pop_back();
                }
                if (stack.size() == 1 && height[stack.back()] > height[i]) {
                    temp = (i - 0)*height[stack.back()];
                    if (temp > largest) largest = temp;
                    stack.pop_back();
                }
                stack.push_back(i);
            }
        }
        while (stack.size() > 1) {
            j = stack.size()-1;
            temp = (height.size() - stack[j-1]-1)*height[stack[j]];
            if (temp > largest) largest = temp;
            stack.pop_back();
        }
        if (stack.size() == 1) {
            temp = (height.size() - 0)*height[stack.back()];
            if (temp > largest) largest = temp;
            stack.pop_back();
        }
        return largest;
    }

    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.size() == 0) return 0;
        vector<int> height(matrix[0].size(), 0);
        int max = 0;
        int temp;
        for (int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '1') {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }
            temp = largestRectangleArea(height);
            if (temp > max) max = temp;
        }
        return max;
    }
    // int getArea(vector<vector<char> > &matrix, int t, int begin, int end) {
    //     int height = 1;
    //     //2 1 3
    //     //search up
    //     for (int i = t-1; i >= 0; --i) {
    //         int j = begin;
    //         for (; j <= end && matrix[i][j] == '1'; ++j) {
    //         }
    //         if (j == end+1) {
    //             height++;
    //         } else {
    //             break;
    //         }
    //     }
    //     //search down
    //     for (int i = t+1; i < matrix.size(); ++i) {
    //         int j = begin;
    //         for (; j <= end && matrix[i][j] == '1'; ++j) {
    //         }
    //         if (j == end+1) {
    //             height++;
    //         } else {
    //             break;
    //         }
    //     }
    //     return height*(end-begin+1);
    // }
//Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
    // int maximalRectangle(vector<vector<char> > &matrix) {
    //     if (matrix.size() == 0) return 0;
    //     int height;
    //     int width;
    //     int begin;
    //     int end;
    //     int area = 0;
    //     int temp_area;
    //     for (int i = 0; i < matrix.size(); ++i) {
    //         for (int j = 0; j < matrix[0].size(); ++j) {
    //             if (matrix[i][j] == '1') {
    //                 begin = j;
    //                 ++j;
    //                 while(j < matrix[0].size() && matrix[i][j] == '1') {
    //                     ++j;
    //                 }
    //                 end = j-1;
    //                 if ((end-begin+1)*matrix.size() > area) {
    //                     temp_area = getArea(matrix, i, begin, end);
    //                     if (temp_area > area) {
    //                         area = temp_area;
    //                     }
    //                 }
    //                 //now find intersection
    //                 if (i != 0 && begin != end) {
    //                     // cout <<"test\n";
    //                     //left link
    //                     int k = begin;
    //                     for (; k <= end && matrix[i-1][k] == '1'; ++k) {

    //                     }
    //                     if (k != begin && k != end+1 &&
    //                         (k-begin)*matrix.size() > area) {
    //                         // cout <<"test\n";
    //                         temp_area = getArea(matrix, i, begin, k-1);
    //                         area = max(area, temp_area);
    //                     }
    //                     //right link
    //                     k = end;
    //                     for (; k >= begin && matrix[i-1][k] == '1'; --k) {

    //                     }
    //                     if (k != end && k != begin-1 &&
    //                         (end-k)*matrix.size() > area) {
    //                         temp_area = getArea(matrix, i, k+1, end);
    //                         area = max(area, temp_area);
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     return area;
    // }

    // void reorderList(ListNode *head) {
    //     // O(1) space O(n) time

    // }

    vector<int> string2int(string num, int L) {
        int temp;
        int start = num.size()-L;
        vector<int> result;
        while (start >= 0) {
            temp = stoi(num.substr(start, L));
            start -= L;
            result.push_back(temp);
        }
        if (start != -L) {
            temp = stoi(num.substr(0, L+start));
            result.push_back(temp);
        }
        return result;
    }

    vector<int> multiply(vector<int> num1, vector<int> num2, int L) {
        vector<int> result(num1.size()+num2.size(), 0);
        int temp;
        int threshold = pow(10,L);
        for (int i = 0; i < num1.size(); ++i) {
            for (int j = 0; j < num2.size(); ++j) {
                temp = num1[i]*num2[j];
                result[i+j] += temp;
            }
        }
        int remain = 0;
        // print(result);
        for (int i = 0; i < result.size(); ++i) {
            temp = (remain+result[i]) / threshold;
            result[i] = (remain+result[i]) % threshold;
            remain = temp;
        }
        return result;
    }

    string multiply(string num1, string num2) {
        // Another Java method that takes O(n+m) in space as it save the result in an array n+m size (where n and m are strings lengths) and O(n*m) time to complete.
        int L = 2;
        vector<int> number_vector1 = string2int(num1, L);
        vector<int> number_vector2 = string2int(num2, L);
        vector<int> result_vector = multiply(number_vector1,
                                             number_vector2,
                                             L);
        // print(number_vector1);
        // print(number_vector2);
        print(result_vector);
        int threshold = pow(10, L-1);
        int start;
        ostringstream convert;
        int i = result_vector.size()-1;
        if (result_vector[i] != 0) {
            convert <<result_vector[i];
            --i;
        } else {
            --i;
            convert <<result_vector[i];
            --i;
        }
        for (; i >= 0; --i) {
            start = threshold;
            while (start > result_vector[i]) {
                convert <<0;
                start/=10;
            }
            if (start != 0) {
                convert <<result_vector[i];
            }
        }
        return convert.str();
    }


    // vector<string> wordBreak(string s, unordered_set<string> &dict) {

    // }
// "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
    // bool wordBreakRecur(string &s, int current, unordered_set<string> &dict) {
    //     if (current == s.size()) return true;
    //     unordered_set<string>::const_iterator got;
    //     for(int len = 1; len  <= s.size()-current; --len) {
    //         got = dict.find(s.substr(current, len));
    //         if (got != dict.end() && wordBreakRecur(s, current+len, dict)) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    // bool wordBreak(string s, unordered_set<string> &dict) {
    //     if (s.size() == 0) return false;
    //     vector<bool> results(s.size()+1, false);
    //     results[0] = true;
    //     unordered_set<string>::const_iterator got;
    //     for (int i = 1; i < results.size(); ++i) {
    //         for (int j = 0; j < i; ++j) {
    //             if (results[j]) {
    //                 got = dict.find(s.substr(j,i-j));
    //                 if (got != dict.end()) {
    //                     results[i] = true;
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    //     return results.back();
    // }

    void wordBreakConstructResults(vector<vector<int> > &temp_results,
                                   int current,
                                   vector<string> &results,
                                   string &s){
        for (int i = 0; i < temp_results[current].size(); ++i) {
            if (temp_results[current][i] == 0) {
                results.push_back(s);
            } else {
                s.insert(temp_results[current][i], " ");
                wordBreakConstructResults(temp_results,
                                          temp_results[current][i],
                                          results, s);
                s.erase(temp_results[current][i], 1);
            }
        }
    }

    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        if (s.size() == 0) return vector<string>();
        vector<vector<int> > results(s.size()+1, vector<int>());
        results[0].push_back(-1);
        unordered_set<string>::const_iterator got;
        for(int i = 1; i < results.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (results[j].size()>0) {
                    got = dict.find(s.substr(j, i-j));
                    if (got != dict.end()) {
                        results[i].push_back(j);
                    }
                }
            }
        }
        //construct results;
        if (results.back().empty()) {
            return vector<string>();
        }
        vector<string> final_results;
        wordBreakConstructResults(results, s.size(), final_results, s);
        return final_results;
    }

// Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

// Note:
// Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
// The solution set must not contain duplicate quadruplets.
//     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

//     A solution set is:
//     (-1,  0, 0, 1)
//     (-2, -1, 1, 2)
//     (-2,  0, 0, 2)

// [-471,-434,-418,-395,-360,-357,-351,-342,-317,-315,-313,-273,-272,-249,-240,-216,-215,-214,-209,-198,-179,-164,-161,-141,-139,-131,-103,-97,-81,-64,-55,-29,11,40,40,45,64,87,95,101,115,121,149,185,230,230,232,251,266,274,277,287,300,325,334,335,340,383,389,426,426,427,457,471,494], 2705

    void fourSumRecur(unordered_set<int> &hashmap,
                      vector<vector<int> > &results,
                      vector<int> result,
                      vector<int> &unique_nums,
                      vector<int> &appear_times,
                      int sum, int current, int target) {
        int max;
        int min;
        if (current == unique_nums.size()) return;
        // print(result);
        int current_len = result.size();
        if (current_len == 3) {
            unordered_set<int>::const_iterator got = hashmap.find(target-sum);
            if (got != hashmap.end() && target-sum != result.back()) {
                result.push_back(target-sum);
                results.push_back(result);
            }
        } else {
            fourSumRecur(hashmap, results, result, unique_nums,
                                     appear_times, sum,
                                     current+1, target);
            for(int i = 0; i < appear_times[current] && i < 4-current_len;++i){
                result.push_back(unique_nums[current]);
                sum += unique_nums[current];
                // current++;
                if (result.size() != 4) {
                    max = sum + (4-result.size())*unique_nums.back();
                    min = sum + (4-result.size())*unique_nums[current];
                    if (target <= max && target >= min) {
                        fourSumRecur(hashmap, results, result, unique_nums,
                                     appear_times, sum,
                                     current+1, target);
                    }
                } else if (sum == target) {
                    results.push_back(result);
                }
            }
        }
    }

    vector<vector<int> > fourSum(vector<int> &num, int target) {
        if (num.size() < 4) return vector<vector<int> >();
        sort(num.begin(), num.end());
        int index = num.size()-1;
        int max = num[index] + num[index-1] + num[index-2] + num[index-3];
        if (target > max) return vector<vector<int> >();
        int min = num[0] + num[1] + num[2] + num[3];
        if (target < min) return vector<vector<int> >();
        vector<int> unique_num;
        vector<int> appear_times;
        unique_num.push_back(num[0]);
        appear_times.push_back(1);
        for (int i = 1; i < num.size(); ++i) {
            if (num[i] == unique_num.back()) {
                appear_times.back()++;
            } else {
                unique_num.push_back(num[i]);
                appear_times.push_back(1);
            }
        }
        unordered_set<int> hashmap(unique_num.begin(), unique_num.end());
        vector<vector<int> > results;
        vector<int> result;
        // print(unique_num);
        // print(appear_times);
        fourSumRecur(hashmap, results, result, unique_num,
                     appear_times, 0, 0, target);
        return results;
    }


    bool existRecur(vector<vector<char> > &board, vector<vector<bool> > &visited, string &word, int current, int row, int col) {
        if (current == word.size()) return true;
        if (row-1 >= 0 && !visited[row-1][col] && board[row-1][col] == word[current]) {
            visited[row-1][col] = true;
            if (existRecur(board, visited, word, current+1, row-1, col)) {
                return true;
            }
            visited[row-1][col] = false;
        }
        if (row+1 < board.size() && !visited[row+1][col] && board[row+1][col] == word[current]) {
            visited[row+1][col] = true;
            if (existRecur(board, visited, word, current+1, row+1, col)) {
                return true;
            }
            visited[row+1][col] = false;
        }
        if (col-1 >= 0 && !visited[row][col-1] && board[row][col-1] == word[current]) {
            visited[row][col-1] = true;
            if (existRecur(board, visited, word, current+1, row, col-1)) {
                return true;
            }
            visited[row][col-1] = false;
        }
        if (col+1 < board[0].size() && !visited[row][col+1] && board[row][col+1] == word[current]) {
            visited[row][col+1] = true;
            if (existRecur(board, visited, word, current+1, row, col+1)) {
                return true;
            }
            visited[row][col+1] = false;
        }
        return false;
    }


    bool exist(vector<vector<char> > &board, string word) {
        if (board.size() == 0) return false;
        if (word.size() == 0) return true;
        vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (existRecur(board, visited, word, 1, i, j)) {
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }


    int countRef(const string &s, int ref) {
        int count = 1;
        for (int i = ref+1; i < s.size() && s[i] == s[ref]; ++i, ++count) {
        }
        return count;
    }

    bool isInterleaveRecur(const string &s1,
                           const string &s2,
                           const string &s3,
                           int i1, int i2, int i3) {
        // cout <<"new thread\n";
        if (i1 == s1.size()) {
            // cout <<i1 <<", " <<i2 <<", " <<i3 <<endl;
            int len = s2.size() - i2;
            if (s2.compare(i2, len, s3, i3, len) == 0) {
                return true;
            } else {
                return false;
            }
        }
        if (i2 == s2.size()) {
            // cout <<i1 <<", " <<i2 <<", " <<i3 <<endl;
            int len = s1.size() - i1;
            if (s1.compare(i1, len, s3, i3, len) == 0) {
                return true;
            } else {
                return false;
            }
        }
        while(i3 != s3.size()) {
            // cout <<i1 <<", " <<i2 <<", " <<i3 <<endl;
            if (s3[i3] == s1[i1] && s3[i3] == s2[i2]) {
                int t1 = countRef(s1, i1);
                int t2 = countRef(s2, i2);
                int t3 = countRef(s3, i3);
                if (t3 < t1 && t3 < t2) {
                    return false;
                } else if (t3 > t1+t2) {
                    return false;
                } else if (t3 == t1+t2) {
                    i3 += t3;
                    i2 += t2;
                    i1 += t1;
                } else if (t3 >= t1 && t3 >= t2) {
                    if (isInterleaveRecur(s1, s2, s3, i1+t1, i2+t3-t1, i3+t3)){
                        return true;
                    }
                    if (isInterleaveRecur(s1, s2, s3, i1+t3-t2, i2+t2, i3+t3)) {
                        return true;
                    }
                    return false;
                } else if (t3 >= t1) {
                    i1 += t1;
                    i3 += t3;
                    i2 += (t3-t1);
                } else if (t3 >= t2) {
                    i2 += t2;
                    i3 += t3;
                    i1 += (t3-t2);
                }
            } else if (s3[i3] == s1[i1]) {
                i3++;
                i1++;
            } else if (s3[i3] == s2[i2]) {
                i3++;
                i2++;
            } else {
                return false;
            }
            if (i1 == s1.size() || i2 == s2.size()) {
                return isInterleaveRecur(s1, s2, s3, i1, i2, i3);
            }
        }
        return false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        return isInterleaveRecur(s1, s2, s3, 0, 0, 0);
    }

//     Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

// For "(()", the longest valid parentheses substring is "()", which has length = 2.

// Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
    int longestValidParentheses(string s) {
        vector<char> char_stack;
        vector<int> index_stack;
        for (int i = 0; i < s.size(); ++i) {
            if (char_stack.empty() ||char_stack.back() == ')' || s[i] == '('){
                char_stack.push_back(s[i]);
                index_stack.push_back(i);
            } else {
                char_stack.pop_back();
                index_stack.pop_back();
            }
        }
        if (index_stack.size() == 0) return s.size();
        int longest = index_stack[0];
        for (int i = 1; i < index_stack.size(); ++i) {
            if (index_stack[i]-index_stack[i-1]-1 > longest) {
                longest = index_stack[i] - index_stack[i-1] - 1;
            }
        }
        if(s.size()-index_stack.back()-1 > longest) {
            longest = s.size()-index_stack.back()-1;
        }
        return longest;
    }


// S: "barfoothefoobarman"
// L: ["foo", "bar"]
// 先find 第一个 然后
// 1. 往前搜L中其他的
// 2. 往后搜L中其他
// 1234123

// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

// For example,
// S = "ADOBECODEBANC"
// T = "ABC"
// Minimum window is "BANC".

// Note:
// If there is no such window in S that covers all characters in T, return the emtpy string "".

// If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.


// find median


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



    // void reorderList(ListNode *head) {
    //     // O(1) space O(n) time

    // }
// Given a string s, partition s such that every substring of the partition is a palindrome.

// Return the minimum cuts needed for a palindrome partitioning of s.

// For example, given s = "aab",
// Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

    // int minCut(string s) {

    // }


// Implement regular expression matching with support for '.' and '*'.

// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.

// The matching should cover the entire input string (not partial).

// The function prototype should be:
// bool isMatch(const char *s, const char *p)

// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "a*") → true
// isMatch("aa", ".*") → true
// isMatch("ab", ".*") → true
// isMatch("aab", "c*a*b") → true

    // "bbbba", ".*a*a"

    // bool isMatchRecur(const char *s, const char *c, int s_i, int c_i) {
    //     if (s[s_i] == '\0') {
    //         for (int i = c_i; c[i] != '\0'; i+=2) {
    //             if (c[i] != '\0' && c[i+1] != '*') {
    //                 return false;
    //             }
    //         }
    //         return true;
    //     } else if (c[c_i] == '\0') {
    //         return false;
    //     } else if (s[s_i] == c[c_i] || c[c_i] == '.') {
    //         if (c[c_i+1] == '*') {
    //             // check dupe char*
    //             int i = c_i +2;
    //             for (; c[i] != '\0' &&
    //                  c[i] == c[c_i] && c[i+1] == '*'; i+=2) {

    //             }
    //             c_i = i-2;
    //             return isMatchRecur(s, c, s_i+1, c_i)||
    //             isMatchRecur(s, c, s_i+1, c_i+2)||
    //             isMatchRecur(s, c, s_i, c_i+2);
    //         } else {
    //             return isMatchRecur(s, c, s_i+1, c_i+1);
    //         }
    //     } else if (c[c_i+1] == '*') {
    //         return isMatchRecur(s, c, s_i, c_i+2);
    //     }
    //     return false;
    // }

    // bool isMatch(const char *s, const char *p) {
    //     return isMatchRecur(s, p, 0, 0);
    // }

// Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

// Only one letter can be changed at a time
// Each intermediate word must exist in the dictionary
// For example,

// Given:
// start = "hit"
// end = "cog"
// dict = ["hot","dot","dog","lot","log"]
// As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.

// Note:
// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.
    // int ladderLengthRecur(unordered_map<string, int> &visited, string current,
    //                       int length) {
    //     unordered_set<string>::iterator got;
    //     got = visited.find(current);
    //     if (got == visited.end()) {
    //         visited.insert({current, length});
    //     } else if (got->second > length) {
    //         got->second = length;
    //     }
    // }
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

    // Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

// For example,
// S = "ADOBECODEBANC"
// T = "ABC"
// Minimum window is "BANC".

// Note:
// If there is no such window in S that covers all characters in T, return the emtpy string "".

// S: "barfoothefoobarman"
// L: ["foo", "bar"]
// 先find 第一个 然后
// 1. 往前搜L中其他的
// 2. 往后搜L中其他
// 1234123

    int matchWord(string &S, int start, vector<string> &L) {
        if (start < 0) return -1;
        for (int i = 1; i < L.size(); ++i){
            int j = 0;
            for (; j < L[0].size() && start+j < S.size()
                 && S[start+j] == L[i][j]; ++j) {
            }
            if (j == L[0].size()) {
                return i;
            }
        }
        return -1;
    }

    vector<int> findSubstring(string S, vector<string> &L) {
        int word_len = L[0].size();
        int len = L.size();
        int found = S.find(L[0]);
        vector<bool> flags(len, false);
        vector<int> order(2*len, -1);
        int word_index;
        int start;
        int end;
        int char_index;
        vector<int> result;
        while (found != string::npos) {
            // cout <<"found:" <<found <<endl;
            order[len] = 0;
            flags[0] = true;
            start = len;
            end = len+1;
            for (int i = 0; i < flags.size(); ++i) {
                flags[i] = false;
            }
            for (; end < order.size(); ++end) {
                char_index = found + word_len*(end-start);
                word_index = matchWord(S, char_index, L);
                // cout <<"wordindex:" <<word_index <<endl;
                if (word_index == -1 || flags[word_index]) {
                    break;
                }
                flags[word_index] = true;
                order[end] = word_index;
            }
            end--;
            // cout <<start <<", " <<end <<endl;
            //if we don't have a match
            if (end-start+1 != L.size()) {
                start--;
                for (; end-start < L.size(); --start) {
                    char_index = found - word_len*(len-start);
                    word_index = matchWord(S, char_index, L);
                    // cout <<"wordindex:" <<word_index <<endl;
                    if (word_index == -1 || flags[word_index]) {
                        break;
                    }
                    flags[word_index] = true;
                    order[start] = word_index;
                }
                start++;
            }
            // cout <<start <<", " <<end <<endl;
            //if we have a mtach;
            if (end-start+1 == L.size()) {
                char_index = found - word_len * (len-start);
                result.push_back(char_index);
                // cout <<found <<endl;
                // print(result);
                start--;
                while (start > 0) {
                    // cout <<start <<", " <<end <<endl;
                    char_index = found - word_len * (len-start);
                    word_index = matchWord(S, char_index, L);
                    if (word_index == -1) break;
                    if (flags[word_index]) {
                        while(end != 0 && order[end] != word_index) {
                            flags[order[end]] = false;
                            end--;
                        }
                        end--;
                    } else {
                        flags[word_index] = true;
                        order[start] = word_index;
                    }
                    if (end-start+1 == L.size()) {
                        char_index = found - word_len * (len-start);
                        result.push_back(char_index);
                    }
                    start--;
                }
            }
            //finished this found
            found = S.find(L[0], found+1);
        }
        return result;
    }


    int divide(int dividend, int divisor) {
        int threshold = pow(2,sizeof(int)*8-2);
        unsigned int unsigned_dividend;
        unsigned int unsigned_divisor;

        // if (divisor == -divisor) return 0;
        // cout <<threshold<<endl;
        // print(divisor > dividend)
        int flag = 1;
        if (dividend < 0) {
            // cout <<dividend <<endl;
            unsigned_dividend = -dividend;
            flag = -flag;
        } else {
            unsigned_dividend = dividend;
        }
        if (divisor < 0) {
            // cout <<divisor <<endl;
            flag = -flag;
            unsigned_divisor = -divisor;
        } else {
            unsigned_divisor = divisor;
        }
        // cout <<unsigned_dividend <<"," <<unsigned_divisor <<endl;
        if (unsigned_divisor > unsigned_dividend) return 0;
        unsigned int result = 0;
        unsigned int temp_result = 1;
        unsigned int temp_divisor = unsigned_divisor;
        while (unsigned_dividend > temp_divisor) {
            temp_divisor<<=1;
            temp_result<<=1;
            // cout <<temp_divisor<<endl;
        }
        if (unsigned_dividend == temp_divisor) {
            // temp_result = 1;
            // int i = -temp_result;
            // cout <<temp_result <<", " <<int(-temp_result) <<endl;
            return flag > 0? temp_result:-temp_result;
        }
        // if (unsigned_dividend < temp_divisor) {
        //     temp_divisor>>=1;
        //     temp_result>>=1;
        // }
        // cout <<temp_divisor <<endl;
        while (temp_divisor >= unsigned_divisor) {
            temp_divisor>>=1;
            temp_result>>=1;
            if (unsigned_dividend >= temp_divisor) {
                result = result^temp_result;
                unsigned_dividend -= temp_divisor;
                if (unsigned_dividend < unsigned_divisor) break;
            }
        }
        // int final_result = -result
        // cout <<result <<endl;
        // cout <<result <<"," <<-result <<endl;
        return flag > 0? result: -result;
        // return dividend/divisor;
    }

    void reverseWords(string &s) {
        int start;
        int end;
        vector<string> stack;
        for (int i = 0; i < s.size(); ++i) {
            while (i < s.size() && s[i] == ' ') {
                ++i;
            }
            if (i < s.size() && s[i] != ' ') {
                start = i;
                ++i;
                while (i < s.size() && s[i] != ' ') {
                    ++i;
                }
                end = i;
                stack.push_back(s.substr(start, end-start));
            }
        }
        print(stack);
        s.clear();
        while(stack.size()!=1) {
            s.append(stack.back());
            s.append(" ");
            stack.pop_back();
        }
        s.append(stack.back());
        // return s;
    }


    //1
    //-1
    //111.1
    //1/11
    //1+2i
    bool isNumber(const char *s) {
        int i = 0;
        int dot_flag = 0;
        while (s[i] == ' ') {
            ++i;
        }
        if (s[i] == '\0') {
            return false;
        } else if (s[i] == '-' || s[i] == '+') {
            i++;
            if (s[i] == '\0') {
                return false;
            }
        }
        if (s[i] == '.') {
            dot_flag = 1;
            i++;
        }
        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
        while (s[i] >= '0' && s[i] <='9') {
            ++i;
        }
        //match first set of numbers
        //s[i] now is not number
        if (s[i] == '.') {
            if (dot_flag == 1) return false;
            i++;
            while (s[i] >= '0' && s[i] <= '9') ++i;
            if (s[i] == 'e') {
                i++;
                if (s[i] == '+' || s[i] == '-') i++;
                if (s[i] < '0' || s[i] >'9') return false;
            }
            while (s[i] >= '0' && s[i] <= '9') ++i;
        } else if (s[i] == 'e' || s[i] == '/') {
            i++;
            if (s[i] == '+' || s[i] == '-') i++;
            if (s[i] < '0' || s[i] > '9') return false;
            while (s[i] >= '0' && s[i] <= '9') ++i;
        } else if (s[i] == '+' || s[i] == '-') {
            ++i;
            if (s[i] < '0' && s[i] > '9') return false;
            while (s[i] >= '0' && s[i] <= '9') ++i;
            if (s[i] != 'i') return false;
            ++i;
        }
        if (s[i] == ' ') {
            while (s[i] == ' ') ++i;
            if (s[i] == '\0') return true;
            else return false;
        }
        if (s[i] == '\0') {
            return true;
        } else {
            return false;
        }
    }
// 1234567890 12345 1 1 1 1
    bool isMatchRecur(const char *s, const char *p, int s_i, int p_i,
                      const int &s_len, int p_remain_char) {
        if (s[s_i] == '\0') {
            for (; p[p_i] != '\0'; ++p_i) {
                if (p[p_i] != '*') return false;
            }
            return true;
        }
        if (p[p_i] == '\0') {
            return false;
        }
        if (s[s_i] == p[p_i] || p[p_i] == '?') {
            return isMatchRecur(s, p, s_i+1, p_i+1, s_len, p_remain_char-1);
        } else if (p[p_i] == '*') {
            int dot_length = 0;
            while (p[p_i] == '*' || p[p_i] == '?') {
                if (p[p_i] == '?') dot_length++;
                p_i++;
            }
            //now least length is dot_length
            //anchor is p[p_i]
            int i = 0;
            for (; s[s_i] != '\0' && i < dot_length; ++i) {
                s_i++;
            }
            if (i != dot_length) return false;
            if (p[p_i] == '\0') return true;
            //0 1 2 3
            //0 1 2
            while ((s_len-s_i) >= p_remain_char) {
                if (s[s_i] == p[p_i] &&
                    isMatchRecur(s, p, s_i+1, p_i+1, s_len, p_remain_char-1)) {
                    return true;
                }
                s_i++;
            }
            return false;
        }
        return false;
    }
    bool isMatch(const char *s, const char *p) {
        int s_len = 0;
        while (s[s_len] != '\0') s_len++;
        int p_len = 0;
        while (p[p_len] != '\0') {
            if (p[p_len] != '*') {
                p_len++;
            }
        }
        return isMatchRecur(s, p, 0, 0, s_len, p_len);
    }


    vector<string> reverse (const vector<string> &temp) {
        vector<string> result;
        for (int i = temp.size()-1; i >= 0; --i) {
            result.push_back(temp[i]);
        }
        return result;
    }

    void ladderConstructReset(vector<vector<string> > &results,
                              vector<string> &result,
                              string current,
                              const string &start,
                              unordered_map<string, vector<string> > &tree) {
        // if (current_height > height) return;
        if (current == start) {
            result.push_back(start);
            results.push_back(reverse(result));
            result.pop_back();
            // cout <<results.size() <<endl;
        } else {
            result.push_back(current);
            unordered_map<string, vector<string> >::const_iterator got;
            got = tree.find(current);
            // print(got->second);
            for (int i = 0; i < got->second.size(); ++i) {
                ladderConstructReset(results, result, got->second[i],
                                     start, tree);
            }
            result.pop_back();
        }
    }

    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        vector<string> result;
        vector<vector<string> > results;

        unordered_map<string, vector<string> > tree;
        //this variable records the parents nodes for each node, the string
        unordered_set<string> not_visit_again;
        //add the string to this set, if we don't want to visit it again
        // vector<string> strings_index;
        //try to
        vector<string> visiting_strings;
        vector<string> tovisit_strings;
        bool found = false;
        visiting_strings.push_back(start);
        string temp;
        unordered_set<string>::const_iterator got;
        unordered_set<string>::const_iterator not_visit_got;
        unordered_map<string, vector<string>>::iterator tree_got;
        // int height = 0;
        while (!visiting_strings.empty()) {
            // height++;
            not_visit_again.insert(visiting_strings.begin(),
                                   visiting_strings.end());
            for (int i = 0; i < visiting_strings.size(); ++i) {
                temp = visiting_strings[i];
                for (int j = 0; j < visiting_strings[i].size(); ++j) {
                    for (char t = 'a'; t <= 'z'; ++t) {
                        temp[j] = t;
                        got = dict.find(temp);
                        // not_visit_got = dict.find(temp)
                        if (got != dict.end()) { //if this word exists
                            not_visit_got  = not_visit_again.find(temp);
                            if (not_visit_got == not_visit_again.end()) {
                                tree_got = tree.find(temp);
                                if (tree_got == tree.end()) {
                                    tree.insert({temp, {visiting_strings[i]}});
                                    tovisit_strings.push_back(temp);
                                    if (temp == end) {
                                        found = true;
                                        break;
                                    }
                                } else {
                                   tree_got->second.push_back(visiting_strings[i]);
                                }
                            }

                        }
                    }
                    // if (found) break;
                    temp[j] = visiting_strings[i][j];
                }
            }
            if (found) break;
            visiting_strings = tovisit_strings;
            tovisit_strings.clear();
        }
        // print(found);
        if (found) {
            ladderConstructReset(results, result, end, start, tree);
        }
        // cout <<height  <<endl;
        return results;
    }






// Requirements for atoi:
// The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

// The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

// If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

// If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.





    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> results;
        string line;
        int start;
        int end;
        int probe = 0;
        int space_num;
        int each_space;
        while (probe < words.size()) { //for each line
            start = probe;
            end = start;
            space_num = L - words[probe].size() - 1;
            // cout <<space_num <<endl;
            probe++;
            while (probe < words.size() && space_num >= (int)words[probe].size()) {
                space_num -= (words[probe].size()+1);
                end = probe;
                probe++;
            }
            space_num++;
            line = words[start];
            start++;
            if (probe != words.size()) {
                while (start <= end) {
                    each_space = space_num/(end-start+1);
                    if (each_space*(end-start+1) < space_num) {
                        each_space++;
                    }
                    line.append(each_space+1, ' ');
                    line.append(words[start]);
                    start++;
                    space_num -= each_space;
                }
            } else {
                while (start <= end) {
                    line.append(" ");
                    line.append(words[start]);
                    start++;
                }
            }
            if (space_num > 0) {
                line.append(space_num, ' ');
            }
            results.push_back(line);
        }
        return results;
    }

// ["What","must","be","shall","be."], 12
// Output: ["What must be","shall    be."]
// Expected:   ["What must be","shall be.   "]

//     ["Listen","to","many,","speak","to","a","few."], 6
// Output: ["Listen","to","many,","speak","to   a","few.  "]
// Expected:   ["Listen","to    ","many, ","speak ","to   a","few.  "]

    // double findMedianSortedArrays(int A[], int m, int B[], int n) {
    //     int A_start = 0;
    //     int A_end = m;
    //     int B_start = 0;
    //     int B_end = n;


    // }

    bool isValid(const int &row, const int &col,
                 const int i, const int j) {
        if (i < 0 || j < 0) return false;
        if (i >= row || j >= col) return false;
        return true;
    }
    void markAliveO(vector<vector<char>> &board,
                    const int &row, const int &col,
                    int i, int j){
        if (board[i][j] != 'O') {
            return;
        }
        board[i][j] = 'S';
        if (isValid(row, col, i+1, j)) {
            markAliveO(board, row, col, i+1, j);
        }
        if (isValid(row, col, i-1, j)) {
            markAliveO(board, row, col, i-1, j);
        }
        if (isValid(row, col, i, j+1)) {
            markAliveO(board, row, col, i, j+1);
        }
        if (isValid(row, col, i, j-1)) {
            markAliveO(board, row, col, i, j-1);
        }
    }

    void solve(vector<vector<char>> &board) {
        if (board.size() == 0) return;
        int row = board.size();
        int col = board[0].size();
        for (int i = 0; i < col; ++i) {
            if (board[0][i] == 'O') {
                markAliveO(board, row, col, 0, i);
            }
            if (board[row-1][i] == 'O') {
                markAliveO(board, row, col, row-1, i);
            }
        }
        for (int i = 1; i < row-1; ++i) {
            if (board[i][0] == 'O') {
                markAliveO(board, row, col, i, 0);
            }
            if (board[i][col-1] == 'O') {
                markAliveO(board, row, col, i, col-1);
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'S') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    bool indexPlus(int &i, int &j, const int &N) {
        // cout <<i <<"," <<j <<"," <<N <<endl;
        j++;
        if (j == N*N) {
            i++;
            if (i == N*N) {
                return false;
            }
            j = 0;
        }
        return true;
    }

    bool solveSudokuRecur(vector<vector<char> > &board,
                          int i, int j,
                          const int &N) {
        do {
            // cout <<i <<"," <<j <<"," <<N <<endl;
            if (board[i][j] == '.') {
                vector<int> hash(N*N+1, 0);
                // print(hash);
                int temp;
                for (int s = 0; s < N*N; s++) {
                    if (board[s][j] != '.') {
                        temp = board[s][j] - '0';
                        // cout <<temp <<endl;
                        // if (hash[temp] == 1) return false;
                        hash[temp] = 1;
                    }
                    if (board[i][s] != '.') {
                        temp = board[i][s] - '0';
                        // cout <<temp <<endl;
                        // if (hash[temp] == 1) return false;
                        hash[temp] = 1;
                    }
                }
                // print(hash);
                for (int s = 0; s < N; s++) {
                    for (int t = 0; t < N; t++) {
                        if (board[i/N*N + s][j/N*N + t] != '.') {
                            temp = board[i/N*N + s][j/N*N + t] - '0';
                            // if (hash[temp] == 1) return false;
                            hash[temp] = 1;
                        }
                    }
                }
                // print(hash);
                for (int s = 1; s <= N*N; s++) {
                    if (hash[s] != 1) {
                        board[i][j] = '0' + s;
                        // print(board);
                        if (solveSudokuRecur(board, i, j, N)) {
                            return true;
                        }
                    }
                }
                board[i][j] = '.';
                return false;
            }
        } while(indexPlus(i, j, N));
        return true;
    }

    void solveSudoku(vector<vector<char> > &board) {
        int size = board.size();
        int N = sqrt(size);
        // cout<<N;
        solveSudokuRecur(board, 0, 0, N);
    }

     int atoi(const char *str) {
        int probe = 0;
        bool flag = false;
        unsigned int number = 0;
        unsigned int MAX = pow(2, sizeof(int)*8-1)-1;
        while(str[probe] == ' ') {
            probe++;
        }
        if (str[probe] == '+') {
            probe++;
        }else if (str[probe] == '-') {
            probe++;
            flag = true;
        }
        while(str[probe]>='0' && str[probe]<='9') {
            if (number > MAX/10) {
                return flag ? (-MAX-1) : MAX;
            } else if (number == MAX/10) {
                if (flag) {
                    if (str[probe] >= '8') return (-MAX-1);
                } else {
                    if (str[probe] >= '7') return MAX;
                }
            }
            number = number*10+str[probe]-'0';
            probe++;
        }
        return !flag?number:-number;
    }

class LRUCache{
public:
    LRUCache(int _capacity) {
        capacity = _capacity;
        current_capacity = 0;
    }

    int get(int key) {
        got = cache.find(key);
        if (got != cache.end()) {
            move2Front(got);
            return got->second.first;
        }
        return -1;
    }

    void set(int key, int value) {
        got = cache.find(key);
        if (got != cache.end()) {
            move2Front(got);
            got->second.first = value;
        } else {
            if (current_capacity == capacity) {
                cache.erase(keys.back());
                keys.pop_back();
                current_capacity--;
            }
            keys.push_front(key);
            cache.insert({key,{value, keys.begin()}});
            current_capacity++;
        }
    }

    void move2Front(unordered_map<int, pair<int, list<int>::iterator>>::iterator got) {
        keys.erase(got->second.second);
        keys.insert(keys.begin(), got->first);
        got->second.second = keys.begin();
    }
private:
    list<int> keys;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    int capacity;
    int current_capacity;
    unordered_map<int, pair<int, list<int>::iterator>>::iterator got;
};

int subStr(string main, string word) {
    //initial[1] = 0 construct initial
    vector<int> initial(word.size()+1, 0);
    int pre;
    int post;
    for (int len = 2; len <= word.size(); ++len) {
        for (int i = 1; i < len; ++i) {
            pre = 0;
            post = i;
            while (post < len && word[pre] == word[post]) {
                pre++;
                post++;
            }
            if (post == len) {
                initial[len] = len-i;
                break;
            }
        }
    }
    print(initial);

    //find substring
    int start = 0;
    int probe = 0;
    int i = 0;
    while (probe < main.size()) {
        cout <<start <<"," <<probe <<", " <<i <<endl;
        i = probe-start;
        while (probe < main.size() && i < word.size() &&
               main[probe] == word[i]) {
            probe++;
            i++;
        }
        if (i == word.size()) {
            return start;
        } else if (start == probe) {
            start++;
            probe++;
        } else {
            start = probe - initial[probe-start];
            // probe++;
        }
    }
    return -1;
}

class Solution {
public:
    int getkth(int s[], int m, int l[], int n, int k){
        // let m <= n
        if (m > n)
            return getkth(l, n, s, m, k);
        if (m == 0)
            return l[k - 1];
        if (k == 1)
            return min(s[0], l[0]);

        int i = min(m, k / 2), j = min(n, k / 2);
        if (s[i - 1] > l[j - 1])
            return getkth(s, m, l + j, n - j, k - j);
        else
            return getkth(s + i, m - i, l, n, k - i);
        return 0;
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int l = (m + n + 1) >> 1;
        int r = (m + n + 2) >> 1;
        return (getkth(A, m ,B, n, l) + getkth(A, m, B, n, r)) / 2.0;
    }
};

int main() {
    //test substring
    cout <<subStr("abcabdabcabdabdabdabdabc", "abcabdabd");
    //test lri
    // list<int> keys = {1,2,3,4,5};
    // unordered_map<int, pair<int, list<int>::iterator>> cache;
    // keys.erase(++keys.begin());
    // LRUCache myCache(1);
    // myCache.set(2,1);
    // cout <<myCache.get(2);
    // myCache.set(3,2);
    // cout <<myCache.get(2);
    // cout <<myCache.get(3);

    //test atoi
    // char temp[] = "    10522545459";
    // char *str = temp;
    // cout <<atoi(str);
    //test sudoku
    // vector<vector<char> > board =
    // vector<string> string_data = {"53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79"};
    // vector<vector<char> > board = convert(string_data);
    // print(board);
    // solveSudoku(board);
    // print(board);

    // test solve
    // vector<vector<char>> board = {{'X','X','X'}, {'X','O','X'},
    // {'X','O','X'}};
    // print(board);
    // solve(board);
    // print(board);
    //test fullJustify
    // vector<string> words = {"Listen","to","many,","speak","to","a","few."};
    // print(fullJustify(words, 6));

    // string start = "red";
    // string end = "tax";
    // unordered_set<string> dict = {"ted","tex","red","tax","tad","den","rex","pee"};
    // string start = "nanny";
    // string end = "aloud";

    // print(findLadders(start, end, dict));

    //test ismatch
    // char s_t[] = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb";
    // char p_t[] = "**aa*****";
    // char *s = s_t;
    // char *p = p_t;
    // print(isMatch(s, p));
    //test isNumber
    // char temp[] = "00e+6";
    // char *s = temp;
    // print(isNumber(s));
    // int a = '0';
    // int b = '9';
    // cout <<a <<"," <<b <<endl;

    //test findLadders
    // unordered_set<string> dict = {"hit", "cog", "hot","dot","dog","lot","log"};
    // print(findLadders("hit", "cog", dict));

    //test reverseWords
    // string test = "theisblue";
    // cout <<test.substr(0,2);
    // reverseWords(test);
    // cout <<"|" <<test <<"|" <<endl;

    //test numDecodings
    // int a = -10;
    // int b = -1;
    // int d = -2147483648;
    // unsigned int f = -d;
    // cout <<f <<endl;
    // cout <<-a;
    // cout <<divide(2147483647, 1) <<endl;
    // cout <<divide(1231241231, -2147483648) <<endl;
    // cout <<divide(13, 3) <<endl;
    // cout <<divide(-13, 3) <<endl;
    // cout <<divide(-2147483648, 1) <<endl;
    // cout <<divide(2147483648, 2) <<endl;
    // cout <<divide(-2147483647, 2147483647) <<endl;
    // cout <<divide(12, 12) <<endl;
    // int c = 2147483648;
    // cout <<c;
    // print(a<0);
    // b = -b;
    // cout <<b;
    // int *dp = new int[a+2];
    // dp[1] = 2;
    // int b = a^a;
    // cout <<a;//pow(2,sizeof(int)*8);
    // cout <<divide(1010369383,2147483648);
    // print(a<b);
    //test find substring
    // "barfoothefoobarman", ["foo","bar"]
    // vector<string> L = {"foo","bar"};
    // string S = "barfoothefoobarman";
    // cout <<matchWord(S, 0, L);
    // print(findSubstring(S, L));


    // unordered_set<string> dict({"a", "b", "c"});
    // cout <<ladderLength("a", "b", dict);
    //test isMatch
    // char t1[] = "aaaaaaaaaaaaab";
    // char t2[] = "a*a*a*a*a*a*a*a*a*a*c";
    // char *s = t1;
    // char *p = t2;
    // print(isMatch(s, p));
    // char *s = "abc";

    // cout <<simplifyPath("//aaa/b");
    // int i = stoi("3");
    // int j = stoi("-4");
    // cout <<stoi("-3");
    //test eval RPN
    // cout <<evalRPN

    //test longest valid parentheses
    // cout <<longestValidParentheses("(((()");


    //test interleave
    //acbcaabaccacacc
    //123456789
    //bbbcbbcacc
    //acbcaabbbbacbcbcacccacacc
    // if (isInterleave("cabbacccabacbcaabaccacacc",
    //     "bccacbacabbabaaacbbbbcbbcacc",
    //     "cbccacabbacabbbaacbcacaaacbbacbcaabbbbacbcbcacccacacc")) {
    // if (isInterleave(
    //     "abbacccabacbcaabaccacacc",
    //     "bccacbacabbabaaacbbbbcbbcacc",
    //     "bccacabbacabbbaacbcacaaacbbacbcaabbbbacbcbcacccacacc")) {
    //     cout <<"true" <<endl;
    // } else {
    //     cout <<"false" <<endl;
    // }
    //test exist
    // char m[2][2] = {'a', 'b', 'c', 'd'};
    // char *p = &m[0][0];
    // vector<vector<char> > matrix = constructMatrix(p, 2, 2);
    // if (exist(matrix, "acdb")) cout <<"exist\n";

    //test fourSum
    // int num[] = {-5,-2,-4,-2,-5,-4,0,0};
    // vector<int> num_vector(num, num + sizeof(num)/sizeof(int));
    // print(fourSum(num_vector, -13));
    // int number[] =  {1,1,-1,-1,3};
    // int number[] = {5, 1, 1};
    //test threeSumClosest
    /*
    vector<int> num(number, number+sizeof(number)/sizeof(int));
    cout <<threeSumClosest(num, 1);
    */

    //test partition
    /*
    ListNode *head = new ListNode(2);
    ListNode *second = new ListNode(1);
    head->next = second;
    ListNode *new_head = partition(head, 2);
    while(new_head!=NULL) {
        cout <<new_head->val <<", ";
        new_head = new_head->next;
    }
    cout <<endl;
    */

    //test testSubsetWithDup
    // vector<int> num(number, number+sizeof(number)/sizeof(int));
    // print(subsetsWithDup(num));

    //test next permutation
    // vector<int> num(number, number+sizeof(number)/sizeof(int));
    // print(num);
    // nextPermutation(num);
    // print(num);

    //test canCompleteCircuit
    // int gas_num[] = {1, 2};
    // int cost_num[] = {2, 1};
    // vector<int> gas(gas_num, gas_num + sizeof(gas_num)/sizeof(int));
    // vector<int> cost(cost_num, cost_num + sizeof(cost_num)/sizeof(int));
    // cout <<canCompleteCircuit(gas, cost);

    //test insertionSortList
    // int nums[] = {3, 2, 4};
    // vector<int> nums_vector(nums, nums + sizeof(nums)/sizeof(int));
    // ListNode *head = constructList(nums_vector);
    // print(insertionSortList(head));

    //test jump
    // int A[] = {2, 3, 1, 1, 4};
    // cout <<jump(A, 5);

    //test deleteDuplicates
    // int nums[] = {0, 1, 1, 3, 4};
    // vector<int> nums_vector(nums, nums + sizeof(nums)/sizeof(int));
    // ListNode *head = constructList(nums_vector);
    // print(deleteDuplicates(head));

    //test permuteUnique
    // int nums[] = {1, 3, 2};
    // vector<int> nums_vector(nums, nums + sizeof(nums)/sizeof(int));
    // print(permuteUnique(nums_vector));

    //test reverseKGroup
    // int nums[] = {2, 1, 5};
    // vector<int> nums_vector(nums, nums + sizeof(nums)/sizeof(int));
    // ListNode *head = constructList(nums_vector);
    // print(reverseKGroup(head, 2));
    // cout <<"result:" <<endl;
    // print(nums_vector);
    // int result = maxProfit(nums_vector);
    // cout <<result <<endl;

    //test maxrectangle
    // char m[2][2] = {'0', '1', '0', '1'};
    // vector<int> temp {1, 2, 3};
    // char m[5][6] = {'0','1','1','0','1',
    // '1','1','0','1','0',
    // '1','1','1','1','0',
    // '0','1','1','1','1',
    // '1','1','1','1','1',
    // '0','0','0','0','0'};
    // char *p = &m[0][0];
    // vector<vector<char> > matrix = constructMatrix(p, 5, 6);
    // print(matrix);
    // cout <<maximalRectangle(matrix) <<endl;

    //test sort
    // int nums[] = {4,19,14,5,-3,1,8,5,11,15};
    // vector<int> nums_vector(nums, nums + sizeof(nums)/sizeof(int));
    // ListNode *head = constructList(nums_vector);
    // head = sortList(head);
    // print(head);

    //test spiralOrder
    // int m[] = {1, 1, 1, 2, 0};
    // int *p = &m[0];
    // vector<vector<int> > matrix = constructMatrix(p, 3, 3);
    // print(matrix);
    // print(spiralOrder(matrix));

    //test merge Interval
    // int nums[] = {};//{16, 100, 1, 3, 2, 6, 8, 15, 15, 18};
    // vector<int> nums_vector;//(nums, nums + sizeof(nums)/sizeof(int));
    // vector<Interval> intervals = constructInterval(nums_vector);
    // // print(intervals);
    // intervals = merge(intervals);
    // print(intervals);

    //test largestRectangleArea
    // int nums[] = {2, 1, 2};
    // vector<int> nums_vector(nums, nums + sizeof(nums)/sizeof(int));
    // cout <<largestRectangleArea(nums_vector);

    //test string2int
    // string num1 = "101";
    // string num2 = "101";
    // cout <<to_string(001);
    // cout <<multiply(num1, num2);
}