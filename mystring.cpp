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
    }else{
        if(*str.begin() != 'i'){
            ret = 0;
        }
    }

    return ret;
}


comp myString::value()
{
    stringstream ss (stringstream::in | stringstream::out);
    comp temp;
    ss << str << endl;
    if(isReal()){
        ss >> temp.re;

    }else if(isImag()){
        if(str.size() ==1){
            temp.im = 1;
        }else{
            ss >> temp.im;

        }
    }

    return temp;
}


bool myString::isOp(){

        for (std::list<op>::iterator it=opList.begin(); it != opList.end(); ++it){
                if(str == (*it).opCode){
                    return 1;
                }
            }

    return 0;
}
