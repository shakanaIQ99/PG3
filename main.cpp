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
            
             cout << "[—v‘f‚Ì‘€ì]" << endl;
             cout << "1.—v‘f‚Ì•\Ž¦" << endl;
             cout << "2.—v‘f‚Ì‘}“ü" << endl;
             cout << "3.—v‘f‚Ì•ÒW" << endl;
             cout << "4.—v‘f‚Ìíœ" << endl;
             cout << endl;
             cout << "---------------------" << endl;
             cout << "‘€ì‚ð‘I‘ð‚µ‚Ä‚­‚¾‚³‚¢" << endl;
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
            cout << "[—v‘f‚Ì•\Ž¦]" << endl;
            cout << "1.—v‘f‚Ìˆê——•\Ž¦" << endl;
            cout << "2.‡”Ô‚ðŽw’è‚µ‚Ä—v‘f‚ð•\Ž¦" << endl;
            cout << "9.—v‘f‘€ì‚É–ß‚é" << endl;
            cout << endl << "‘€ì‚ð‘I‘ð‚µ‚Ä‚­‚¾‚³‚¢B" << endl;
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
                cout << "[—v‘f‚Ìˆê——•\Ž¦]" << endl;
                cout << "—v‘fˆê——: {" << endl;

                Liststr.dump();

                cout << "}" << endl << endl;
                cout << "—v‘f”: " << Liststr.size() << endl;

                cout << endl << "-------------------------------" << endl;
                cout << "1.—v‘f‚Ì•\Ž¦‚É–ß‚é" << endl;
                cout << "2.—v‘f‚Ì‘€ì‚É–ß‚é" << endl;

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
                cout << "[‡”Ô‚ðŽw’è‚µ‚Ä—v‘f‚ð•\Ž¦]" << endl;
                cout << "•\Ž¦‚µ‚½‚¢—v‘f‚Ì‡”Ô‚ðŽw’è‚µ‚Ä‚­‚¾‚³‚¢B" << endl;
                cin >> input;
                Liststr.choice_draw(stoi(input));

                cout << endl << "---------------------------" << endl;
                cout << "1.—v‘f‚Ì•\Ž¦‚É–ß‚é" << endl;

                cout << "2.—v‘f‚Ì‘€ì‚É–ß‚é" << endl;

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
            cout << "[ƒŠƒXƒg—v‘f‚Ì‘}“ü]" << endl;
            cout << "—v‘f‚ð’Ç‰Á‚·‚éêŠ‚ðŽw’è‚µ‚Ä‚­‚¾‚³‚¢B" << endl;
            cout << "ÅŒã”ö‚É’Ç‰Á‚·‚éê‡‚Í‰½‚à“ü—Í‚µ‚È‚¢‚Å‚­‚¾‚³‚¢B" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            getline(cin, input); 

            cout << "’Ç‰Á‚·‚é—v‘f‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B" << endl;
            cin >> str;
            if (input == string(""))
            {
                Liststr.push_back(str);
                cout << "—v‘f\"" << str << "\"‚ªÅŒã”ö‚É‘}“ü‚³‚ê‚Ü‚µ‚½B" << endl;
            }
            else
            {
                Liststr.Insert(stoi(input), str);
                cout << "—v‘f\"" << str << "\"‚ª" << input << "”Ô–Ú‚É‘}“ü‚³‚ê‚Ü‚µ‚½B" << endl;
            }

            cout << "9:—v‘f‘€ì‚É–ß‚é" << endl;
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
                cout << "—v‘f‚Ì•ÒW" << endl;
                system("cls");
                cout << "[ƒŠƒXƒg—v‘f‚Ì•ÒW]" << endl;
                cout << "—v‘f‚ð•ÒW‚·‚éêŠ‚ðŽw’è‚µ‚Ä‚­‚¾‚³‚¢B" << endl;

                cin.clear();
                cin.ignore(1024, '\n');
                getline(cin, input);

                if (stoi(input) >= Liststr.size() || stoi(input) < 0)
                {
                    cout << input << "”Ô–Ú‚Ì—v‘f‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½B" << endl;
                }
                else {
                    cout << "•ÒWŒã‚Ì—v‘f‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B" << endl;
                    cin >> str;

                    Liststr.replace(stoi(input), str);
                    cout << "—v‘f\"" << input << "\"‚ª" << str << "‚É•ÏX‚³‚ê‚Ü‚µ‚½B" << endl;
                }

                cout << "9:—v‘f‘€ì‚É–ß‚é" << endl;
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
                cout << "[ƒŠƒXƒg—v‘f‚Ìíœ]" << endl;
                cout << "—v‘f‚ðíœ‚·‚éêŠ‚ðŽw’è‚µ‚Ä‚­‚¾‚³‚¢B" << endl;

                cin >> input;

                if (stoi(input) >= Liststr.size() || stoi(input) < 0)
                {
                    cout << input << "”Ô–Ú‚Ì—v‘f‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½B" << endl;
                }
                else
                {

                    Liststr.DeleteCell(stoi(input));
                    cout << input << "”Ô–Ú‚Ì—v‘f‚ªíœ‚³‚ê‚Ü‚µ‚½B" << endl;
                }

                cout << "9:—v‘f‘€ì‚É–ß‚é" << endl;
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