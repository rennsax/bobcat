#include "ldc.ih"

LDC::LDC(string const &hexStr, size_t radix)    // e.g., deadbeef, no 0x
{
    string hexNr{ hexStr };

    setRadix(radix);


    bytes2hex(hexNr);           // hexNr's elements now contain hex digit
                                // values  

                                // at least SIZE bytes, 1 extra byte for odd-
    compress(hexNr);            // sized digits -> room for the final digit
    convert();
}







