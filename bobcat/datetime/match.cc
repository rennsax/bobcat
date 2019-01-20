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
        case 4:                 // only true or false
            spec = DSTSpec{ s_spec[3] == "true" };
        break;

        case 6:                 // true or false, minutes
            spec = DSTSpec{ s_spec[3] == "true", 
                            static_cast<int>(stoul(s_spec[5])) };
        break;

        case 7:                 // minutes
            spec = DSTSpec{ static_cast<int>(stoul(s_spec[6])) };
        break;

        case 9:                 // hh:mm hh:mm
            try
            {
                spec = DSTSpec{ s_spec[7], s_spec[8] };
            }
            catch (exception const &exc)
            {
                cerr << exc.what() << '\n';
                throw 1;
            }
        break;

        case 11:                 // hh:mm hh:mm minutes
            spec = DSTSpec{ s_spec[7], s_spec[8], 
                            static_cast<int>(stoul(s_spec[10])) };
        break;

        default:
        throw 1;
    }

    if (s_zone.find(s_spec[1]) != s_zone.end())
        cerr << "Warning: in `" << fname << "' line " << lineNr << 
            ": redefining zone " << s_spec[1] << '\n';

    s_zone[s_spec[1]] = spec;

}
catch (...)
{
    cerr << fname << " line " << lineNr << 
            ": format error in line `" << line << "'\n";
}

