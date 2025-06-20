!! Número de términos de la serie de Fibonacci a calcular
escribir('Indique el número de términos de la sucesión de Fibonacci que se desea mostrar ->');
n := 10;
leer(n);
n:-=1;
!! Inicializar los dos primeros términos
a := 0;
b := 1;

!! Imprimir los dos primeros términos
escribir(a);
escribir('\n');
escribir(b);
escribir('\n');



!! Calcular los siguientes términos de la serie de Fibonacci
i:=1;
mientras (i<n) hacer
    !! temp será el siguiente término de la serie
    temp := a + b;
    
    !! Imprimir el siguiente término
    escribir(temp);
    escribir('\n');
    
    !! Actualizar a y b usando el operador ternario
    !! a se convierte en b
    !! b se convierte en temp
    a := b;
    b := temp;
    i:+=1;
fin_mientras;
