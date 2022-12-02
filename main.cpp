#include"List.h"
#include<string>

enum class State
{
    MENU,
    OUTPUT,
    INPUT,
    EDIT,
    DEL
};




int main()
{
    string str;
    List<string> Liststr;
    Liststr.push_back("banana");
    Liststr.push_back("apple");
    Liststr.push_back("orange");

    State state = State::MENU;

    string input;
    while (1)
    {
        if (state == State::MENU)
        {
            system("cls");
            
             cout << "[要素の操作]" << endl;
             cout << "1.要素の表示" << endl;
             cout << "2.要素の挿入" << endl;
             cout << "3.要素の編集" << endl;
             cout << "4.要素の削除" << endl;
             cout << endl;
             cout << "---------------------" << endl;
             cout << "操作を選択してください" << endl;
             do
             {
                 cin >> input;
                 try
                 {
                     stoi(input);
                 }
                 catch (std::invalid_argument)
                 {
                     input = "-256";
                 }
             } while (stoi(input) > 3 && stoi(input) < 1);
             state = (State)stoi(input);
           
        }
        if (state == State::OUTPUT)
        {
            system("cls");
            input = "0";
            cout << "[要素の表示]" << endl;
            cout << "1.要素の一覧表示" << endl;
            cout << "2.順番を指定して要素を表示" << endl;
            cout << "9.要素操作に戻る" << endl;
            cout << endl << "操作を選択してください。" << endl;
            do
            {
                cin >> input;

                try
                {
                    stoi(input);
                }
                catch (std::invalid_argument)
                {
                    input = "-256";
                }
            } while (stoi(input) != 1 && stoi(input) != 2 && stoi(input) != 9);
            if (stoi(input) == 1)
            {
                system("cls");
                cout << "[要素の一覧表示]" << endl;
                cout << "要素一覧: {" << endl;

                Liststr.dump();

                cout << "}" << endl << endl;
                cout << "要素数: " << Liststr.size() << endl;

                cout << endl << "-------------------------------" << endl;
                cout << "1.要素の表示に戻る" << endl;
                cout << "2.要素の操作に戻る" << endl;

                do
                {
                    cin >> input;
                    try
                    {
                        stoi(input);
                    }
                    catch (std::invalid_argument)
                    {
                        input = "-256";
                    }
                } while (stoi(input) != 1 && stoi(input) != 2);
                if (stoi(input) == 2)
                {
                    state = State::MENU;
                }


            }

            //順番を指定して要素を表示

            if (stoi(input) == 2)
            {
                system("cls");
                cout << "[順番を指定して要素を表示]" << endl;
                cout << "表示したい要素の順番を指定してください。" << endl;
                cin >> input;
                Liststr.choice_draw(stoi(input));

                cout << endl << "---------------------------" << endl;
                cout << "1.要素の表示に戻る" << endl;

                cout << "2.要素の操作に戻る" << endl;

                do
                {
                    cin >> input;
                    try
                    {
                        stoi(input);
                    }
                    catch (std::invalid_argument)
                    {
                        input = "-256";
                    }
                } while (stoi(input) != 1 && stoi(input) != 2);
                if (stoi(input) == 2)
                {
                    state = State::MENU;
                }

            }

            // 要素操作に戻る
            if (stoi(input) == 9)
            {
                state = State::MENU;
            }
        }
        if (state == State::INPUT)
        {
           
            system("cls");
            cout << "[リスト要素の挿入]" << endl;
            cout << "要素を追加する場所を指定してください。" << endl;
            cout << "最後尾に追加する場合は何も入力しないでください。" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            getline(cin, input); 

            cout << "追加する要素を入力してください。" << endl;
            cin >> str;
            if (input == string(""))
            {
                Liststr.push_back(str);
                cout << "要素\"" << str << "\"が最後尾に挿入されました。" << endl;
            }
            else
            {
                Liststr.Insert(stoi(input), str);
                cout << "要素\"" << str << "\"が" << input << "番目に挿入されました。" << endl;
            }

            cout << "9:要素操作に戻る" << endl;
            do {
                cin >> input;
                try {
                    stoi(input);
                }
                catch (std::invalid_argument) {
                    input = "-256";
                }
            } while (stoi(input) != 9);

            if (stoi(input) == 9)
            {
                state = State::MENU;
            }
        }

            if (state == State::EDIT)
            {
                cout << "要素の編集" << endl;
                system("cls");
                cout << "[リスト要素の編集]" << endl;
                cout << "要素を編集する場所を指定してください。" << endl;

                cin.clear();
                cin.ignore(1024, '\n');
                getline(cin, input);

                if (stoi(input) >= Liststr.size() || stoi(input) < 0)
                {
                    cout << input << "番目の要素が見つかりませんでした。" << endl;
                }
                else {
                    cout << "編集後の要素を入力してください。" << endl;
                    cin >> str;

                    Liststr.replace(stoi(input), str);
                    cout << "要素\"" << input << "\"が" << str << "に変更されました。" << endl;
                }

                cout << "9:要素操作に戻る" << endl;
                do {
                    cin >> input;
                    try {
                        stoi(input);
                    }
                    catch (std::invalid_argument) {
                        input = "-256";
                    }
                } while (stoi(input) != 9);

                if (stoi(input) == 9)
                {
                    state = State::MENU;
                }
            }
            if (state == State::DEL)
            {
                system("cls");
                cout << "[リスト要素の削除]" << endl;
                cout << "要素を削除する場所を指定してください。" << endl;

                cin >> input;

                if (stoi(input) >= Liststr.size() || stoi(input) < 0)
                {
                    cout << input << "番目の要素が見つかりませんでした。" << endl;
                }
                else
                {

                    Liststr.DeleteCell(stoi(input));
                    cout << input << "番目の要素が削除されました。" << endl;
                }

                cout << "9:要素操作に戻る" << endl;
                do {
                    cin >> input;
                    try {
                        stoi(input);
                    }
                    catch (std::invalid_argument) {
                        input = "-256";
                    }
                } while (stoi(input) != 9);

                if (stoi(input) == 9)
                {
                    state = State::MENU;
                }
            }
    }

    return 0;
}