//**********************int_s_l_l_node.h***************************// 
// singly-linked list class to store integers
// CreatTime: 2016-5-31

#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST

class IntSLLNode {
    public:
        IntSLLNode() {
            next = 0;
        }

        IntSLLNode(int el, IntSLLNode *ptr = 0) {
            info = el;
            next = ptr;
        }
        int info;
        IntSLLNode *next;
};


#endif
