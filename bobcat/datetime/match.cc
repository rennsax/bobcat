#include "datetime.ih"

// static
void DateTime::ZoneNames::match(string const &fname, size_t lineNr,
                                                     string const &line)
try
{
    s_spec.match(line);
    DSTSpec spec;

    switch (s_spec.end())       // see demo.cc for s_spec definition
    {
        case 5:                 // only true or false
            spec = DSTSpec{ s_spec[4] == "true" };
        break;

        case 7:                 // true or false, minutes
            spec = DSTSpec{ s_spec[4] == "true",
                            static_cast<int>(stoul(s_spec[6])) };
        break;

        case 8:                 // minutes
            spec = DSTSpec{ static_cast<int>(stoul(s_spec[7])) };
        break;

        case 10:                // hhmm hhmm
            try
            {
                spec = DSTSpec{ s_spec[8], s_spec[9] };
            }
            catch (exception const &exc)
            {
                cerr << exc.what() << '\n';
                throw 1;
            }
        break;

        case 12:                 // hh:mm hhmm minutes
            spec = DSTSpec{ s_spec[8], s_spec[9],
                            static_cast<int>(stol(s_spec[11])) };
        break;

        default:
        throw 1;
    }

    if (s_zone.find(s_spec[1]) != s_zone.end())
        cerr << "Warning: in `" << fname << "' line " << lineNr <<
            ": redefining zone " << s_spec[1] << '\n';

    s_zone[s_spec[1]] = { static_cast<int>(stol(s_spec[2])), spec };

}
catch (...)
{
    cerr << fname << " line " << lineNr <<
            ": format error in line `" << line << "'\n";
}
