#include "cryptbuf.ih"

namespace FBB
{
    std::ostream &end(std::ostream &out)
    {
        CryptBuf *buf = dynamic_cast<CryptBuf *>(out.rdbuf());
    
        if (buf != 0)
            buf->end_();            // call the appropriate 
    
        return out;
    }
}
