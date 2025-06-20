!! Programa para calcular la raíz cuadrada de un número usando el Método de Newton-Raphson

!! Variables iniciales
number := 0;
guess := 1.0;
tolerance := 0.00001;
difference := 1.0;

!! Entrada del usuario
escribir('Introduce el número para calcular su raíz cuadrada: ');
leer(number);

!! Algoritmo de Newton-Raphson
mientras (difference > tolerance) hacer
    guess_new := (guess + number / guess) / 2;
    difference := abs(guess_new - guess);
    guess := guess_new;
fin_mientras;

escribir('La raíz cuadrada aproximada de ');
escribir(number);
escribir(' es: ');
escribir(guess);
escribir('\n');