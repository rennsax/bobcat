#include "datetime.ih"

    // the return type is pseudo; it it used to prevent a compiler
    // warning in parsetime.cc

// static
DateTime::Parse DateTime::timeException(string const &timeStr) 
{
    throw Exception{ 1 } << "error in time specification `" << timeStr << 
                                                                '\'';
}
