#ifndef INCLUDED_LDC_
#define INCLUDED_LDC_

#include <ostream>
#include <string>

    // in the sources:  MSB means most significant byte
    //                  LSB: least significant byte. See the README file
class LDC
{
    using CHAR = unsigned char;
    using VALUE = size_t;           // usually sizeof(size_t) >= 
                                    //         sizeof(uint64_t)

    enum
    {
        SIZE = sizeof(VALUE)
    };

    union Ptrs
    {
        CHAR *ptr;
        VALUE *valuePtr;             // interpret byte sequence as VALUE
    };

    union Cpt
    {
        VALUE value;
        CHAR bytes[SIZE];
    };

    size_t d_size;                      // size of the buffers
    size_t d_radix;

    bool d_cb = false;                  // index of the d_buffer element 
                                        // containing the cpv bytes

    Ptrs d_begin;                       // address and value of the currently
                                        // processed value (cpv)
    CHAR *d_lsb;                        // location of the full value's LSB
    CHAR *d_end;                        // beyond the cpv

    CHAR *d_divEnd;                     // beyond the bytes of the div10 value
    CHAR *d_divBegin;                   // the first byte of the div10 value

        // beyond the quotient's bytes pointed at by d_divEnd there are SIZE
        // bytes so when a small value is stored in the buffer the value at
        // d_divBegin always points to a VALUE value
    CHAR *d_buffer[2];                  // buffers containing the cpb ([0])
                                        // and cpb / 10 ([1]) + SIZE / 2
                                        // spare bytes at the end so at least
                                        // VALUE values fit. 

    std::string d_converted;

    public:
        LDC();                                                          // 1

        LDC(std::string const &hexNr,   // input is a hex number in a      2
           size_t radix = 10);          // string e.g., deadbeef 
                                        // (no 0x prefix)

                                        // bytes contains the
                                        // binary big endian representation of
                                        // the number using nBytes 
        LDC(size_t nBytes, char const *bytes, size_t radix = 10);       // 3

        LDC(LDC const &other);                                          // 4
        LDC(LDC &&tmp);                                                 // 5

       ~LDC();

        LDC &operator=(LDC const &rhs);                                 // 1
        LDC &operator=(LDC &&tmp);                                      // 2
        LDC &operator=(std::string const &hexNr);  // uses radix 10        3

        void set(std::string const &hexNr, size_t radix = 10);
        void set(size_t nBytes, char const *bytes, size_t radix = 10);

        std::string const &str() const;

        void swap(LDC &other);                                          // 1

    private:
        static void bytes2hex(std::string &arg);

        void compress(std::string const &hexNr);

        void compressDigits(std::string const &hexNr);

        void convert();                         // convert to d_radix

        void guardBegin();                      // ensure d_begin.ptr >= d_lsb

        int idx(CHAR *ptr, bool bufIdx) const;

                                                // inserts current and next 
                                                // buffer indices into out
        std::ostream &indices(std::ostream &out) const;

                                                // install div_10 in 
        void installDiv10(VALUE div10Value); // d_begin[not d_cpt]

        void prepareBuffers();

        void reduce();                          // reduced digits to d_ret

        void setDivPtrs();                      // initialize the div-ptrs

        void setRadix(size_t radix);

        static std::ostream &show(std::ostream &out,
                                  std::string const &digits);
        std::ostream &showCb(std::ostream &out) const;
        std::ostream &showDiv(std::ostream &out) const;

        void swap();                            // swap begin/end with      2
                                                // nextBegin/nextEnd
};

#include "ldc.f"
    
#endif
