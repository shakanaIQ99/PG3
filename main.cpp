#include"List.h"

int main()
{
    List<int> list;
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
        cout << "1.要素の表示" << '\n';
        cout << "2.要素の挿入" << '\n';
        cout << "3.要素の編集" << '\n';
        cout << "4.要素の削除" << '\n';

        cout << "-----------------" << '\n';
        cout << "操作を選択してください" << '\n';

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