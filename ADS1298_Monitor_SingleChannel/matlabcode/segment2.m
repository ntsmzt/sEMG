function [ point ] = segment2( data )
%UNTITLED �˴���ʾ�йش˺�����ժҪ
%   �˴���ʾ��ϸ˵��

threshold=1.8e-3;
index=find(max(abs(data),[],2)>threshold);
[max_value,max_p]=max(abs(data),[],2);
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
    if ~(endpoint-startpoint<=150)
        point=[point;[startpoint,endpoint]];
    end
    i=i+1;
end

end

