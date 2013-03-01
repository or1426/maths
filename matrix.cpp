#include "main.h"

matrix::matrix(const matrix &param)
{
    vList = param.vList;
    isComplex = param.isComplex;
    isVector = param.isVector;
}

matrix::matrix(const vect &param)
{
    vList = list<vect>(1,param);
    isComplex = false;
    // cout << "HI";
    isVector = true;
}

matrix::matrix(const comp &param)
{
    vList = list<vect>(1,vect(param));
    isComplex = true;
    isVector = false;
}

matrix::matrix()
{
    isComplex = false;
    isVector = false;
}

bool matrix::operator = (matrix param)
{
    vList = param.vList;
    isComplex = param.isComplex;
    isVector = param.isVector;
    return 0;
}

matrix matrix::operator + (matrix param)
{
    matrix temp1 = *this,temp2 = param,temp3;
    vect v1,v2;

    //  if(param.vList.size() == vList.size() && param.vList.front().elList.size() == vList.front().elList.size())
    //  {
    while(!temp1.vList.empty())
    {
        v1 = temp1.vList.front();
        temp1.vList.pop_front();
        v2 = temp2.vList.front();
        temp2.vList.pop_front();
        temp3.vList.push_back(v1 + v2);
    }
    //  }

    // cout << isVector << param.isVector <<temp3.isVector;
    if(isVector == true || param.isVector == true )
    {
        temp3.isVector = true;
    }
    if(isComplex == true || param.isComplex == true )
    {
        temp3.isComplex = true;
    }
    //  cout << temp3.toString()<<endl;
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

    if(param.vList.size() == vList.size() && param.vList.front().elList.size() == vList.front().elList.size())
    {
        while(!temp1.vList.empty())
        {
            v1 = temp1.vList.front();
            temp1.vList.pop_front();
            v2 = temp2.vList.front();
            temp2.vList.pop_front();
            temp3.vList.push_back(v1 * v2);
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
