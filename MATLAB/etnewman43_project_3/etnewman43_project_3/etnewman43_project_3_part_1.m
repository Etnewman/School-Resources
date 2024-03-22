%Ethan Newman - Project 3 Part 1
%Tristan Hill - Tennessee Technological University
%10 November 2017

clear variables;clc
i=1;
Xdat=zeros(1,6);
Ydat=zeros(1,6);
fid=fopen('hw3_task1.txt','r');
Xdat1=fscanf(fid,'%f',1);
Ydat1=fscanf(fid,'%f',1);
while i<=6
    Xdat(i)=fscanf(fid,'%f',1);
    Ydat(i)=fscanf(fid,'%f',1);
    i=i+1;
end
fclose(fid)
title('Task 1')
xlabel('X Data')
ylabel('Y Data')
deg_clock=[60 30 0 330 300 270 240 210 180 150 120 90];
i=1;
a=zeros(1,6);
while i<=6
    a=Ydat(i);
    Ydat(i)=deg_clock(a);
    i=i+1;
end

hold on;grid on
x=(Xdat(1)*cosd(Ydat(1)))+Xdat1;
y=(Xdat(1)*sind(Ydat(1)))+Ydat1;
x2=(Xdat(2)*cosd(Ydat(2)))+x;
y2=(Xdat(2)*sind(Ydat(2)))+y;
x3=(Xdat(3)*cosd(Ydat(3)))+x2;
y3=(Xdat(3)*sind(Ydat(3)))+y2;
x4=(Xdat(4)*cosd(Ydat(4)))+x3;
y4=(Xdat(4)*sind(Ydat(4)))+y3;
x5=(Xdat(5)*cosd(Ydat(5)))+x4;
y5=(Xdat(5)*sind(Ydat(5)))+y4;
x6=(Xdat(6)*cosd(Ydat(6)))+x5;
y6=(Xdat(6)*sind(Ydat(6)))+y5;


plot([Xdat1 x], [Ydat1 y],'g.-','markersize',10)
plot([x x2], [y y2],'g.-','markersize',10)
plot([x2 x3], [y2 y3],'g.-','markersize',10)
plot([x3 x4], [y3 y4],'g.-','markersize',10)
plot([x4 x5], [y4 y5],'g.-','markersize',10)
plot([x5 x6], [y5 y6],'g.-','markersize',10)
plot([Xdat1 x], [Ydat1 y],'g.-','markersize',10)
plot([Xdat1 x], [Ydat1 y],'b')
plot([x x2], [y y2],'b')
plot([x2 x3], [y2 y3],'b')
plot([x3 x4], [y3 y4],'b')
plot([x4 x5], [y4 y5],'b')
plot([x5 x6], [y5 y6],'b')
plot(Xdat1,Ydat1,'.b','markersize',35)
plot(Xdat1,Ydat1,'.g','markersize',30)
plot(x6,y6,'pg','markersize',15,'markerfacecolor','g','markeredgecolor','r')
xlim([0 100])
ylim([0 100])

