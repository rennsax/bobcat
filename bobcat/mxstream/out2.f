inline MxStream::Out::Out(Out &&tmp)
:
    std::ostream(tmp.rdbuf())
{}
