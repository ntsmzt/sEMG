function [ theta1,theta2 ] = nerualnetwork(X,y,sl)   %X 一行是一个实例
%UNTITLED2 此处显示有关此函数的摘要
%   此处显示详细说明
initial_theta1=randInitializeWeights(sl(1),sl(2));
initial_theta2=randInitializeWeights(sl(2),sl(3));
initial_nn_params=[initial_theta1(:);initial_theta2(:)];

options = optimset('GradObj','on','MaxIter', 400);

%  You should also try different values of lambda
lambda =0.2;

% Now, costFunction is a function that takes in only one argument (the
% neural network parameters)
[nn_params, fval,exitflag,output] = fminunc(@(t)(costfunction(X,y,t,sl,lambda)),initial_nn_params, options);
fval
exitflag
output
% Obtain Theta1 and Theta2 back from nn_params
theta1=reshape(nn_params(1:sl(2) * (sl(1) + 1)), ...
                 sl(2), (sl(1) + 1));
theta2=reshape(nn_params(1+sl(2) * (sl(1) + 1):end), ...
 sl(3), (sl(2) + 1));

end

function [J, grad]=costfunction(X,y,t,sl,lambda)  %t:参数

theta1=reshape(t(1:sl(2) * (sl(1) + 1)), ...
                 sl(2), (sl(1) + 1));
theta2=reshape(t(1+sl(2) * (sl(1) + 1):end), ...
 sl(3), (sl(2) + 1));

m=size(X,1);
bias=ones(m,1);
a1=[bias,X]';

z2=theta1*a1;
a2=sigmoid(z2);
a2=[bias';a2];
z3=theta2*a2;
a3=sigmoid(z3);

J=-1/m*sum(sum(y.*log(a3)+(1-y).*log(1-a3)))+lambda/(2*m)*(sum(sum(theta1(:,2:end).^2))+sum(sum(theta2(:,2:end).^2)));

delta3=a3-y;
delta2=theta2'*delta3.*sigmoidGradient(a2);
delta2=delta2(2:end,:);

Theta2_grad=(delta3*a2')/m;
Theta2_grad(:,2:end)=Theta2_grad(:,2:end)+lambda/m*theta2(:,2:end);
Theta1_grad=(delta2*a1')/m;
Theta1_grad(:,2:end)=Theta1_grad(:,2:end)+lambda/m*theta1(:,2:end);

grad = [Theta1_grad(:) ; Theta2_grad(:)];
end

function g = sigmoid(z)
%SIGMOID Compute sigmoid functoon
%   J = SIGMOID(z) computes the sigmoid of z.

g = 1.0 ./ (1.0 + exp(-z));
end

function g = sigmoidGradient(z)

g=z.*(1-z);


end

function W = randInitializeWeights(L_in, L_out)
%RANDINITIALIZEWEIGHTS Randomly initialize the weights of a layer with L_in
%incoming connections and L_out outgoing connections
%   W = RANDINITIALIZEWEIGHTS(L_in, L_out) randomly initializes the weights 
%   of a layer with L_in incoming connections and L_out outgoing 
%   connections. 
%
%   Note that W should be set to a matrix of size(L_out, 1 + L_in) as
%   the first column of W handles the "bias" terms
%

% You need to return the following variables correctly 
W = zeros(L_out, 1 + L_in);

epsilon_init = 0.12;
W=2*epsilon_init*rand(L_out,1+L_in)-epsilon_init;


end

