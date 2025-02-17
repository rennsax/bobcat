#include "diffiehellman.ih"

DiffieHellman::DiffieHellman(size_t primeLength, size_t generator, 
                             bool progress)
:
    d_dh(DH_new()),
    d_otherPubKey(0)
{
    if (primeLength < 1024)
        throw Exception{} << "DiffieHellman key length must be >= 1024";

    if (progress)                   // if true, prime generation is shown
        cout << '\n';               // as a series of dots etc, which start
                                    // on a new line

    BN_GENCB *cb = BN_GENCB_new();
    BN_GENCB_set(cb, callback, 0);

                                    // Generate prime (p), using generator    
    if (not DH_generate_parameters_ex(d_dh, primeLength, generator, 
                progress ? cb : 0))
        throw Exception{} << s_header << "generating parameters failed";

    BN_GENCB_free(cb);

    if (progress)
        cout << endl;

    checkDHparameters();            // verify the validity of p and generator
}
