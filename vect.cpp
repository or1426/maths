#include "main.h"
bool vect::operator = (vect param)
{
    elList = param.elList;

    return 0;
}

vect::vect(const comp &param){
    elList = list<comp>(1,param);
}

vect::vect(const vect &param){
    list<comp> temp = param.elList;
    comp c;
    while(!temp.empty()){
            c = temp.front();
            temp.pop_front();
            elList.push_back(c);
    }
}

vect::vect(list<comp> inList){
    list<comp> temp = inList;
    comp c;
    while(!temp.empty()){
            c = temp.front();
            temp.pop_front();
            elList.push_back(c);
    }
}

vect vect::operator + (vect param)
{
    vect temp1 = *this,temp2 = param,temp3;
    comp c1,c2;

    if(param.elList.size() == elList.size())
    {
        while(!temp1.elList.empty()){
            c1 = temp1.elList.front();
            temp1.elList.pop_front();
            c2 = temp2.elList.front();
            temp2.elList.pop_front();
            temp3.elList.push_back(c1 + c2);
        }
    }

    return temp3;
}

vect vect::operator - (vect param)
{
    vect temp1 = *this,temp2 = param,temp3;
    comp c1,c2;

    if(param.elList.size() == elList.size())
    {
        while(!temp1.elList.empty()){
            c1 = temp1.elList.front();
            temp1.elList.pop_front();
            c2 = temp2.elList.front();
            temp2.elList.pop_front();
            temp3.elList.push_back(c1 - c2);
        }
    }
    return temp3;
}
vect vect::operator * (vect param)
{
    vect temp1 = *this,temp2 = param;
    comp c1,c2,s;

    if(param.elList.size() == elList.size())
    {
        while(!temp1.elList.empty()){
            c1 = temp1.elList.front();
            temp1.elList.pop_front();
            c2 = temp2.elList.front();
            temp2.elList.pop_front();
            s = s + c1 * c2;
        }
    }
    vect temp3(s);

    return temp3;
}

vect vect::operator / (vect param)
{
    vect temp1 = *this,temp2 = param,temp3;
    comp c1,c2;

    if(param.elList.size() == elList.size())
    {
        while(!temp1.elList.empty()){
            c1 = temp1.elList.front();
            temp1.elList.pop_front();
            c2 = temp2.elList.front();
            temp2.elList.pop_front();
            temp3.elList.push_back(c1 / c2);
        }
    }
    return temp3;
}

string vect::toString(){
    stringstream temp;
    comp tempC;
    vect tempV(*this);
    temp << "(";

    while(!tempV.elList.empty()){
            tempC = tempV.elList.front();
            tempV.elList.pop_front();
            temp << tempC.toString();
            if(!tempV.elList.empty()){temp << ",";}
        }
        temp << ")";

    return temp.str();
}
