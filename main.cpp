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
            
             cout << "[�v�f�̑���]" << endl;
             cout << "1.�v�f�̕\��" << endl;
             cout << "2.�v�f�̑}��" << endl;
             cout << "3.�v�f�̕ҏW" << endl;
             cout << "4.�v�f�̍폜" << endl;
             cout << endl;
             cout << "---------------------" << endl;
             cout << "�����I�����Ă�������" << endl;
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
            cout << "[�v�f�̕\��]" << endl;
            cout << "1.�v�f�̈ꗗ�\��" << endl;
            cout << "2.���Ԃ��w�肵�ėv�f��\��" << endl;
            cout << "9.�v�f����ɖ߂�" << endl;
            cout << endl << "�����I�����Ă��������B" << endl;
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
                cout << "[�v�f�̈ꗗ�\��]" << endl;
                cout << "�v�f�ꗗ: {" << endl;

                Liststr.dump();

                cout << "}" << endl << endl;
                cout << "�v�f��: " << Liststr.size() << endl;

                cout << endl << "-------------------------------" << endl;
                cout << "1.�v�f�̕\���ɖ߂�" << endl;
                cout << "2.�v�f�̑���ɖ߂�" << endl;

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
            if (stoi(input) == 2)
            {
                system("cls");
                cout << "[���Ԃ��w�肵�ėv�f��\��]" << endl;
                cout << "�\���������v�f�̏��Ԃ��w�肵�Ă��������B" << endl;
                cin >> input;
                Liststr.choice_draw(stoi(input));

                cout << endl << "---------------------------" << endl;
                cout << "1.�v�f�̕\���ɖ߂�" << endl;

                cout << "2.�v�f�̑���ɖ߂�" << endl;

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
            if (stoi(input) == 9)
            {
                state = State::MENU;
            }
        }
        if (state == State::INPUT)
        {
           
            system("cls");
            cout << "[���X�g�v�f�̑}��]" << endl;
            cout << "�v�f��ǉ�����ꏊ���w�肵�Ă��������B" << endl;
            cout << "�Ō���ɒǉ�����ꍇ�͉������͂��Ȃ��ł��������B" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            getline(cin, input); 

            cout << "�ǉ�����v�f����͂��Ă��������B" << endl;
            cin >> str;
            if (input == string(""))
            {
                Liststr.push_back(str);
                cout << "�v�f\"" << str << "\"���Ō���ɑ}������܂����B" << endl;
            }
            else
            {
                Liststr.Insert(stoi(input), str);
                cout << "�v�f\"" << str << "\"��" << input << "�Ԗڂɑ}������܂����B" << endl;
            }

            cout << "9:�v�f����ɖ߂�" << endl;
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
                cout << "�v�f�̕ҏW" << endl;
                system("cls");
                cout << "[���X�g�v�f�̕ҏW]" << endl;
                cout << "�v�f��ҏW����ꏊ���w�肵�Ă��������B" << endl;

                cin.clear();
                cin.ignore(1024, '\n');
                getline(cin, input);

                if (stoi(input) >= Liststr.size() || stoi(input) < 0)
                {
                    cout << input << "�Ԗڂ̗v�f��������܂���ł����B" << endl;
                }
                else {
                    cout << "�ҏW��̗v�f����͂��Ă��������B" << endl;
                    cin >> str;

                    Liststr.replace(stoi(input), str);
                    cout << "�v�f\"" << input << "\"��" << str << "�ɕύX����܂����B" << endl;
                }

                cout << "9:�v�f����ɖ߂�" << endl;
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
                cout << "[���X�g�v�f�̍폜]" << endl;
                cout << "�v�f���폜����ꏊ���w�肵�Ă��������B" << endl;

                cin >> input;

                if (stoi(input) >= Liststr.size() || stoi(input) < 0)
                {
                    cout << input << "�Ԗڂ̗v�f��������܂���ł����B" << endl;
                }
                else
                {

                    Liststr.DeleteCell(stoi(input));
                    cout << input << "�Ԗڂ̗v�f���폜����܂����B" << endl;
                }

                cout << "9:�v�f����ɖ߂�" << endl;
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