a:=1;
b:=10;
t_n := uniforme(a,b);
t_n := t_n*1000000;
t_n := (t_n%(b-a+1))+a;
escribir('Se ha generado un número aleatorio entre ');
escribir(a);
escribir(' y ');
escribir(b);
escribir('\nIntente adivinarlo\n');
ad:=-1;
adivinado:=falso;
n_intentos:=0;
mientras (adivinado<>verdadero) hacer
    escribir('Introduzca un número ->');
    leer(ad);
    si (ad = t_n) entonces
        escribir('Felicidades, lo has adivinado\n');
        adivinado:=verdadero;
    si_no
        escribir('Número incorrecto\n');
        respuesta:= ((t_n<ad) ? 'El número a adividar es menor que el que ha introducido\n' : 'El número a adividar es mayor que el que ha introducido\n');
        escribir(respuesta);
    fin_si;
    n_intentos:+=1;
fin_mientras;
escribir('El número a adividar era ');
escribir(t_n);
escribir('\n');
escribir('Ha tardado ');
escribir(n_intentos);
escribir(' intentos\n');