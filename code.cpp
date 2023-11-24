// Sample arguments to test
//  23+4*      res 20
//  572+*8-    res 37
//  92/34*+    res 16
//  63/5*2+    res 12
//  921+/4*    res 12

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

    string token = "Token ";
    string push = "Push ";
    string pop = "Pop  ";
    string blank = "      ";

    //============== Start of the operations =========
    stack<int> store;
    for (int i = 0; i < exp.length(); i++)
    {
        char c = exp[i];
        //===== pushing the operands
        if (isdigit(c))
        {
            int integer = c - '0'; // THIS LINE GOT ME STUCK FOR 3 HOURS :(
            store.push(integer);
            cout << token << exp[i] << blank << push << exp[i] << endl;
        }
        else
        {
            //====== handling expressions that are not well formed.
            if (store.size() < 2)
            {
                cout << "Error: Not enough operands for operator " << endl;
                return 1;
            }
            //=========pop first number
            int first = store.top();
            store.pop();
            //=========pop second number
            int second = store.top();
            store.pop();
            int res;

            if (exp[i] == '*')
            {
                res = first * second;
            }
            if (exp[i] == '/')
            {
                if (second > first)
                {
                    res = second / first;
                }
                else
                {
                    res = first / second;
                }
            }
            if (exp[i] == '+')
            {
                res = first + second;
            }
            if (exp[i] == '-')
            {
                if (second > first)
                {
                    res = second - first;
                }
                else
                {
                    res = first - second;
                }
            }
            store.push(res);
            cout << token << exp[i] << blank << pop << first << blank << pop << second << blank << push << res << endl;
        }
    }
    if (!store.empty())
    {
        cout << endl;
        cout << token << "END" << blank << "Push " << store.top() << endl;
    }
    //====== handling expressions that are not well formed.
    else
    {
        cout << "Error: No result available" << endl;
        return 1;
    }
    return 0;
}
