!!Área de una función distribución normal de media 0 y desviación típica 1
escribir('Programa que calcula la integral definida de una distribución normal con media 0 y desviación típica 1 en el rango [a,b]\n');

limite_inf := 0;
limite_sup := 0;
repetir
    escribir('Introduzca el valor de a ->');
    leer(limite_inf);

    escribir('\n');

    escribir('Introduzca el valor de b ->');
    leer(limite_sup);
    escribir('\n');
    si (limite_inf >= limite_sup) entonces
        escribir('ERROR, el valor de a debe ser menor que el de b\n');
    fin_si;
hasta (limite_inf < limite_sup);

n := 0;
repetir
   escribir('introduzca el número de valores aleatorios con el que se quiere calcular la media(n) ->');

    leer(n);

    escribir('\n');
    si (n <= 0) entonces
        escribir('ERROR, el valor de n debe ser mayor que 0\n');
    fin_si;
hasta (n > 0);
suma:=0;


f:= 1/(sqrt(2*pi));
para i desde 1 hasta n hacer
    r:=uniforme(limite_inf,limite_sup);
    suma:+= f*e**(-(r**2)/2);
fin_para;
superficie := limite_sup-limite_inf;
suma :/= n;
superficie :*= suma;
escribir('El área de la función es: ');
escribir(superficie);
escribir('\n');
