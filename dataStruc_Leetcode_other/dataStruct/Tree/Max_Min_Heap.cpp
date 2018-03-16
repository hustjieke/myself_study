// 二叉堆,这里设定根元素在0上(索引为i的左孩子的索引是 (2*i+1);索引为i的右孩子的
// 索引是(2*i+2));索引为i的父结点的索引是 floor((i-1)/2);
// 如果设定根元素在1上,索引为i的左孩子的索引是 (2*i);索引为i的左孩子的索引是(2*i+1);
// 索引为i的父结点的索引是 floor(i/2);

#include <iostream>

using namespace std;

template<typename T>
class MaxHeap {
public:
    explicit MaxHeap(size_t size);
    ~MaxHeap();
    bool insert(T data);
    bool remove(T data);
    int getIndex(T data);
    void print();

private:
    MaxHeap() { }
    void adjustUp(size_t index);
    void adjustDown(size_t index);

    size_t m_size;
    size_t m_capacity;
    T* m_heapArray;
};

template<typename T>
MaxHeap<T>::MaxHeap(size_t size) : m_size(0), m_capacity(size) {
    m_heapArray = new T[m_capacity];
}

template<typename T>
MaxHeap<T>::~MaxHeap() {
    m_size = 0;
    m_capacity = 0;
    delete []m_heapArray;
}

template<typename T>
void MaxHeap<T>::adjustUp(size_t index) {
    T tmp = m_heapArray[index];
    int child = index;
    int parentIndex = (child- 1) / 2;
    while (child > 0) {  // 这里我用的是parentIndex,网上用的child,哪里的逻辑有问题?
        cout << "now adjustUp" << endl;
        if (m_heapArray[parentIndex] < m_heapArray[child]) {
            m_heapArray[child] = m_heapArray[parentIndex];
            child = parentIndex;
            parentIndex = (child - 1) / 2;
        } else {  // 漏了这个else分支虽然不会错,但是会进行无意义的循环,直到root节点
            break;
        }
    }

    m_heapArray[child] = tmp;
}

template<typename T>
bool MaxHeap<T>::insert(T data) {
    if (m_size >= m_capacity)  return false;
    
    m_heapArray[m_size] = data;
    adjustUp(m_size);
    ++m_size;

    return true;
}

template<typename T>
int MaxHeap<T>::getIndex(T data) {
    for (size_t index = 0; index < m_size; ++index) {
        if (data == m_heapArray[index]) {
            return index;
        }
    }

    return -1;
}


template<typename T>
void MaxHeap<T>::adjustDown(size_t index) {
    size_t parentIndex = index;
    size_t child = 2 * parentIndex + 1;  // 左孩子索引
    T curData = m_heapArray[parentIndex];
    
    while (child < m_size) {
        cout << "adjustDown now" << endl;
        if (child < (m_size - 1) && m_heapArray[child] < m_heapArray[child + 1]) {
            ++child; // child是左孩子,child++是右孩子,m_size-1是防止若没有右孩子时越界
        }
        if (m_heapArray[parentIndex] < m_heapArray[child]) {
            m_heapArray[parentIndex] = m_heapArray[child];
            parentIndex = child;
            child = 2 * parentIndex + 1;
        } else {
            break;
        }
    }
    
    m_heapArray[parentIndex] = curData;
}

template<typename T>
bool MaxHeap<T>::remove(T data) {
    // 在此之前是否有必要增加堆为空的判断??降低性能?
    size_t index = getIndex(data);
    if (-1 == index) {
        return false;
    }
    m_heapArray[index] = m_heapArray[m_size];
    --m_size;  // 计数先递减,区别于adjustUp
    adjustDown(index);

    return true;
}

template<typename T>
void MaxHeap<T>::print() {
    for (int i = 0; i < m_size; ++i) {
        cout << m_heapArray[i] << " " << endl;
    }
}


int main()
{
    int arr[] = {10, 40, 30, 60, 90, 70, 20, 50, 80};
    int i, len=(sizeof(arr)) / (sizeof(arr[0]));
    MaxHeap<int>* heapTree = new MaxHeap<int>(1024);

    for (i = 0; i < len; ++i) {
        heapTree->insert(arr[i]);
    }

    cout << "最大堆:" << endl;
    heapTree->print();

    cout << "添加元素: " << i << endl;
    i = 85;
    heapTree->insert(i);
    cout << "最大堆:" << endl;
    heapTree->print();

    i = 90;
    cout << "删除元素: " << endl;
    heapTree->remove(i);
    cout << "最大堆:" << endl;
    heapTree->print();
    
    return 0;
}
