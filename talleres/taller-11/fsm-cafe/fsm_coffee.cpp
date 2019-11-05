#include "systemc.h"

#include <stdio.h>

#define BLACK_COFFEE 1
#define LATTE_COFFEE 2
#define CAPUCCINO_COFFEE 4

#define Idle_state 1
#define Coffee_selected_state 2
#define Drop_coffee_state 3
#define Drop_milk_state 4
#define Drop_sugar_state 5
#define Waiting_deliver_state 6

SC_MODULE (fsm_coffee)
{
    sc_in<bool>             clk;
    sc_in<bool>             reset;
    sc_in<bool>             enable;
    sc_in<bool>             start;
    sc_in< sc_uint<3> >     select;
    sc_in< sc_uint<3> >     action_ready;
    sc_in<bool>             delivered;
    sc_out< sc_uint<4> >    state;
    sc_out<bool>            dropping_coffee;
    sc_out<bool>            dropping_milk;
    sc_out<bool>            dropping_sugar;

    // local variables
    sc_uint<4> actual_state;
    sc_uint<4> next_state;
    sc_uint<3> selection;

    void fsm_coffee_run ()
    {
        if( reset.read() == 1 )
        {
            actual_state = Idle_state;
            next_state = Idle_state;

            dropping_coffee.write(0);
            dropping_milk.write(0);
            dropping_sugar.write(0);
        }
        else if( enable.read() == 1 )
        {
            switch (actual_state)
            {
            case Idle_state:
                if( start.read() == 1 )
                {
                    next_state = Coffee_selected_state;
                }
                break;
            
            case Coffee_selected_state:
                if( select.read() == BLACK_COFFEE )
                {
                    selection = 0x1;
                }
                else if ( select.read() == LATTE_COFFEE )
                {
                    selection = 0x3;
                }
                else if ( select.read() == CAPUCCINO_COFFEE )
                {
                    selection = 0x7;
                }

                next_state = Coffee_selected_state;
                if( select.read() == 1 )
                    next_state = Drop_coffee_state;
                break;

            case Drop_coffee_state:
                if( selection >= 1 )
                {
                    dropping_coffee.write(1);
                    dropping_milk.write(0);
                    dropping_sugar.write(0);
                }

                next_state = Drop_coffee_state;
                if( action_ready.read() == 1 )
                    next_state = Drop_milk_state;
                break;

            case Drop_milk_state:
                if( selection >= 3 )
                {
                    dropping_coffee.write(0);
                    dropping_milk.write(1);
                    dropping_sugar.write(0);

                }

                next_state = Drop_milk_state;
                if( action_ready.read() == 2 )
                    next_state = Drop_sugar_state;
                break;

            case Drop_sugar_state:
                if( selection >= 7 )
                {
                    dropping_coffee.write(0);
                    dropping_milk.write(0);
                    dropping_sugar.write(1);

                }

                next_state = Drop_sugar_state;
                if( action_ready.read() >= 4 )
                    next_state = Waiting_deliver_state;
                break;

            case Waiting_deliver_state:
                next_state = Waiting_deliver_state;
                if( delivered.read() == 1 )
                    next_state = Idle_state;
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