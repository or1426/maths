#include "main.h"
list<op> opList;
op::op(string opS,void (*exe)(list<matrix> &stack))
{
    opCode = string(opS);
    execute = exe;
    (opList).push_front(*this);
}

void add(list<matrix> &stack)
{
    matrix temp1,temp2,temp3;

    temp1 = stack.front();
    stack.pop_front();

    temp2 = stack.front();
    stack.pop_front();

    temp3 =  temp2 + temp1;

    stack.push_front(temp3);

}


void sub(list<matrix> &stack)
{
    matrix temp1,temp2,temp3;
    temp1 = *stack.begin();

    stack.pop_front();
    temp2 = *stack.begin();

    stack.pop_front();
    temp3 =  temp2 - temp1;

    stack.push_front(temp3);

}

void mul(list<matrix> &stack)
{
    matrix temp1,temp2,temp3;
    temp1 = *stack.begin();

    stack.pop_front();
    temp2 = *stack.begin();

    stack.pop_front();
    temp3 =  temp2 * temp1;

    stack.push_front(temp3);

}

void div(list<matrix> &stack)
{
    matrix temp1,temp2,temp3;

    temp1 = *stack.begin();
    stack.pop_front();

    temp2 = *stack.begin();
    stack.pop_front();

    temp3 =  temp2 / temp1;

    stack.push_front(temp3);

}

void makeVect(list<matrix> &stack)
{
    matrix current;

    vect tempV;
    while(!stack.empty() && stack.front().isComplex == true){
        current = stack.front();
        stack.pop_front();
        tempV.elList.push_front(current.vList.front().elList.front());
    }

    matrix tempM(tempV);
    tempM.isVector = true;
    //cout << tempM.toString();
    stack.push_front(tempM);
  //  cout << "&&&&&&" << stack.front().isVector <<endl;

}

void trans(list<matrix> &stack)
{
    matrix current;
    matrix temp;
    current = stack.front();
    stack.pop_front();
    temp = ++current;
    stack.push_front(temp);
}

void makeMatrix(list<matrix> &stack)
{
    matrix current;
    matrix tempM;

    while(!stack.empty() && stack.front().isVector == true){
        current = stack.front();
        stack.pop_front();
        tempM.vList.push_front(current.vList.front());
    }

    tempM.isVector = false;
    tempM.isComplex = false;
    //cout << tempM.toString();
    stack.push_front(tempM);
}

void help(list<matrix> &stack){
    cout << "********************************************************************************" <<endl;
    cout <<"Enter commands and arguments in form: arg1 arg2 .... argn command. For example:"<< endl << "4 10i + returns 4 + 10i" <<endl;
    cout <<"You can chain commands to evaluate more complicated expressions. For example:" << endl << "3 5 + 4 2 - / returns 4"<<endl;
    cout << "********************************************************************************" <<endl;
    //stack.push_front(comp());
}
