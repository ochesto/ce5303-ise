#include "systemc.h"

#include "first_counter.cpp"

int sc_main (int argc, char *argv[])
{
    sc_signal<bool>         clock;
    sc_signal<bool>         reset;
    sc_signal<bool>         enable;
    sc_signal<sc_uint<4> >   counter_out;
    int i = 0;

    // Connect the DUT
    first_counter counter("COUNTER");
    counter.clock(clock);
    counter.reset(reset);
    counter.enable(enable);
    counter.counter_out(counter_out);

    sc_start(1, SC_NS);

    // Open VCD file
    sc_trace_file *wf = sc_create_vcd_trace_file("counter");

    // Dump the desire signals
    sc_trace(wf, clock, "clock");
    sc_trace(wf, reset, "reset");
    sc_trace(wf, enable, "enable");
    sc_trace(wf, counter_out, "counter_out");

    // Initialize all variables
    reset = 0;
    enable = 0;
    for (i = 0; i < 5; i++)
    {
        clock = 0;
        sc_start(1, SC_NS);
        clock = 1;
        sc_start(1, SC_NS);
    }

    // Assert the reset
    reset = 1;
    cout << "@" << sc_time_stamp() << " :: Asserting_reset" << endl;

    for (i = 0; i < 10; i++)
    {
        clock = 0;
        sc_start(1, SC_NS);
        clock = 1;
        sc_start(1, SC_NS);
    } 

    // De-assert the reset
    reset = 0;
    cout << "@" << sc_time_stamp() << " :: De-asserting_reset" << endl;
    for (i = 0; i < 5; i++)
    {
        clock = 0;
        sc_start(1, SC_NS);
        clock = 1;
        sc_start(1, SC_NS);
    }

    // Assert the enable
    enable = 1;
    cout << "@" << sc_time_stamp() << " :: Asserting_enable" << endl;
    for (i = 0; i < 20; i++)
    {
        clock = 0;
        sc_start(1, SC_NS);
        clock = 1;
        sc_start(1, SC_NS);
    }

    // De-assert the enable
    enable = 0;
    cout << "@" << sc_time_stamp() << " :: De-asserting_enable" << endl;

    // Terminating simulation
    cout << "@" << sc_time_stamp() << " :: Terminating_simulation" << endl;
    
    // Close VCD file
    sc_close_vcd_trace_file(wf);

    return 0;
}