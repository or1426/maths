#include "main.h"
list<op> opList;
op::op(string opS,void (*exe)(list<comp> &stack))
{
    opCode = string(opS);
    execute = exe;
    (opList).push_front(*this);
}

void add(list<comp> &stack)
{
    comp temp1,temp2,temp3;
    temp1 = *stack.begin();

    stack.pop_front();
    temp2 = *stack.begin();

    stack.pop_front();
    temp3 =  temp2 + temp1;

    stack.push_front(temp3);

}


void sub(list<comp> &stack)
{
    comp temp1,temp2,temp3;
    temp1 = *stack.begin();

    stack.pop_front();
    temp2 = *stack.begin();

    stack.pop_front();
    temp3 =  temp2 - temp1;

    stack.push_front(temp3);

}

void mul(list<comp> &stack)
{
    comp temp1,temp2,temp3;
    temp1 = *stack.begin();

    stack.pop_front();
    temp2 = *stack.begin();

    stack.pop_front();
    temp3 =  temp2 * temp1;

    stack.push_front(temp3);

}

void div(list<comp> &stack)
{
    comp temp1,temp2,temp3;

    temp1 = *stack.begin();
    stack.pop_front();

    temp2 = *stack.begin();
    stack.pop_front();

    temp3 =  temp2 / temp1;

    stack.push_front(temp3);

}

void help(list<comp> &stack){ //it is quite bad that the function help pushes 0 + 0i onto the stack (although it gets eaten anyway)
    cout << "********************************************************************************" <<endl;
    cout <<"Enter commands and arguments in form: arg1 arg2 .... argn command. For example:"<< endl << "4 10i + returns 4 + 10i" <<endl;
    cout <<"You can chain commands to evaluate more complicated expressions. For example:" << endl << "3 5 + 4 2 - / returns 4"<<endl;
    cout << "********************************************************************************" <<endl;
    stack.push_front(comp());
}
