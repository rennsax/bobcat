#include "ldc.ih"

LDC::LDC(BigInt const &bigInt, size_t radix)    
:
    LDC()
{
    char *bytes = bigInt.bigEndian();
    LDC tmp{ bigInt.sizeInBytes(), bytes, radix };
    delete[] bytes;

    swap(tmp);
}







