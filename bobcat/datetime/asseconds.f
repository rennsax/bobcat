inline int DateTime::asSeconds(int minutes)
{
    return  minutes / 30 * 30       // multiples of 30 minutes
            % (12 * 60)             // at most 12 hours
            * 60;                   // minutes to seconds
}
