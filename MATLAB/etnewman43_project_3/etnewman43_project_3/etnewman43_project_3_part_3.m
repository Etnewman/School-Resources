%Ethan Newman - Project 3 Part 3
%Tristan Hill - Tennessee Technological University
%10 November 2017
clear variables;clc
i=1;
Xdat=zeros(1,17);
Ydat=zeros(1,17);
fid=fopen('hw3_task3.txt','r');
K=fscanf(fid,'%f',4)
while i<=17;
    Xdat(i)=fscanf(fid,'%f',1);
    Ydat(i)=fscanf(fid,'%f',1);
    dia(i)=fscanf(fid,'%f',1);
    square(i)=fscanf(fid,'%f',1);
    i=i+1;
end
fclose(fid);
title('Task 3')
xlabel('X Data')
ylabel('Y Data')
deg_clock=[60 30 0 330 300 270 240 210 180 150 120 90];
i=1;
a=zeros(1,17);
while i<=17
    a=Ydat(i);
    Ydat(i)=deg_clock(a);
    i=i+1;
end
x=zeros(1,17);
y=zeros(1,17);
i=1;
while i<=17
    x(i)=(Xdat(i)*cosd(Ydat(i)));
    y(i)=(Xdat(i)*sind(Ydat(i)));
    i=i+1;
end
X=9.9;
Fx=zeros(1,17);
Y=10.3;
Fy=zeros(1,17);
i=1;
while i<=17
    X=X+x(i);
    Y=Y+y(i);
    Fx(i)=X;
    Fy(i)=Y;
    i=i+1;
end
hold on;grid on
plot(Fx(17),Fy(17),'pg','markersize',15,'markerfacecolor','g','markeredgecolor','r')
plot([K(1) Fx(1)], [K(2) Fy(1)],'b-')
plot(K(1),K(2),'b.','markersize',35)
plot(K(1),K(2),'g.','markersize',30)
plot(Fx,Fy,'b.-','markersize',20)
plot(Fx,Fy,'g.','markersize',15)
xlim([0 100])
ylim([0 100])
hold on
plot(Fx(1),Fy(1),'cd','markersize',7,'markerfacecolor','c','markeredgecolor','r')
plot(Fx(2),Fy(2),'cd','markersize',5,'markerfacecolor','c','markeredgecolor','r')
plot(Fx(8),Fy(8),'cd','markersize',16,'markerfacecolor','c','markeredgecolor','r')
plot(Fx(11),Fy(11),'cd','markersize',25,'markerfacecolor','c','markeredgecolor','r')
plot(Fx(15),Fy(15),'cd','markersize',13,'markerfacecolor','c','markeredgecolor','r')
plot(Fx(3),Fy(3),'ms','markersize',45,'markerfacecolor','m','markeredgecolor','b')
plot(Fx(4),Fy(4),'ms','markersize',10,'markerfacecolor','m','markeredgecolor','b')
plot(Fx(6),Fy(6),'ms','markersize',30,'markerfacecolor','m','markeredgecolor','b')
plot(Fx(10),Fy(10),'ms','markersize',11,'markerfacecolor','m','markeredgecolor','b')
plot(Fx(13),Fy(13),'ms','markersize',30,'markerfacecolor','m','markeredgecolor','b')
plot(Fx(16),Fy(16),'ms','markersize',20,'markerfacecolor','m','markeredgecolor','b')
plot(Fx(6),Fy(6),'cd','markersize',10,'markerfacecolor','c','markeredgecolor','r')
plot(Fx(4),Fy(4),'cd','markersize',5,'markerfacecolor','c','markeredgecolor','r')
plot(Fx(13),Fy(13),'cd','markersize',15,'markerfacecolor','c','markeredgecolor','r')