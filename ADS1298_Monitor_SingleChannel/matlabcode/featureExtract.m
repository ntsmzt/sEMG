function [ feature ] = featureExtract( data,point )
%UNTITLED 此处显示有关此函数的摘要
%   此处显示详细说明
m=size(point,1);  %手势实例个数
segmentNum=0;
n=10+segmentNum;  %特征种数
feature=zeros(m,n*size(data,2)); %多个通道

for i=1:m
    for j=1:size(data,2)
        feature(i,1+n*(j-1))=mean(abs(data(point(i,1):point(i,2),j)));  %MAV
        feature(i,2+n*(j-1))=sqrt(mean((data(point(i,1):point(i,2),j)).^2));  %RMS
        feature(i,3+n*(j-1))=sum((data(point(i,1):point(i,2),j)).^2)/(point(i,2)-point(i,1));  %VAR
        feature(i,4+n*(j-1))=sqrt(sum((data(point(i,1):point(i,2),j)-mean(data(point(i,1):point(i,2),j))).^2)/(point(i,2)-point(i,1)));  %SD
        feature(i,5+n*(j-1))=sum(abs(data((point(i,1)+1):point(i,2),j)-data(point(i,1):(point(i,2)-1),j)));  %waveform length        
%         feature(i,6+n*(j-1))=sum((1-sign(data((point(i,1)+1):point(i,2),j).*data(point(i,1):(point(i,2)-1),j)))/2);  %zero crossing
%         
%         slope1=data((point(i,1)+1):(point(i,2)-1),j)-data(point(i,1):(point(i,2)-2),j);
%         slope2=data((point(i,1)+2):point(i,2),j)-data((point(i,1)+1):(point(i,2)-1),j);
%         feature(i,7+n*(j-1))=sum((1-sign(slope1.*slope2))/2); %slope sign change
        

        %1-5阶自回归系数
        feature(i,6+n*(j-1))= mean(data(point(i,1):point(i,2)-1,j).* data((point(i,1)+1):point(i,2),j));
        feature(i,7+n*(j-1))= mean(data(point(i,1):point(i,2)-2,j).* data((point(i,1)+2):point(i,2),j));
        feature(i,8+n*(j-1))= mean(data(point(i,1):point(i,2)-3,j).* data((point(i,1)+3):point(i,2),j));
        feature(i,9+n*(j-1))= mean(data(point(i,1):point(i,2)-4,j).* data((point(i,1)+4):point(i,2),j));
        feature(i,10+n*(j-1))=mean(data(point(i,1):point(i,2)-5,j).* data((point(i,1)+5):point(i,2),j));
        
        
        %功率谱平均频率
        segmentpoint=zeros(segmentNum+1,1);
        segmentpoint(1)=point(i,1);
        for k=1:segmentNum
            segmentpoint(k+1)=point(i,1)+floor((point(i,2)-point(i,1)+1)/segmentNum)*k;
        end
        for k=1:segmentNum
            feature(i,10+k+n*(j-1))=powerspectrum(data,segmentpoint(k),segmentpoint(k+1));
        end
    end   
end

end

function [AveragePower]=powerspectrum(data,startpoint,endpoint)
    delta=2.0;
    frequencySupremum=100.0;

    fp=0.0;
    p=0.0;
    for j=1:(frequencySupremum/delta)    
        Rep=0.0;
        Imp=0.0;
        for i=startpoint:endpoint-1
            Rep=Rep+data(i)*cos((i-startpoint)*(j+1)*delta);
            Imp=Imp-data(i)*sin((i-startpoint)*(j+1)*delta);
        end
        p=p+(Rep*Rep+Imp*Imp)/(endpoint-startpoint)*delta;
        fp=fp+(Rep*Rep+Imp*Imp)/(endpoint-startpoint)*(j+1)*delta*delta;
    end
    AveragePower=fp/p;
end

