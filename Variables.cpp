//Dictionaries
#include <iostream>
//Namespaces
using namespace std;

//Main
int main()
{
    setlocale(0, "");

    //Put here number of variables of 8 types you want to see
    const int N = 10;

    //Anouncement and divider
    cout << "There are some variables: " << endl;
    cout << " " << endl;

    //1
    //Making N int variables and showing them
    for (int i = 0; i < N; i++)
    {
        int j[N] = { };
        j[i] = i * 10 / 3;
        cout << "new int j" << i+1 << " = " << j[i] << endl;
    }
    //Capacity
    cout << "All int variables take 4 bytes each" << endl;

    //Just a divider
    cout << " " << endl;

    //2
    //Making N long variables and showing them as well
    for (int i = 0; i < N; i++)
    {
        long l[N] = { };
        l[i] = rand() + i ^ 3 * 1337;
        cout << "new long l" << i + 1 << " = " << l[i] << endl;
    }
    //Capacity
    cout << "All long variables take 4 bytes each" << endl;

    //Another divider
    cout << " " << endl;

    //3
    //Making N short variables and showing them as well
    for (int i = 0; i < N; i++)
    {
        short s[N] = { };
        s[i] = i * 1091 + rand();
        cout << "new short s" << i + 1 << " = " << s[i] << endl;
    }
    //Capacity
    cout << "All short variables take 2 bytes each" << endl;

    //Divider
    cout << " " << endl;
    
    //4
    //Making N char variables and showing them as well
    for (int i = 0; i < N; i++)
    {
        char c[N] = { };
        c[i] = 'a';
        cout << "new char c" << i + 1 << " = " << c[i] << endl;
    }
    //Capacity
    cout << "All char variables take 1 byte each" << endl;

    //Divider
    cout << " " << endl;

    //5
    //Making N bool variables and showing them as well
    for (int i = 0; i < N; i++)
    {
        bool b[N] = { };
        b[i] = 0 + rand() % 2;
        cout << "new bool b" << i + 1 << " = " << b[i] << endl;
    }
    //Capacity
    cout << "All bool variables take 1 byte each" << endl;

    //Divider
    cout << " " << endl;

    //6
    //Making N float variables and showing them as well
    for (int i = 0; i < N; i++)
    {
        float f[N] = { };
        f[i] = i +  i * 1.7;
        cout << "new float f" << i + 1 << " = " << f[i] << endl;
    }
    //Capacity
    cout << "All float variables take 4 bytes each" << endl;

    //Divider
    cout << " " << endl;

    //7
    //Making N double variables and showing them as well
    for (int i = 0; i < N; i++)
    {
        double d[N] = { };
        d[i] = i + i * 7.3019123;
        cout << "new double d" << i + 1 << " = " << d[i] << endl;
    }
    //Capacity
    cout << "All double variables take 8 bytes each" << endl;

    //Divider
    cout << " " << endl;

    //8
    //Making N string variables and showing them as well
    string txt = "lol ";
    for (int i = 0; i < N; i++)
    {
        string ss[N] = { };
        ss[i] = txt + "xd";
        txt = ss[i];
        cout << "new string ss" << i + 1 << " = " << ss[i] << endl;
    }
    //Capacity
    cout << "All long variables take UNKNOWN_COUNT of bytes each" << endl;

    //Divider
    cout << " " << endl;

    //End
    cout << "THE END" << endl;

    //Divider
    cout << " " << endl;

    //Making programm not to close after execution
    system("pause");

    return 0;
}