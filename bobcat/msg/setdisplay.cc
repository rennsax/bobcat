#include "msg.ih"

bool Msg::setDisplay(bool mode) 
{
    bool old = display();

    for_each(s_streams, s_streams + s_nStreams, 
                FnWrap::unary(setActive, mode));

    return old;
}
