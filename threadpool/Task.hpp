#pragma once
#include <iostream>
#include <string>

class Task
{
public:
    Task()
        :a(0)
        ,b(0)
        ,op('0')
    {}
    Task(int one, int two, char op)
        :a(one)
        ,b(two)
        ,op(op)
    {}
    int operator() ()
    {
        return run();
    }
 
    int run()
    {
        int result = 0;
        switch(op)
        {
            case '+':
                result  = a+ b;
                break;
            case '-':
                result  = a- b;
                break;
            case '*':
                 result  = a* b;
                break;
            case '/':
            {
                if(b == 0)
                {
                    std::cout << "div zero, abort" <<std::endl;
                    result = -1;
                }
                else
                {
                    result  = a/ b;
                }
            }

                break;
            case '%':
                result  = a% b;
                break;
            default:
                std::cout << "非法操作" << op << std::endl;
                break;                                
        }
        return result;
    }

    void get(int* e1, int* e2, char* e3)
    {
        *e1 = a;
        *e2 = b;
        *e3 = op;
    }
private:
    int a;
    int b;
    char op;
};