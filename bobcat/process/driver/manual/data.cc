#include "main.ih"

unique_ptr<Pipe> d_child_inp;          // cin read by the CHILD
unique_ptr<Pipe> d_child_outp;         // cout written by the CHILD

OFdBuf    d_childCinbuf; 
IFdBuf    d_childCoutbuf;

ostream   d_childCin(0);            // Parent inserts child cin
istream   d_childCout(0);           // Parent extr. child cout

IOStream io(d_childCout, d_childCin);

pid_t pid;
string line;

int p1;
int p2;

int oldIn;
int oldOut;





