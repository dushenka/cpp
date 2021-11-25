#include <iostream>

using namespace std;


short figure, lenght, type, size1, size2;
char symbol1, symbol2;
bool isEmpty;

void menu()
{
    cout << "[+] \"Figures\"\n\n";
    cout << "[1] Line\n";
    cout << "[2] Square\n";
    cout << "[3] Rectangle\n";
    cout << "[4] Triangle\n";
    cout << "[5] Cross\n";
    cout << "[6] Square recursion\n";
    cout << "[7] Chess grid\n";
    cout << "[8] Grate\n\n";

    cout << "[+] Choose your figure (button): ";
    cin >> figure;

    system("cls");
}

int main()
{
    setlocale(0, "");

    menu();

    switch (figure)
    {
    case 1:
        cout << "[+] Line\n";

        cout << "\n[+] Types\n";

        cout << "\n[1] Horizontal";
        cout << "\n[2] Vertical\n";
        cout << "\n[+] Choose type (button): ";
        cin >> type;

        cout << "\n[+] Enter desirable lenght: ";
        cin >> lenght;

        cout << "\n[+] Enter desirable texture (symbol): ";
        cin >> symbol1;

        if (type == 1)
        {
            cout << "[+] Result: ";
            while (lenght > 0)
            {
                cout << symbol1;
                lenght -= 1;
            }
            cout << endl;
        }
        else
        {
            cout << "[+] Result: \n";
            while (lenght > 0)
            {
                cout << symbol1 << endl;
                lenght -= 1;
            }
        }
        break;
    case 2:
        cout << "\n[+] Is square hollow? (1 - Yes, 0 - No) ";
        cin >> isEmpty;
        cout << "[+] Choose desirable size: ";
        cin >> size1;
        cout << "\n[+] Choose desirable texture (symbol): ";
        cin >> symbol1;
        if (isEmpty == 0)
        {
            cout << "[+] Result: \n";
            for (int i = 0; i < size1; i++)
            {
                for (int j = 0; j < size1; j++)
                {
                    cout << symbol1 << " ";
                }
                cout << "\n";
            }
        }
        else
        {
            cout << "[+] Result: \n";
            for (int i = 0; i < size1; i++)
            {
                for (int j = 0; j < size1; j++)
                {
                    if (i == 0 || i == size1 - 1)
                    {
                        cout << symbol1 << " ";
                    }
                    else
                    {
                        if (j == 0 || j == size1 - 1)
                        {
                            cout << symbol1 << " ";
                        }
                        else
                        {
                            cout << "  ";
                        }
                    }
                }
                cout << endl;
            }
        }

        break;

    case 3:

        cout << "\n[+] Is rectangle hollow? (1 - Yes, 0 - No) ";
        cin >> isEmpty;
        cout << "[+] Choose desirable height: ";
        cin >> size1;
        cout << "[+] Choose desirable width: ";
        cin >> size2;
        cout << "\n[+] Choose desirable texture (symbol): ";
        cin >> symbol1;

        if (isEmpty == 0)
        {
            cout << "[+] Result: \n";
            for (int i = 0; i < size2; i++)
            {
                for (int j = 0; j < size1; j++)
                {
                    cout << symbol1 << " ";
                }
                cout << "\n";
            }
        }
        else
        {
            cout << "[+] Result: \n";
            for (int i = 0; i < size2; i++)
            {
                for (int j = 0; j < size1; j++)
                {
                    if (i == 0 || i == size2 - 1 || j == 0 || j == size1 - 1)
                    {
                        cout << symbol1 << " ";
                    }
                    else
                    {
                        cout << "  ";
                    }
                }
                cout << endl;
            }
        }
        break;
    case 4:
        cout << "\n[+] Is triangle hollow? (1 - Yes, 0 - No) ";
        cin >> isEmpty;
        cout << "[+] Choose desirable height: ";
        cin >> size1;
        cout << "[+] Choose desirable width: ";
        cin >> size2;
        cout << "[+] Choose desirable texture (symbol): ";
        cin >> symbol1;
        if (isEmpty == 1)
        {
            if (size2 % 2 != 0)
            {
                for (int i = 0; i < size1; i++)
                {
                    for (int j = 0; j < size2; j++)
                    {
                        if (j == size2 / 2 + i || j == size2 / 2 - i || i == size1 - 1)
                        {
                            cout << symbol1 << " ";
                        }
                        else
                        {
                            cout << "  ";
                        }
                    }
                    cout << "\n";
                }
            }
            else
            {
                cout << "Triangle width must be odd number!\n";
            }
        }
        else
        {
            if (size2 % 2 != 0)
            {
                for (int i = 0; i < size1; i++)
                {
                    for (int j = 0; j < size2; j++)
                    {
                        if (j <= size2 / 2 + i && j >= size2 / 2 - i || i == size1 - 1)
                        {
                            cout << symbol1 << " ";
                        }
                        else
                        {
                            cout << "  ";
                        }
                    }
                    cout << "\n";
                }
            }
            else
            {
                cout << "Triangle width must be odd number!\n";
            }
        }

        break;
    case 5:
        cout << "[+] Choose desirable size: ";
        cin >> size1;
        cout << "\n[+] Choose desirable texture (symbol): ";
        cin >> symbol1;
        cout << "\n[+] Cross type: ";
        cout << "\n\n[1] Vertical, like +";
        cout << "\n[2] 45 degree, like X";
        cout << "\n\n[+] Choose desirable type: ";
        cin >> type;

        if (type == 1)
        {
            cout << "[+] Result: \n";
            for (int i = 0; i < size1; i++)
            {
                for (int j = 0; j < size1; j++)
                {
                    if (i == size1 / 2 || j == size1 / 2)
                    {
                        cout << symbol1 << " ";
                    }
                    else
                    {
                        cout << "  ";
                    }

                }
                cout << "\n";
            }
        }
        else if (type == 2)
        {
            cout << "[+] Result: \n";
            for (int i = 0; i < size1; i++)
            {

                for (int j = 0; j < size1; j++)
                {
                    if (i == j)
                    {
                        cout << symbol1 << " ";
                    }
                    else if (i + j == size1)
                    {
                        cout << symbol1 << " ";
                    }
                    else
                    {
                        cout << "  ";
                    }
                }
                cout << "\n";
            }
        }
        break;
    case 6:
        cout << "[+] Choose desirable size of recursion: ";
        cin >> size1;
        cout << "\n[+] Choose desirable texture of recursion (symbol): ";
        cin >> symbol1;

        cout << "\n[+] Result: \n";

        for (int i = 0; i <= size1; i++)
        {
            for (int j = 0; j <= size1; j++)
            {
                if ((min(min(i, size1 - i), min(j, size1 - j)) % 2) == 0)
                {
                    cout << symbol1 << " ";
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << endl;
        }
        break;

    case 7:
        cout << "[+] Choose grid size: ";
        cin >> size1;
        cout << "[+] Choose texture 1 (symbol): ";
        cin >> symbol1;
        cout << "[+] Choose texture 2 (symbol): ";
        cin >> symbol2;
        cout << "\n[+] Result: \n";
        cout << "";

        for (int i = 0; i < size1; i++)
        {
            for (int j = 0; j < size1; j++)
            {
                if ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))
                {
                    cout << symbol1 << " ";
                }
                else
                {
                    cout << symbol2 << " ";
                }
            }
            cout << endl;
        }
        break;
    case 8:
        cout << "[+] Choose desirable size: ";
        cin >> size1;
        cout << "[+] Choose desirable texture (symbol): ";
        cin >> symbol1;
        cout << "\n[+] Result: \n";
        cout << "";

        for (int i = 0; i < size1 - 1; i++)
        {
            for (int j = 0; j < size1 - 1; j++)
            {
                if (i % 2 == 0 && j % 2 == 0 && i < size1 - 1 && j < size1 - 1)
                {
                    cout << "  ";
                }
                else
                {
                    cout << symbol1 << " ";
                }
            }
            cout << endl;
        }
        break;
    default:
        cout << "Sorry, there is no such button/figure :с\n";
    }
    system("pause"); 
    menu();
    return 0;
}