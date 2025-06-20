!! Programa para ajustar un regresor lineal de grado 2 a un punto usando gradiente descendente
escribir('Programa que ajusta un regresor lineal de grado 2 a un punto (x,y)\nusando el método del gradiente descendente.\n\n');
!! Definición de constantes y variables
LEARNING_RATE := 0.001;
EPOCHS := 1000;

!! Inicialización de los coeficientes del polinomio
a := 1;
b := 1;
c := 1;

!! Entrada del usuario
escribir('Introduce el valor de x: ');
leer(x);
escribir('Introduce el valor de y: ');
leer(y);

escribir('Error inicial: ');
escribir(abs((a * x**2 + b * x + c)-y));
escribir('\n');
!! Algoritmo de Gradiente Descendente
para epoch desde 1 hasta EPOCHS  hacer
    !! Calcular la predicción y el error
    y_pred := a * x**2 + b * x + c;
    error := y_pred - y;

    !! Calcular los gradientes
    gradient_a := error * x**2;
    gradient_b := error * x;
    gradient_c := error;
    
    !! Actualizar los coeficientes
    a := a - LEARNING_RATE * gradient_a;
    b := b - LEARNING_RATE * gradient_b;
    c := c - LEARNING_RATE * gradient_c;
fin_para;

escribir('Coeficientes ajustados:\n');
escribir('a = ');
escribir(a);
escribir('\n');
escribir('b = ');
escribir(b);
escribir('\n');
escribir('c = ');
escribir(c);
escribir('\n');
escribir('Error final: ');
escribir(abs(error));
escribir('\n');