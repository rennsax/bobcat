//#define XERR
#include "configfile.ih"

CF_Types::RE_iteratorPair CF_Pimpl::beginEnd(
                    std::string const &re,
                    const_iterator (CF_Pimpl::*find)(std::string const &,
                                          const_iterator const &) const
)
{
    d_CIvect.clear();

    auto beyond = end();
    auto from = begin();

    while (true)
    {
        from = (this->*find)(re, from);

        if (from == beyond)
            break;

        d_CIvect.push_back(from);
        ++from;
    }

    return RE_iteratorPair{ d_CIvect.cbegin(), d_CIvect.cend() };
}
