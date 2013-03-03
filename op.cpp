#include "main.h"
list<op> opList;
op::op(string opS,void (*exe)(list<object> &stack))
{
    opCode = string(opS);
    execute = exe;
    (opList).push_front(*this);
}

void add(list<object> &stack)
{
    object temp1,temp2,temp3;

    temp1 = stack.front();
    stack.pop_front();

    temp2 = stack.front();
    stack.pop_front();

    temp3.comp_data =  temp2.comp_data + temp1.comp_data;
    temp3.vect_data =  temp2.vect_data  + temp1.vect_data ;
    temp3.matrix_data =  temp2.matrix_data + temp1.matrix_data;

    temp3.isComp = temp1.isComp;
    temp3.isVect = temp1.isVect;
    temp3.isMatrix = temp1.isMatrix;
    stack.push_front(temp3);

}


void sub(list<object> &stack)
{
    object temp1,temp2,temp3;

    temp1 = stack.front();
    stack.pop_front();

    temp2 = stack.front();
    stack.pop_front();

    temp3.comp_data =  temp2.comp_data - temp1.comp_data;
    temp3.vect_data =  temp2.vect_data  - temp1.vect_data ;
    temp3.matrix_data =  temp2.matrix_data - temp1.matrix_data;

    temp3.isComp = temp1.isComp;
    temp3.isVect = temp1.isVect;
    temp3.isMatrix = temp1.isMatrix;
    stack.push_front(temp3);
}

void mul(list<object> &stack)
{
    object temp1,temp2,temp3;

    temp1 = stack.front();
    stack.pop_front();

    temp2 = stack.front();
    stack.pop_front();

  //  cout << temp1.toString() << endl;

    if(temp2.isComp == temp1.isComp && temp2.isVect == temp1.isVect && temp2.isMatrix == temp1.isMatrix)
    {
        temp3.comp_data =  temp2.comp_data * temp1.comp_data;
        temp3.vect_data =  temp2.vect_data  * temp1.vect_data ;
        temp3.matrix_data =  temp2.matrix_data * temp1.matrix_data;

        temp3.isComp = temp1.isComp;
        temp3.isVect = temp1.isVect;
        temp3.isMatrix = temp1.isMatrix;
    }else if(temp1.isComp && temp2.isVect){
        temp3.vect_data = temp2.vect_data * temp1.comp_data;
        temp3.isComp = false;
        temp3.isVect = true;
        temp3.isMatrix = false;
    }else if(temp1.isComp && temp2.isMatrix){
        temp3.matrix_data = temp2.matrix_data * temp1.comp_data;
        temp3.isComp = false;
        temp3.isVect = false;
        temp3.isMatrix = true;
    }else if(temp1.isVect && temp2.isMatrix){
        temp3.vect_data = temp2.matrix_data * temp1.vect_data;
        temp3.isComp = false;
        temp3.isVect = true;
        temp3.isMatrix = false;
    }
    stack.push_front(temp3);

}

void div(list<object> &stack)
{
    object temp1,temp2,temp3;

    temp1 = stack.front();
    stack.pop_front();

    temp2 = stack.front();
    stack.pop_front();

    temp3.comp_data =  temp2.comp_data / temp1.comp_data;
    temp3.vect_data =  temp2.vect_data  / temp1.vect_data ;
    temp3.matrix_data =  temp2.matrix_data / temp1.matrix_data;

    temp3.isComp = temp1.isComp;
    temp3.isVect = temp1.isVect;
    temp3.isMatrix = temp1.isMatrix;
    stack.push_front(temp3);

}

void makeVect(list<object> &stack)
{
    object current;
    vect tempV;
    while(!stack.empty() && stack.front().isComp == true)
    {
        current = stack.front();
        stack.pop_front();
        tempV.elList.push_front(current.comp_data);
    }

    object tempO(tempV);

    stack.push_front(tempO);


}

void trans(list<object> &stack)
{
    object current;
    object temp;
    current = stack.front();
    stack.pop_front();
    temp.matrix_data = ++(current.matrix_data);
    stack.push_front(temp);
}

void makeMatrix(list<object> &stack)
{
    object current;
    matrix tempM;

    while(!stack.empty() && stack.front().isVect == true)
    {
        current = stack.front();
        stack.pop_front();
        tempM.vList.push_front(current.vect_data);
    }

    object tempO(tempM);
    stack.push_front(tempO);
}

void define(list<object> &stack)
{
    object temp1,temp2,temp3;

    temp1 = stack.front();
    stack.pop_front();

    temp2 = stack.front();
    stack.pop_front();
  //  cout << "Hi" <<temp2.toString()  << endl;
    if(temp1.isVar){
        temp3 = object(temp1.name,temp2);
        varList.push_back(temp3);
    }

    stack.push_front(temp3);

    //cout << varList.back().name << "=" << varList.back().

}

void help(list<object> &stack)
{
    cout << "********************************************************************************" <<endl;
    cout <<"Enter commands and arguments in form: arg1 arg2 .... argn command. For example:"<< endl << "4 10i + returns 4 + 10i" <<endl;
    cout <<"You can chain commands to evaluate more complicated expressions. For example:" << endl << "3 5 + 4 2 - / returns 4"<<endl;
    cout << "********************************************************************************" <<endl;
    stack.push_front(object());
}
