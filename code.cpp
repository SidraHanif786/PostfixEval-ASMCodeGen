#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string exp;
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            exp += argv[i];
        }
    }
    else
    {
        cout << "Provide a postfix expression like this, 921+/4* " << endl;
    }
    //=====================================================

    stack<int> store;
    string token = "Token ";
    string push = "Push ";
    string pop = "Pop  ";
    string blank = "      ";

    for (int i = 0; i < exp.length(); i++)
    {
        char c = exp[i];
        if (isdigit(c))
        {
            int integer = atoi(&exp[i]);
            store.push(integer);
            cout << token << exp[i] << blank << push << exp[i] << endl;
        }
        else
        {
            //=========pop first number
            int first = store.top();
            // while (first >= 10)
            // {
            //     first /= 10;
            // }
            store.pop();
            //=========pop second number
            int second = store.top();
            // while (second >= 10)
            // {
            //     second /= 10;
            // }
            store.pop();
            int res;

            if (exp[i] == '*')
            {
                res = first * second;
            }
            if (exp[i] == '/')
            {
                res = second / first;
            }
            if (exp[i] == '+')
            {
                res = first + second;
            }
            if (exp[i] == '-')
            {
                res = first - second;
            }
            store.push(res);
            cout << token << exp[i] << blank << pop << first << blank << pop << second << blank << push << res << endl;
        }
    }
    cout << endl;
    cout << token << "END" << blank << push << store.top() << endl;

    return 0;
}

//  23+4*   20
//  572+*8-    35
//  92/34*+     11
//   63/5*2+     12
//    921+/4*     12