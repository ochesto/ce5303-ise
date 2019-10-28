#include "systemc.h"

SC_MODULE (first_counter)
{
    sc_in_clk           clock;          // Clock input
    sc_in<bool>         reset;          // Reset input
    sc_in<bool>         enable;         // Enable signal
    sc_out<sc_uint<4> >  counter_out;    // 4 bit vector

    // Local variable
    sc_uint<4>  count;

    void incr_count()
    {
        if (reset.read() == 1)
        {
            count = 0;
            counter_out.write(count);
        }
        else if (enable.read() == 1)
        {
            count = count + 1;
            counter_out.write(count);
            
            cout    << "@" 
                    << sc_time_stamp() 
                    << " :: Incremented_Counter"
                    << counter_out.read()
                    << endl;
        }
    }; // incr_count

    // Constructor for the counter
    SC_CTOR (first_counter)
    {
        cout << " :: Executing_new" << endl;

        SC_METHOD (incr_count);
        sensitive << reset;
        sensitive << clock.pos();
    }; // SC_CTOR first_counter

}; // SC_MODULE first_counter