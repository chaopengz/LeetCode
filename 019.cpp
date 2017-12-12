
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "head.h"


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1,*p2,*pre;
        p1=head;
        p2=head;
        pre=head;
        for(int i = 0; i < n-1 ;i++)
        {
            p1 = p1->next;
        }
        while(p1->next!= nullptr)
        {
            p1 = p1->next;
            pre = p2;
            p2 = p2->next;
        }

        if (p2 == head)
        {
            head = head->next;
        }
        pre->next = p2->next;

        return head;
    }
};
//
//void trimLeftTrailingSpaces(string &input) {
//    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
//        return !isspace(ch);
//    }));
//}
//
//void trimRightTrailingSpaces(string &input) {
//    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
//        return !isspace(ch);
//    }).base(), input.end());
//}
//
//vector<int> stringToIntegerVector(string input) {
//    vector<int> output;
//    trimLeftTrailingSpaces(input);
//    trimRightTrailingSpaces(input);
//    input = input.substr(1, input.length() - 2);
//    stringstream ss;
//    ss.str(input);
//    string item;
//    char delim = ',';
//    while (getline(ss, item, delim)) {
//        output.push_back(stoi(item));
//    }
//    return output;
//}
//
//ListNode* stringToListNode(string input) {
//    // Generate list from the input
//    vector<int> list = stringToIntegerVector(input);
//
//    // Now convert that list into linked list
//    ListNode* dummyRoot = new ListNode(0);
//    ListNode* ptr = dummyRoot;
//    for(int item : list) {
//        ptr->next = new ListNode(item);
//        ptr = ptr->next;
//    }
//    ptr = dummyRoot->next;
//    delete dummyRoot;
//    return ptr;
//}
//
//int stringToInteger(string input) {
//    return stoi(input);
//}
//
//string listNodeToString(ListNode* node) {
//    string result;
//    if (node == nullptr) {
//        return result;
//    }
//
//    while (node) {
//        result += to_string(node->val) + ", ";
//        node = node->next;
//    }
//    return result.substr(0, result.length() - 2);
//}
//
//int main() {
//    string line;
//    while (getline(cin, line)) {
//        ListNode* head = stringToListNode(line);
//        getline(cin, line);
//        int n = stringToInteger(line);
//
//        ListNode* ret = Solution().removeNthFromEnd(head, n);
//
//        string out = listNodeToString(ret);
//        cout << out << endl;
//    }
//    return 0;
//}