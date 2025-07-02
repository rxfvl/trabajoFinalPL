print('Inserte el cuantos digitos de la sucesion quiere obtener\n');

read(n);

sigiente := 1;
anterior := 0;
actual := 0;
i := 0;

for i from 1 to n do
actual := sigiente + anterior;
print(actual);
print(' ');
anterior := sigiente;
sigiente := actual;
end_for

print('\nFinal del programa\n');
