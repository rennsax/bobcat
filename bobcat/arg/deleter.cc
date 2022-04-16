#include "arg.ih"

Arg::Deleter::~Deleter()
{
    cout << "********DELETING S_ARG\n";
    delete s_arg;
}

void Arg::deleter()
{
    static Deleter deleter;    
}
