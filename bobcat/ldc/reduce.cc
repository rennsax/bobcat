#include "ldc.ih"

void LDC::reduce()
{
    while (true)
    {                                       // store value / 10 at d_divEnd
        installDiv10(*d_begin.valuePtr / d_radix);   

        *d_begin.valuePtr %= d_radix;     // compute the radix value

        if (d_begin.ptr == d_lsb)           // all digits were processed
            break;
                                            // not all digits were processed
                                            // the next value ends at (beyond)
                                            // the byte holding the remainder
        d_end = d_begin.ptr + 1;            // (% 10) of the current value    

                                            // ensure that d_begin.ptr points
        guardBegin();                       // at or beyond the value's LSB
    }
                                            // the remainder is always < 10:
                                            // add the remainder as the next
    CHAR ch = *d_begin.ptr;

    ch += ch < 10 ? '0' : 'a' - 10;
    d_converted += ch;                      // digit to 'd_converted'
}

