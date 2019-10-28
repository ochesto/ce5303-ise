Compilación:

    g++ -I/opt/systemc/include -L/opt/systemc/lib-linux64 -o hellobin hello.cpp -lsystemc -lm

Si el proceso falla, se debe agregar al comando anterior:

    -std=c++98