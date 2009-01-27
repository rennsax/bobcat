#include "foldstreambuf.ih"

FoldStreambuf::~FoldStreambuf()
{
    if (d_mode == NON_WS)
        flush();
    else if (d_mode == WS)
    {
        if (d_handleTrailingBlanks)
        {
            if (length() <= d_rightMargin)
                writeWs();
            else
                put('\n');
        }
    }
    d_out->rdbuf()->pubsync();
}
