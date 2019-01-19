inline DateTime::DSTSpec::DSTSpec(bool supportsDST, int dstMinutes)
:
    d_dstSeconds(supportsDST ? asSeconds(dstMinutes) : 0)
{
    d_dates.d_supportsDST = supportsDST;
}
