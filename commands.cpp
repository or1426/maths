#include "main.h"

list<myString> split(string input)
{
    list<myString> outputList;

    unsigned int found = input.find(" ");
    while (found != -1)
    {
        outputList.push_back(myString(input.substr(0, found)));
        input.erase(0,found +1);
        found = input.find(" ");
    }


    outputList.push_back(myString(input));

    return outputList;

}

void eval(list<myString> input)
{
    myString current;
    list<comp> stack;
    while(!input.empty())
    {
        current = input.front();
        cout << current.str<<endl;
        input.pop_front();

        if(current.isOp())
        {
            for (std::list<op>::iterator it=opList.begin(); it != opList.end(); ++it)
            {
                if(current.str == (*it).opCode)
                {
                    (*it).execute(stack);
                }
            }
        }
        else
        {
            stack.push_front(current.value());
        }
    }

    cout << stack.front().toString();

    return;
}


