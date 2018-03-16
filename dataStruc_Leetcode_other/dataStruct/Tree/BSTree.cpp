// 二查搜索树的实现
//
#include <iostream>
#include <queue>
#include <memory>


using namespace std;

// 声明
template <typename T>
class BSTNode {
public:
    BSTNode(T key, BSTNode *left, BSTNode *right, BSTNode *parent) : m_key(key),
    m_left(left), m_right(right), m_parent(parent) { }

public:
    T m_key;
    BSTNode<T> *m_left;
    BSTNode<T> *m_right;
    BSTNode<T> *m_parent;  // 下一次实现的时候,不要考虑父节点
};

template <typename T>
class BSTree {
private:
    BSTNode<T> *m_root;

public:
    BSTree() { m_root = NULL; }
    ~BSTree() { }

public:
    void preOrder();
    void inOrder();
    void postOrder();
    void breadthOrder();
    void insert(T key);
    BSTNode<T>* search(T key);

private:
    // breadth first,使用队列实现
    void breadthOrder(BSTNode<T>* root) const;
    void preOrderImpl(BSTNode<T>* root) const;
    void inOrderImpl(BSTNode<T>* root) const;
    void postOrderImpl(BSTNode<T>* root) const;
    void insertImpl(BSTNode<T>* &root, BSTNode<T>* node) const;
    BSTNode<T>* searchImpl(BSTNode<T>* root, T key) const;
};

// 定义
template <typename T>
void BSTree<T>::preOrder() {
    preOrderImpl(m_root);
}

template <typename T>
void BSTree<T>::inOrder() {
    inOrderImpl(m_root);
}

template <typename T>
void BSTree<T>::postOrder() {
    postOrderImpl(m_root);
}

template <typename T>
void BSTree<T>::breadthOrder() {
    breadthOrder(m_root);
}

template <typename T>
void BSTree<T>::insert(T key) {
    BSTNode<T>* temp = NULL;
    if (NULL == (temp = new BSTNode<T>(key, NULL, NULL, NULL))) {
        return;
    }
    
    insertImpl(m_root, temp);
}

// root指针必须引用,不然只是一份指针的拷贝,其原来的0值不会改变
template <typename T>
void BSTree<T>::insertImpl(BSTNode<T>* &root, BSTNode<T>* node) const {
    BSTNode<T>* tmpRoot = root;
    BSTNode<T>* parent  = NULL;
    
    while (tmpRoot) {
        parent = tmpRoot;  // 用于最后空子节点的父节点,有用的
        if (node->m_key < tmpRoot->m_key) {
            tmpRoot = tmpRoot->m_left;
        } else {
            tmpRoot = tmpRoot->m_right;
        }
    }

    node->m_parent = parent;  // 如果root是NULL,那就是第一个节点,当然了root的父节点是NULL
    if (!parent) {  // 这意味着,tree是个空树
        root = node;
    } else if (node->m_key < parent->m_key) {
        parent->m_left = node;
    } else {
        parent->m_right = node;
    }
}

template <typename T>
void BSTree<T>::breadthOrder(BSTNode<T>* root) const {
    if (root) {
        std::queue<BSTNode<T> *> nodeQueue;
        nodeQueue.push(root);
        while (!nodeQueue.empty()) {
            BSTNode<T>* tmp = nodeQueue.front();
            nodeQueue.pop();
            cout << tmp->m_key << " ";
            if (tmp->m_left) {
                nodeQueue.push(tmp->m_left);
            }
            if (tmp->m_right) {
                nodeQueue.push(tmp->m_right);
            }
        }
    } else {
        cout << "empty tree.";
    }
}

template <typename T>
void BSTree<T>::preOrderImpl(BSTNode<T>* root) const {
    if (root) {
        cout << root->m_key << " ";
        preOrderImpl(root->m_left);
        preOrderImpl(root->m_right);
    }
}

template <typename T>
void BSTree<T>::inOrderImpl(BSTNode<T>* root) const {
    if (root) {
        inOrderImpl(root->m_left);
        cout << root->m_key << " ";
        inOrderImpl(root->m_right);
    }
}

template <typename T>
void BSTree<T>::postOrderImpl(BSTNode<T>* root) const {
    if (root) {
        postOrderImpl(root->m_left);
        postOrderImpl(root->m_right);
        cout << root->m_key << " ";
    }
}

template <typename T>
BSTNode<T>* BSTree<T>::search(T key) {
    searchImpl(m_root, key);
}

template <typename T>
BSTNode<T>* BSTree<T>::searchImpl(BSTNode<T>* root, T key) const {
#if 0  // for recursive
    if (!root || (key == root->m_key)) {
            return root;
    } else if (key < root->m_key) {
        searchImpl(root->m_left, key);
    } else {
        searchImpl(root->m_right, key);
    }
#else  // use while loop
    BSTNode<T>* tmp = root;
    while (tmp) {
        if (key == tmp->m_key) {
            return tmp;
        } else if (key < tmp->m_key) {
            tmp = tmp->m_left;
        } else {
            tmp = tmp->m_right;
        }
    }

    return tmp;  // now tmp must be NULL
#endif
}


// test
static int arr[] = {1,5,4,3,2,6};
#define ARRAY_SIZE(arr) ( (sizeof(arr)) / (sizeof(arr[0])) )

int main()
{
    // BSTree<int>* tree=new BSTree<int>();  // 为什么要加括号?
    shared_ptr<BSTree<int>> tree(new BSTree<int>());
    // BSTree<int>* tree=new BSTree<int>;  这样子也是对的

    cout << "依次添加: " << endl;
    int ilen = ARRAY_SIZE(arr);
    for(int i=0; i < ilen; i++) {
        cout << arr[i] <<" ";
        tree->insert(arr[i]);
    }
    cout << endl;

    cout << "preOrder: ";
    tree->preOrder();
    cout << endl;

    cout << "inOrder: ";
    tree->inOrder();
    cout << endl;

    cout << "postOrder: ";
    tree->postOrder();
    cout << endl;

    cout << "breadth order: ";
    tree->breadthOrder();
    cout << endl;

    // search
    int key = 4;
    BSTNode<int>* retNode = tree->search(key);
    cout << "retNode addr: " << retNode << " key value: " << retNode->m_key << endl;

    return 0;
}
