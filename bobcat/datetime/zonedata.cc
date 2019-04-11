#include "datetime.ih"

// static
DateTime::Zone::Data DateTime::Zone::data(string const &name,
                std::string shift, std::string dstSpec,
                std::string dstBegin, std::string dstEnd)
{
    if (shift[0] == ':')        // a ":Asia/Calcutta" type of specification
        return { 3600, shift }; // dst may never be used, but then tm_isdst
                                // remains 0

    if (dstSpec == "=")
        dstSpec = "1";               // use the default of 1 hr.

    checkDST(dstSpec, dstBegin, dstEnd);

    negate(shift);                      // if specified then [0] is + or -

    Data ret;
    string dstName;                     //  -> dstSpec + d

    bool useDST = not dstSpec.empty();  
    if (useDST)                         // dst was specified
    {
        dstName = name;                 // append d, if needed also >
        if (dstName.back() != '>')
            dstName += 'd';
        else
            dstName.replace((dstName.rbegin() + 1).base(), dstName.end(), 
                            "d>");
    }

    if (dstSpec.empty())                // set the DST seconds
        ret.dstSeconds = 3600;
    else
    {
        negate(dstSpec);
        ret.dstSeconds = add(dstSpec, shift);
    }
    
                                        // and the spec. (no DST section if
    ret.spec =  name + shift +          // not specified)
                    (useDST ? dstName + dstSpec : "") +
                    dstBegin + dstEnd;
    return ret;
}




