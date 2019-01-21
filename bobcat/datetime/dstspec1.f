inline DateTime::DSTSpec::DSTSpec(bool supportsDST, int dstMinutes)
:
    d_supportsDST(supportsDST),
    d_dstSeconds(supportsDST ? asSeconds(dstMinutes) : 0)
{}
