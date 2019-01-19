#include "datetime.ih"

    // the return type is pseudo; it it used to prevent a compiler
    // warning in parsetime.cc

// static
void DateTime::timeException() 
{
    throw Exception{ 1 } << "error in time specification";
}
