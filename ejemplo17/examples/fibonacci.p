print('Inserte el cuantos digitos de la sucesion quiere obtener');

read(n);

sigiente := 1;
anterior := 0;
actual := 0;
i := 0;

for i from 1 to n do
actual := sigiente + anterior;
print(actual);
anterior := sigiente;
sigiente := actual;
end_for

print('Final del programa');
