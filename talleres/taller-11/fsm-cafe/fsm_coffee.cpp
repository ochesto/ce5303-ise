#include "systemc.h"

SC_MODULE (fsm_coffee)
{
    sc_in<bool>             clk;
    sc_in<bool>             reset;
    sc_in<bool>             enable;
    sc_in< sc_uint<3> >     select;
    sc_out< sc_uint<4> >    state;

    // local variables
    sc_uint<4> actual_state;
    sc_uint<4> next_state;

    void fsm_coffee_run ()
    {
        if( reset.read() == 1 )
        {
            actual_state = 0;
            next_state = 0;
        }
        else if( enable.read() == 1 )
        {
            switch (actual_state)
            {
            case 0:
                next_state = 1;
                break;
            
            case 1:
                next_state = 2;
                break;

            case 2:
                next_state = 0;
                break;

            default:
                break;
            }

            actual_state = next_state;
            state.write(actual_state);
        }
    }; // end fsm_coffee_run

    SC_CTOR (fsm_coffee)
    {
        cout << " :: Executing_new_fsm_coffee" << endl;
        SC_METHOD (fsm_coffee_run);
        sensitive << reset;
        sensitive << clk.pos();
    }; // end SC_CTOR fsm_coffee
};