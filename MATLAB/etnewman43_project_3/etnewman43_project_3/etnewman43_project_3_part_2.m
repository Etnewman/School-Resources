%Ethan Newman - Project 3 Part 2
%Tristan Hill - Tennessee Technological University
%10 November 2017
clear variables;clc
i=1;
Xdat=zeros(1,24);
Ydat=zeros(1,24);
fid=fopen('hw3_task2.txt','r');
K=fscanf(fid,'%f',4)
while i<=24;
    Xdat(i)=fscanf(fid,'%f',1);
    Ydat(i)=fscanf(fid,'%f',1);
    dia(i)=fscanf(fid,'%f',1);
    square(i)=fscanf(fid,'%f',1);
    i=i+1;
end
fclose(fid);
title('Task 2')
xlabel('X Data')
ylabel('Y Data')
deg_clock=[60 30 0 330 300 270 240 210 180 150 120 90];
i=1;
a=zeros(1,24);
while i<=24
    a=Ydat(i);
    Ydat(i)=deg_clock(a);
    i=i+1;
end
x=zeros(1,24);
y=zeros(1,24);
i=1;
%I eventually figured out how to put it in a loop
while i<=24
    x(i)=(Xdat(i)*cosd(Ydat(i)));
    y(i)=(Xdat(i)*sind(Ydat(i)));
    i=i+1;
end
X=10;
Fx=zeros(1,24);
Y=89.9;
Fy=zeros(1,24);
i=1;
while i<=24
    X=X+x(i);
    Y=Y+y(i);
    Fx(i)=X;
    Fy(i)=Y;
    i=i+1;
end
hold on;grid on
plot(Fx(24),Fy(24),'pg','markersize',15,'markerfacecolor','g','markeredgecolor','r')
plot([K(1) Fx(1)], [K(2) Fy(1)],'b-')
plot([K(1) Fx(1)], [K(2) Fy(1)],'b.','markersize',35)
plot([K(1) Fx(1)], [K(2) Fy(1)],'g.','markersize',30)
plot(Fx,Fy,'b-')
xlim([0 100])
ylim([0 100])


i=1;
while i<=24
    if square(i)==1
    plot(Fx(i),Fy(i),'ms','markersize',20,'markerfacecolor','m','markeredgecolor','b')
    end
    hold on
    i=i+1;
end

i=1;
while i<=24
    if dia(i)==1
    plot(Fx(i),Fy(i),'cd','markersize',10,'markerfacecolor','c','markeredgecolor','r')
    end
    hold on
    i=i+1;
 end









