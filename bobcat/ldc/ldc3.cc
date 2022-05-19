#include "ldc.ih"

LDC::LDC(size_t nBytes, char const *bytes, size_t radix)
{
    setRadix(radix);

    d_size = nBytes + SIZE;         // always at least VALUE bytes

    prepareBuffers();

    reverse_copy(bytes, bytes + nBytes, d_lsb);

    d_end = d_lsb + nBytes;         // beyond the last byte to convert

                                    // the first div10 value is stored before
                                    // d_end: there must always be enough
                                    // bytes to handle the value as VALUE
    guardBegin();
    setDivPtrs();

    convert();
}

