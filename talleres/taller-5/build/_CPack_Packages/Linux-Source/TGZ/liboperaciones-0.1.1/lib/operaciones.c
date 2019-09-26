
int lib_suma (int p_a, int p_b)
{
    return p_a + p_b;
}

int lib_resta (int p_a, int p_b)
{
    return p_a - p_b;
}

int lib_multiplicacion (int p_a, int p_b)
{
    return p_a * p_b;
}

int lib_division (int p_a, int p_b)
{
    return p_a / p_b;
}

double lib_raiz_cuadrada (int p_a)
{
    float temp, sqrt;

    temp = 0;
    sqrt = p_a / 2;

    while (sqrt != temp)
    {
        temp = sqrt;

        sqrt = (p_a / temp + temp) / 2;
    }

    return sqrt;
}
