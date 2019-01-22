#include "datetime.ih"

// static
void DateTime::readZones(std::string const &fname)
{
    ifstream in = Exception::factory<ifstream>(fname);  // open the file

    size_t count = 0;
    string line;

    while (getline(in, line))
    {
        ++count;

        line = String::trim(line);
        if (line.empty() || line[0] == '#')
            continue;
        
            // name: zoneminutes true|false [dstminutes]
            // name: zoneminutes dstminutes
            // name: zoneminutes begin end [dstminutes]
        ZoneNames::match(fname, count, line);
    }
}
