function [ y ] = recognizor( theta1,theta2,X )
%UNTITLED3 �˴���ʾ�йش˺�����ժҪ
%   �˴���ʾ��ϸ˵��

m=size(X,1);
bias=ones(m,1);
a1=[bias,X]';

z2=theta1*a1;
a2=sigmoid(z2);
a2=[bias';a2];
z3=theta2*a2;
a3=sigmoid(z3);

y=zeros(length(a3),1);
index=find(a3==max(a3));
% if a3(index(1))>=0.5
%    y(index(1))=1; 
% end
y(index(1))=1; 
end

