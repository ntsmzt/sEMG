function [ point ] = segment( data )
%UNTITLED2 此处显示有关此函数的摘要
%   此处显示详细说明
%提取活动段，设定阈值
%信号之间小于20，类间之间大于100
%信号长度大于150
threshold=2e-4;

sorteddata=sort(abs(data),2);
index=find(mean(sorteddata(:,3:5),2)>threshold);
i=1;
point=[];
while i<length(index)
    startpoint=index(i);
    endpoint=startpoint;
    while index(i+1)-index(i)<=20
        endpoint=index(i+1);
        i=i+1;
        if i==length(index)
            break;
        end
    end
    if ~(endpoint-startpoint<=100)
        point=[point;[startpoint,endpoint]];
    end
    i=i+1;
end
end

