#include <iostream>
#include <vector>

using namespace std;

struct listNode {
    listNode(int key) {
        m_key = key;
        next = nullptr;
    }

    int m_key;
    listNode* next;
};

void deleteList(listNode* head) {
    while (head) {
        listNode* curr = head;
        head = head->next;
        delete curr;
    }
}

listNode* mergeTwoSortedList(listNode* list1, listNode* list2) {
    listNode tmpHead(-1);
    for (listNode* curr = &tmpHead; list1 != nullptr || list2 != nullptr; curr = curr->next) {
        if (nullptr == list1) { curr->next = list2; break;}
        if (nullptr == list2) { curr->next = list1; break;}
        if (list1->m_key <= list2->m_key) {
            curr->next = list1;
            list1 = list1->next;
        } else {
            curr->next = list2;
            list2 = list2->next;
        }
    }

    return tmpHead.next;
}

listNode* mergeKSortedList(vector<listNode*> &vecList) {
    if (0 == vecList.size()) return nullptr;

    listNode* list = vecList[0];
    for (int i = 1; i < vecList.size(); i++) {
        list = mergeTwoSortedList(list, vecList[i]);
    }

    return list;
}

int main() {
    vector<listNode*> vecList;
    for (int loop = 4; loop > 0; loop--) {
        listNode head(-1);
        listNode *curr = &head;
        for (int i = 0; i < 10; i++) {
            listNode* tmp = new listNode(loop*i);
            curr->next = tmp;
            curr = curr->next;
        }
        curr->next = nullptr;
        vecList.push_back(head.next);
    }

    listNode* list = mergeKSortedList(vecList);
    listNode* head = list;

    while (head) {
        std::cout << head->m_key << " ";
        head = head->next;
    }
    std::cout << std::endl;

    deleteList(list);

    return 0;
}
