%Ethan Newman - Question 2 - Dr. Adenson

clear variables;clc

A = [0.8, 0.5, 0.1; 0.15, 0.3, 0.2; 0.05, 0.2, 0.7];
B = [0.4*1000; 0.25*1000; 0.35*1000];

FR = A\B 
F1 = FR(1)
F2 = FR(2)
F3 = FR(3)

disp('Flowrate 1 =')
disp(F1)
disp('Flowrate 2 =')
disp(F2)
disp('Flowrate 3 =')
disp(F3)
