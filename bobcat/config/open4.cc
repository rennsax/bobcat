#include "config.ih"

void CF_Pimpl::open(istream &stream)
{
    clear();

    string line;
    while (nextLine(stream, line))  // add the lines to d_line
        d_line.push_back({ d_rawNumber, std::move(line) });
}
