#include <iostream>
#include <string>
#include <list>
#include <locale>
#include <sstream>

#include <cstring>
#include <cstdlib>

#include "comp.h"
#include "vect.h"
#include "matrix.h"
#include "op.h"
#include "myString.h"

using namespace std;

void eval(list<myString> input);

void add(list<matrix> &stack);
void sub(list<matrix> &stack);
void mul(list<matrix> &stack);
void div(list<matrix> &stack);
void makeVect(list<matrix> &stack);
void trans(list<matrix> &stack);
void makeMatrix(list<matrix> &stack);
void help(list<matrix> &stack);
extern list<op> opList;
