inline DateTime::DSTSpec::DSTSpec(int dstMinutes)
:
    d_dstSeconds(asSeconds(dstMinutes))
{
    d_dates.d_supportsDST = true;
}
