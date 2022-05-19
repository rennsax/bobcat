#include "ldc.ih"

void LDC::setRadix(size_t radix)
{
    if (radix < 2 or radix > 36)
        throw Exception{} << "radix must be >= 2 and <= 36";

    d_radix = radix;
}
