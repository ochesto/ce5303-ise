#include "systemc.h"

SC_MODULE (hello_world) 
{
    SC_CTOR (hello_world) 
    {
        // nothing in constructor
    }

    void be_nice() 
    {
        cout << "Hello world from systemc" << endl;
    }
};

int sc_main(int argc, char *argv[])
{
    hello_world hello("NULL");
    hello.be_nice();

    return(0);
}