escribir('Introduzca un número para averiguar si es primo -> ');
n := 104729;
leer(n);
escribir('El número leido es: ');
escribir(n);
escribir('\n');
resultado := verdadero;
si (n <= 1) entonces
    resultado :=falso;
si_no 
    si (n = 2) entonces
        resultado := verdadero;
    si_no 
        si (n%2 = 0) entonces
            resultado :=falso;
        si_no 
            i:= 3;
            repetir
                si (n % i = 0) entonces
                        resultado :=falso;
                fin_si;
                i:+=2;
            hasta ((i>sqrt(n)) #o (resultado=falso));
            
        fin_si;
        
    fin_si;
fin_si;
escribir('El número ');
escribir(n);
si (resultado = verdadero) entonces
    escribir(' es primo\n');
si_no
    escribir(' no es primo.\n');
fin_si;
