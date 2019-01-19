#include "datetime.ih"

// static
void DateTime::readZones(std::string const &fname, bool header, char sep)
{
    ifstream in = Exception::factory<ifstream>(fname);  // open the file
    CSV4180 csv{ 2, header, sep };

    while (in >> csv)
    {
        auto &&vect = csv.release();
        addZone(vect[0][0], stol(vect[0][1]));
    }    
}
