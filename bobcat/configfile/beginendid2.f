inline CF_Types::RE_iteratorPair CF_Pimpl::beginEndID(std::string const &re)
{
    return beginEnd(re, &CF_Pimpl::findID);
}
