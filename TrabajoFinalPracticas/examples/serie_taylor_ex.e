!!Programa para calcular e^x usando la serie de Taylor
!!Variables iniciales
x := 0.0;
n := 20;  !! Número de términos de la serie
term := 1.0;
sum := 1.0;

!! Entrada del usuario
escribir('Introduce el valor de x para calcular e^x: ');
leer(x);

!! Calcular e^x usando la serie de Taylor
para i desde 1  hasta n paso 1 hacer
    term := term * (x / i);
    sum := sum + term;
fin_para;

escribir('La aproximación de e^');
escribir(x);
escribir(' usando ');
escribir(n);
escribir(' términos es: ');
escribir(sum);
escribir('\n');
