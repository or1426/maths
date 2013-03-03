#include "main.h"

bool myString::isReal()
{
    locale loc;
    bool ret = 1;

    for(string::iterator it = str.begin(); it != str.end(); ++it)
    {
        if(!isdigit(*it,loc) && !(*it =='.'))
        {
            ret = 0;
        }
    }
    return ret;
}

bool myString::isImag()
{
    locale loc;
    bool ret = 1;
    string::iterator en = str.end();
    if(str.size() != 1)
    {
        --en;
        --en;
        for(string::iterator it = str.begin(); it != en; ++it)
        {

            if(!isdigit(*it,loc) && !(*it =='.'))
            {
                ret = 0;
            }
        }
        ++en;
        if(*en != 'i')
        {
            ret = 0;
        }
    }
    else
    {
        if(*str.begin() != 'i')
        {
            ret = 0;
        }
    }

    return ret;
}


bool myString::isValid()
{
    locale loc;
    bool ret = 1;

    if(str == string("i"))
    {
        return 0;
    }



    for(string::iterator it = str.begin(); it != str.end(); ++it)
    {
        if(!isalpha(*it,loc))
        {
            ret = 0;
        }
    }
    return ret;
}

bool myString::isDefined()
{

    for(list<object>::iterator it = varList.begin(); it != varList.end(); ++it)
    {
        if((*it).name == str)
        {
            return 1;
        }
    }

    return 0;
}


object myString::value()
{
    stringstream ss (stringstream::in | stringstream::out);
    comp temp;
    object tempO;
    ss << str << endl;

    if(isValid() && !isOp())
    {
        if(isDefined())
        {
            for(list<object>::iterator it = varList.begin(); it != varList.end(); ++it)
            {
                if((*it).name == str)
                {
                    tempO = (*it);
                }
            }
        }
        else
        {
            tempO = object(str);
        }
    }
    else if(isReal())
    {
        ss >> temp.re;
        tempO = object(temp);
    }
    else if(isImag())
    {
        if(str.size() ==1)
        {
            temp.im = 1;
        }
        else
        {
            ss >> temp.im;

        }
        tempO = object(temp);
    }


    //cout << tempM.toString()<<endl;
    return tempO;
}


bool myString::isOp()
{

    for (std::list<op>::iterator it=opList.begin(); it != opList.end(); ++it)
    {
        if(str == (*it).opCode)
        {
            return 1;
        }
    }

    return 0;
}


