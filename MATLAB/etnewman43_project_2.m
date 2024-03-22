%Ethan Newman - Tennessee Technological University
%Project 2 - Using 1D Arrays in MATLAB

clear variables;clc

Tri_x=input('Enter 3 numbers in an array for vertices in X')
Tri_y=input('Enter 3 numbers in an array for vertices in Y')
figure(1)
hold on
axis([-1,6,-1,5])
plot(Tri_x,Tri_y)
Tri_xline=[Tri_x(1),Tri_x(3)];
Tri_yline=[Tri_y(1),Tri_y(3)];
plot(Tri_xline,Tri_yline);
tside_a=(sqrt((Tri_x(2)-Tri_x(1))+(Tri_y(2)-Tri_y(1))))^2;
tside_b=((sqrt((Tri_x(3)-Tri_x(2))+(Tri_y(3)-Tri_y(2))))^2);
tside_c=(sqrt((Tri_x(3)-Tri_x(1))+(Tri_y(3)-Tri_y(1))))^2;
fprintf('Side a of the Triangle is %6.1f\n',tside_a)
fprintf('Side b of the Triangle is %6.1f\n',tside_b)
fprintf('Side c of the Triangle is %6.1f\n',tside_c)
tangle_a= acos((((tside_b)^2)+((tside_c)^2)-((tside_a)^2)))/(2*(tside_b*tside_c));
fprintf('The first angle is degree raidians %6.3f\n',tangle_a)
tangle_b= acos((((tside_c)^2)+((tside_a)^2)-((tside_b)^2)))/(2*(tside_c*tside_a));
fprintf('The second angle is degree raidians %6.3f\n',tangle_b)
tangle_c= acos((((tside_a)^2)+((tside_b)^2)-((tside_c)^2)))/(2*(tside_a*tside_b));
fprintf('The third angle is degree raidians %6.3f\n',tangle_c)





