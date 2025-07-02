print ('Inserte un numero ');
read(numero);

i := 2;
no_primo := false;

while ((i<numero) and (no_primo = false)) do
    if ((numero mod i) = 0) then
        no_primo := true;
        print ('El numero no es primo\n');
    end_if;
    i := i+1;
end_while

if (no_primo = false) then
    print ('El numero es primo\n');
end_if;
