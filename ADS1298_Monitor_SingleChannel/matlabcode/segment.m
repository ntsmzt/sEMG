function [ point ] = segment( data )
%UNTITLED2 �˴���ʾ�йش˺�����ժҪ
%   �˴���ʾ��ϸ˵��
%��ȡ��Σ��趨��ֵ
%�ź�֮��С��20�����֮�����100
%�źų��ȴ���150
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

