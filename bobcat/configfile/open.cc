#include "configfile.ih"

void CF_Pimpl::open(string const &fname)
{
    ifstream stream{ Exception::factory<ifstream>(fname) };

    d_line.clear();                 // clear the vector
    d_CIvect.clear();               // clear iterators to matching lines

//    d_re.clear();                   // clear a previously set search RE

    d_rawNumber = 0;                // re-initialize the line-number count
                                    // of the original file

    string line;
    while (nextLine(stream, line))  // add the lines to d_line
        d_line.push_back({ d_rawNumber, std::move(line) });
}

void ConfigFile::open(string const &fname)
{
    d_ptr->open(fname);
}
