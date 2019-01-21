inline DateTime::DSTSpec::DSTSpec(int dstMinutes)
:
    d_supportsDST(true),
    d_dstSeconds(asSeconds(dstMinutes))
{}
