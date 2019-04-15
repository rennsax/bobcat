inline IRandStream::IRandStream(int min, int max, size_t seed)
:
    Randbuffer(min, max, seed),
    std::istream(this)
{}
