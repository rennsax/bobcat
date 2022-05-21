#include "ldc.ih"

LDC::LDC(BigInt const &bigInt, string const &digits)    
:
    LDC()
{
    char *bytes = bigInt.bigEndian();
    LDC tmp{ bigInt.sizeInBytes(), bytes, digits };
    delete[] bytes;

    swap(tmp);
}







