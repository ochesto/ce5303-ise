#include "systemc.h"
#include "fsm_coffee.cpp"

int sc_main (int agrc, char *argv[])
{
    sc_signal<bool>             clock;
    sc_signal<bool>             reset;
    sc_signal<bool>             enable;
    sc_signal< sc_uint<3> >     select;
    sc_signal< sc_uint<4> >     state_out;
    int i = 0;

    // Connect the DUT
    fsm_coffee coffe_machine("COFFEE-MACHINE");
    coffe_machine.clk(clock);
    coffe_machine.reset(reset);
    coffe_machine.enable(enable);
    coffe_machine.state(state_out);

    sc_start(1, SC_NS);

    // Open VCD file
    sc_trace_file *wf = sc_create_vcd_trace_file("coffee-machine");

    // Dump the desire signals
    sc_trace(   wf, clock,      "clk"       );
    sc_trace(   wf, reset,      "reset"     );
    sc_trace(   wf, enable,     "enable"    );
    sc_trace(   wf, state_out,  "state_out" );

    // Initialize simulation
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
    for (i = 0; i < 10; i++)
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
    for (i = 0; i < 5; i++)
    {
        clock = 0;
        sc_start(1, SC_NS);
        clock = 1;
        sc_start(1, SC_NS);
    }

    // Terminating simulation
    cout << "@" << sc_time_stamp() << " :: Terminating_simulation" << endl;

    // Close VCD file
    sc_close_vcd_trace_file(wf);

    return 0;
}