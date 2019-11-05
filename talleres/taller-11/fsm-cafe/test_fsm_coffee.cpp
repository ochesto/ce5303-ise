#include "systemc.h"
#include "fsm_coffee.cpp"

int sc_main (int agrc, char *argv[])
{
    sc_signal<bool>             clock_in;
    sc_signal<bool>             reset_in;
    sc_signal<bool>             enable_in;
    sc_signal<bool>             start_in;
    sc_signal< sc_uint<3> >     select_in;
    sc_signal<bool>             delivered_in;
    sc_signal< sc_uint<4> >     state_out;
    sc_signal<bool>             dropping_coffee_out;
    sc_signal<bool>             dropping_milk_out;
    sc_signal<bool>             dropping_sugar_out;
    int i = 0;

    // Connect the DUT
    fsm_coffee coffee_machine("COFFEE-MACHINE");
    coffee_machine.clk(clock_in);
    coffee_machine.reset(reset_in);
    coffee_machine.enable(enable_in);
    coffee_machine.start(start_in);
    coffee_machine.select(select_in);
    coffee_machine.delivered(delivered_in);
    coffee_machine.state(state_out);
    coffee_machine.dropping_coffee(dropping_coffee_out);
    coffee_machine.dropping_milk(dropping_milk_out);
    coffee_machine.dropping_sugar(dropping_sugar_out);

    sc_start(1, SC_NS);

    // Open VCD file
    sc_trace_file *wf = sc_create_vcd_trace_file("coffee-machine");

    // Dump the desire signals
    sc_trace(wf, clock_in, "clk_in");
    sc_trace(wf, reset_in, "reset_in");
    sc_trace(wf, enable_in, "enable_in");
    sc_trace(wf, start_in, "start_in");
    sc_trace(wf, select_in, "select_in");
    sc_trace(wf, delivered_in, "delivered_in");
    sc_trace(wf, state_out, "state_out");
    sc_trace(wf, dropping_coffee_out, "dropping_coffee_out");
    sc_trace(wf, dropping_milk_out, "dropping_milk_out");
    sc_trace(wf, dropping_sugar_out, "dropping_sugar_out");


    // Initialize simulation
    clock_in = 0;
    reset_in = 0;
    enable_in = 0;
    start_in = 0;
    select_in = 0;
    delivered_in = 0;
    for (i = 0; i < 5; i++)
    {
        clock_in = ~clock_in;
        sc_start(1, SC_NS);
        clock_in = ~clock_in;
        sc_start(1, SC_NS);
    }

    // Assert the reset_in
    reset_in = 1;
    cout << "@" << sc_time_stamp() << " :: Asserting_reset" << endl;
    for (i = 0; i < 10; i++)
    {
        clock_in = ~clock_in;
        sc_start(1, SC_NS);
        clock_in = ~clock_in;
        sc_start(1, SC_NS);
    }

    // De-assert the reset_in
    reset_in = 0;
    cout << "@" << sc_time_stamp() << " :: De-asserting_reset" << endl;
    for (i = 0; i < 10; i++)
    {
        clock_in = ~clock_in;
        sc_start(1, SC_NS);
        clock_in = ~clock_in;
        sc_start(1, SC_NS);
    }

    // Assert the enable_in
    enable_in = 1;
    cout << "@" << sc_time_stamp() << " :: Asserting_enable" << endl;
    for (i = 0; i < 20; i++)
    {
        clock_in = ~clock_in;
        sc_start(1, SC_NS);
        clock_in = ~clock_in;
        sc_start(1, SC_NS);
    }

    // Assert the start_in
    start_in = 1;
    cout << "@" << sc_time_stamp() << " :: Asserting_start" << endl;
    for (i = 0; i < 20; i++)
    {
        clock_in = ~clock_in;
        sc_start(1, SC_NS);
        clock_in = ~clock_in;
        sc_start(1, SC_NS);
    }

    

    // De-assert the start_in
    start_in = 0;
    cout << "@" << sc_time_stamp() << " :: De-asserting_start" << endl;
    for (i = 0; i < 5; i++)
    {
        clock_in = ~clock_in;
        sc_start(1, SC_NS);
        clock_in = ~clock_in;
        sc_start(1, SC_NS);
    }

    // De-assert the enable_in
    enable_in = 0;
    cout << "@" << sc_time_stamp() << " :: De-asserting_enable" << endl;
    for (i = 0; i < 5; i++)
    {
        clock_in = ~clock_in;
        sc_start(1, SC_NS);
        clock_in = ~clock_in;
        sc_start(1, SC_NS);
    }

    // Terminating simulation
    cout << "@" << sc_time_stamp() << " :: Terminating_simulation" << endl;

    // Close VCD file
    sc_close_vcd_trace_file(wf);

    return 0;
}