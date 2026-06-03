int factorial_iterative(int n) {
    
    int result = 1;

    // Funcion de iteracion con un for desde 1 hasta N...
    for (int i = 1; i <= n; i++) {
        result = result * i;
    }
    return result;
}