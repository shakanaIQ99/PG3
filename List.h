#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
template <typename T>
struct Cell
{
    T value_;
    Cell* prev_;
    Cell* next_;
    Cell()
    {
        prev_ = this;
        next_ = this;
    }
    Cell(T value, Cell* prev, Cell* next)
    {
        value_ = value;
        prev_ = prev;
        next_ = next;
    }

    T* operator*()
    {
        return &value_;
    };

};


template <typename T>
class List
{

private:
    Cell<T>* dummy_;
    int size_;
public:
    List();
    ~List()
    {
        clear();
    }

    void add(T v, Cell<T>* node);
    void push_front(T value);
    void push_back(T value);
    bool empty()
    {
        return dummy_->next_ == dummy_;
    }

    T remove(Cell<T>* node);
    T pop_front()
    {
        Cell<T>* cur = dummy_->next_;
        return remove(cur);
    }

    T pop_back()
    {
        Cell<T>* cur = dummy_->prev_;
        return remove(cur);
    }
    void dump()
    {
        Cell<T>* ptr = dummy_->next_;
        int i = 0;
        while (ptr != dummy_)
        {
            cout <<i << " : " << ptr->value_ << endl;
            ptr = ptr->next_;
            i++;
        }

       
    }

    void replace(int num,T&obj)
    {
        Cell<T>* ptr = dummy_->next_;
        for (int i = 0; i < num; i++) {
            ptr = ptr->next_;
        }
        ptr->value_ = obj;
    }

    void choice_draw(int i)
    {
        Cell<T>* ptr = dummy_->next_;
        int num = 0;
        while (num<i)
        {
            ptr = ptr->next_;
            num++;
        }
        cout << i << " : " << ptr->value_ << endl;
    }

   void Insert(int num, T& obj)
   {
        if (num >= size()) 
        {
            push_back(obj);
        }
        else
        {
            Cell<T>* ptr = dummy_;
            for (int i = 0; i < num; i++) {
                ptr = ptr->next_;
            }
            add(obj, ptr);
        }
       
    };

   void DeleteCell(int num)
   {
       Cell<T>* ptr = dummy_->next_;
       for (int i = 0; i < num; i++) {
           ptr = ptr->next_;
       }
       remove(ptr);
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
    
    dummy_ = new Cell<T>();
    size_ = 0;
    
}

template<typename T>
inline void List<T>::add(T v, Cell<T>* node)
{
    Cell<T>* newNode = new Cell<T>(v, node, node->next_);
    node->next_->prev_ = newNode;
    node->next_ = newNode;
    node = newNode;
    size_++;
}

template<typename T>
inline void List<T>::push_front(T value)
{
    Cell<T>* cur = dummy_;
    add(value, cur);
}

template<typename T>
inline void List<T>::push_back(T value)
{
    Cell<T>* cur = dummy_->prev_;
    add(value, cur);
}

template<typename T>
inline T List<T>::remove(Cell<T>* node)
{
    if (empty())
    {
        throw std::logic_error("‹ó‚Å‚·");
    }
    T ret = node->value_;
    node->prev_->next_ = node->next_;
    node->next_->prev_ = node->prev_;
    delete node;
    size_--;
    return ret;
}
