#include <iostream>

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


int main() {
    listNode head1(-1), head2(-1);
    listNode *curr1 = &head1;
    listNode *curr2 = &head2;
    for (int i = 0; i < 10; i++) {
        listNode* tmp = new listNode(2*i + 1);
        curr1->next = tmp;
        curr1 = curr1->next;
    }

    for (int i = 0; i < 10; i++) {
        listNode* tmp = new listNode(2*i + 2);
        curr2->next = tmp;
        curr2 = curr2->next;
    }
    listNode* list = mergeTwoSortedList(head1.next, head2.next);
    listNode* head = list;

    while (head) {
        std::cout << head->m_key << " ";
        head = head->next;
    }
    std::cout << std::endl;

    deleteList(list);

    return 0;
}
