#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
template <typename T>
struct Node
{
    T value_;
    Node* prev_;
    Node* next_;
    Node()
    {
        prev_ = this;
        next_ = this;
    }
    Node(T value, Node* prev, Node* next)
    {
        value_ = value;
        prev_ = prev;
        next_ = next;
    }
};
template <typename T>
class List
{

private:
    Node<T>* dummy_;
    int size_;
public:
    List();
    ~List()
    {
        clear();
    }

    void add(T v, Node<T>* node);
    void push_front(T value);
    void push_back(T value);
    bool empty()
    {
        return dummy_->next_ == dummy_;
    }

    T remove(Node<T>* node);
    T pop_front()
    {
        Node<T>* cur = dummy_->next_;
        return remove(cur);
    }

    T pop_back()
    {
        Node<T>* cur = dummy_->prev_;
        return remove(cur);
    }
    void dump()
    {
        Node<T>* ptr = dummy_->next_;
        while (ptr != dummy_)
        {
            cout << ptr->value_ << ' ';
            ptr = ptr->next_;
        }
        cout << '\n';
    }

    void clear()
    {
        while (!empty())
        {
            pop_front();
        }
    }

    int size()
    {
        return size_;
    }
};

template<typename T>
inline List<T>::List()
{
    
    dummy_ = new Node<T>();
    size_ = 0;
    
}

template<typename T>
inline void List<T>::add(T v, Node<T>* node)
{
    Node<T>* newNode = new Node<T>(v, node, node->next_);
    node->next_->prev_ = newNode;
    node->next_ = newNode;
    node = newNode;
    size_++;
}

template<typename T>
inline void List<T>::push_front(T value)
{
    Node<T>* cur = dummy_;
    add(value, cur);
}

template<typename T>
inline void List<T>::push_back(T value)
{
    Node<T>* cur = dummy_->prev_;
    add(value, cur);
}

template<typename T>
inline T List<T>::remove(Node<T>* node)
{
    if (empty())
    {
        throw std::logic_error("node is empty!");
    }
    T ret = node->value_;
    node->prev_->next_ = node->next_;
    node->next_->prev_ = node->prev_;
    delete node;
    size_--;
    return ret;
}
