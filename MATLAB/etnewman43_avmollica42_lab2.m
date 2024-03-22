% ENGR1120-020 Tennessee Technological Univ.
% Alex Mollica and Ethan Newman
% Lab 2 - Chemistry: The Ideal Gas Law

clear variables
clc 
% Constants

A=100; %cm^2
P=300;
T=325;
M=28.97;
R=8.314;
x=15;     % cm
% Find Value F

F=(A*(1/10000))*(P*(1000))
% Find Values V,n,m

V=(x*(1/100))*(A*(1/10000)) % m^3
n=(P*(1000)*V)/(R*T)
m=n*(M*(1/1000))
% Find if x=10

'Problem 2'

x=10
V2=(x*(1/100))*(A*(1/10000))
n2=(P*(1000)*V)/(R*T)
m2=n*(M*(1/1000))
P2=(n2*R*T)/(V2)
F2=P2*(A*(1/10000))