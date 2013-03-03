#include "main.h"

matrix::matrix(const matrix &param)
{
    vList = param.vList;

}

matrix::matrix(const vect &param)
{
    vList = list<vect>(1,param);

}

matrix::matrix(const comp &param)
{
    vList = list<vect>(1,vect(param));

}

matrix::matrix()
{

}

bool matrix::operator = (matrix param)
{
    vList = param.vList;

    return 0;
}

matrix matrix::operator + (matrix param)
{
    matrix temp1 = *this,temp2 = param,temp3;
    vect v1,v2;

    if(param.vList.size() == vList.size() && param.vList.front().elList.size() == vList.front().elList.size())
    {
    while(!temp1.vList.empty())
    {
        v1 = temp1.vList.front();
        temp1.vList.pop_front();
        v2 = temp2.vList.front();
        temp2.vList.pop_front();
        temp3.vList.push_back(v1 + v2);
    }
    }

    return temp3;
}

matrix matrix::operator - (matrix param)
{
    matrix temp1 = *this,temp2 = param,temp3;
    vect v1,v2;

    if(param.vList.size() == vList.size() && param.vList.front().elList.size() == vList.front().elList.size())
    {
        while(!temp1.vList.empty())
        {
            v1 = temp1.vList.front();
            temp1.vList.pop_front();
            v2 = temp2.vList.front();
            temp2.vList.pop_front();
            temp3.vList.push_back(v1 - v2);
        }
    }
    return temp3;
}

matrix matrix::operator * (matrix param)
{
    matrix temp1 = *this,temp2 = param,temp3;
    vect v1,v2;
    temp2 = ++temp2;

    if(temp2.vList.size() == temp1.vList.size() && temp2.vList.front().elList.size() == temp1.vList.front().elList.size())
    {
        for(std::list<vect>::iterator m1it=temp1.vList.begin(); m1it != temp1.vList.end(); ++m1it){
            vect v3;
            for(std::list<vect>::iterator m2it=temp2.vList.begin(); m2it != temp2.vList.end(); ++m2it){
                v1 = *m1it;
                v2 = *m2it;
                v3.elList.push_back(v1*v2);
            }
            temp3.vList.push_back(v3);
        }
    }
    return temp3;
}

matrix matrix::operator / (matrix param)
{
    matrix temp1 = *this,temp2 = param,temp3;
    vect v1,v2;

    if(param.vList.size() == vList.size() && param.vList.front().elList.size() == vList.front().elList.size())
    {
        while(!temp1.vList.empty())
        {
            v1 = temp1.vList.front();
            temp1.vList.pop_front();
            v2 = temp2.vList.front();
            temp2.vList.pop_front();
            temp3.vList.push_back(v1 / v2);
        }
    }
    return temp3;
}

matrix matrix::operator * (comp param){
    matrix temp1 = *this,temp2;
    vect v1;
    while(!temp1.vList.empty())
    {
            v1 = temp1.vList.front();
            temp1.vList.pop_front();
            v1 = v1 * param;
            temp2.vList.push_back(v1);
    }

    return temp2;
}
vect matrix::operator * (vect param){
    matrix temp1 = *this;
    vect v1,v2;
    while(!temp1.vList.empty())
    {
            v1 = temp1.vList.front();
            temp1.vList.pop_front();
            v2.elList.push_back(v1 * param);
    }
    return v2;

}
matrix matrix::operator ++ ()
{
    matrix temp1, temp2(*this);
    while(!temp2.vList.back().elList.empty())
    {
        vect tempV;
        for (std::list<vect>::iterator it=temp2.vList.begin(); it != temp2.vList.end(); ++it)
        {
            tempV.elList.push_back((*it).elList.front());
            (*it).elList.pop_front();
        }
        temp1.vList.push_back(tempV);
    }

    return temp1;
}

string matrix::toString()
{

    stringstream temp;
    vect tempV;
    matrix tempM(*this);

    temp << "{";

    while(!tempM.vList.empty())
    {
        tempV = tempM.vList.front();
        tempM.vList.pop_front();
        temp << tempV.toString();
    }
    temp << "}";

    return temp.str();

};
