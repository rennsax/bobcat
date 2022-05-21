#include "ldc.ih"

    // called by LDC(string const &hexStr, ...)

void LDC::init(std::string const &hexStr)
{
    string hexNr{ String::lc(hexStr) };

    bytes2hex(hexNr);           // hexNr's elements now contain hex digit
                                // values  

                                // at least SIZE bytes, 1 extra byte for odd-
    compress(hexNr);            // sized digits -> room for the final digit
    convert();
}
