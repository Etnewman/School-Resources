%Ethan Newman - Question 1 - Dr. Adenson
clear all;clear variables;clc

R=8.314;
v=1;
T=0:20:500;
Tc=-118.6;
Pc=732;
Tr=T./Tc;
a=.42748*(R.^2*Tc.^2/Pc)*1./(Tr.^.5);
b=.08664.*(R.*Tc./Pc);
P_Ideal=(R.*T)./v;
P_vdw=(R.*T)./(v-b)-(a/v);
P_RK=(R.*T)./(v-b)-(a/(v.*(v+b)));

plot(T, P_Ideal, P_vdw, P_RK)
xlabel('Temperature')
ylabel('Pressure')


