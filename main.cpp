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
class DoublyLinkedList
{
private:
    Node<T>* dummy_;
    int size_;
public:
    DoublyLinkedList()
    {
        dummy_ = new Node<T>();
        size_ = 0;
    }
    ~DoublyLinkedList()
    {
        clear();
    }

    void add(T v, Node<T>* node)
    {
        // insert a new node between the current node and the next of current node
        Node<T>* newNode = new Node<T>(v, node, node->next_);
        node->next_->prev_ = newNode;
        node->next_ = newNode;
        // update the current node
        node = newNode;
        size_++;
    }
    void push_front(T value)
    {
        Node<T>* cur = dummy_;
        add(value, cur);
    }
    void push_back(T value)
    {
        Node<T>* cur = dummy_->prev_;
        add(value, cur);
    }
    bool empty()
    {
        return dummy_->next_ == dummy_;
    }

    T remove(Node<T>* node)
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
int main()
{
    DoublyLinkedList<int> list;
    list.push_front(13);
    list.push_front(7);
    list.push_front(10);
    cout << "size: " << list.size() << '\n';
    list.dump();
    list.push_back(11);
    cout << "size: " << list.size() << '\n';
    list.dump();
    cout << "remove: " << list.pop_back() << '\n';
    cout << "size: " << list.size() << '\n';
    list.dump();
    cout << "remove: " << list.pop_front() << '\n';
    cout << "size: " << list.size() << '\n';
    list.dump();
   /* while (1)
    {
        cout << "1.—v‘f‚Ì•\Ž¦" << '\n';
        cout << "2.—v‘f‚Ì‘}“ü" << '\n';
        cout << "3.—v‘f‚Ì•ÒW" << '\n';
        cout << "4.—v‘f‚Ìíœ" << '\n';

        cout << "-----------------" << '\n';
        cout << "‘€ì‚ð‘I‘ð‚µ‚Ä‚­‚¾‚³‚¢" << '\n';

        int num;
        cin >> num;

        switch (num)
        {
            case 1:
                cout << "1" << '\n';
                break;
            case 2:
                cout << "2" << '\n';
                break;
            case 3:
                cout << "3" << '\n';
                break;
            case 4:
                cout << "4" << '\n';
                break;
        }
        if (num == 0)
        {
            break;
        }
    }*/

    return 0;
}