clear
close all
%% ******************************initial****************************
readpath='..\data\';
filenames={'left-5','right-5','fist-5','spread-5','yeah-5'};
ext='.filtereddat';
gestureNum=length(filenames);
data=cell(gestureNum,1);
counter=cell(gestureNum,1);
for i=1:gestureNum
    data{i}=textread([readpath,filenames{i},ext]);
    counter{i}=data{i}(:,1);
    data{i}(:,1)=[];
    data{i}(:,5:7)=[];
    data{i}(:,end)=[];
%     data{i}(:,3)=[]; %去除通道3的数据
end
% rawdata=textread([readpath,filenames{1},'.rawdat']);
% figure('NumberTitle', 'off', 'Name', filenames{1});
% subplot(2,1,1)
% plot(rawdata(:,2),'r');
% title('rawdata')
% subplot(2,1,2)
% plot(data{1}(:,1),'r')
% title('filtered data')
% n=size(data{1},2);
% for i=1:gestureNum
%    figure('NumberTitle', 'off', 'Name', filenames{i});
%    for j=1:n
%        subplot(n,1,j)
%        plot(data{i}(:,j),'r');
%        title(['channel ',num2str(j)])
%    end
% end

%% ***************************training*************************
if 1
%     活动段提取
    point=cell(gestureNum,1);
    for i=1:gestureNum
        point{i}=segment(data{i});
    end
%     
    n=size(data{1},2);
    for i=1:gestureNum
        
        for j=1:n
            figure('NumberTitle', 'off', 'Name', filenames{i});
%             subplot(n,1,j)
            hold on
            plot(data{i}(:,j),'r');
            plot(point{i}(:,1),0,'bo');
            plot(point{i}(:,2),0,'bx');
%             legend('filtered data','startpoint','endpoint');
            title(['channel ',num2str(j)]);       
            xlim([100,inf]);
        end
    end

%     threshold=2e-4;
%     
%     X=[];
%     y=[];
%     index_test=cell(gestureNum,1);
%     for i=1:gestureNum
%         point=[];
%         index_test{i}=zeros(size(data{i},1),1);
%         for j=1:size(data{i},1)
%             if  abs(mean(data{i}(j,:)))>threshold
%                 point=[point;j];
%             else
%                 continue;
%             end
%             if length(point)>=2
%                 if point(end)-point(end-1)>20
%                     point(1:end-1)=[];
%                 else
%                     if point(end)-point(1)>150
%                         X=[X;featureExtract(data{i},[point(1),point(end)])];
% %                         y= recognizor( theta1,theta2,X );              
% %                         index_test{i}(j)=find(y==1);
%                         yy=zeros(gestureNum,1);
%                         yy(i,:)=1;
%                         y=[y,yy];
%                     end
%                 end
%             end
%         end
%     end
    
    
    
%     特征提取
    feature=cell(gestureNum,1);
    for i=1:gestureNum
        feature{i}=featureExtract(data{i},point{i});
    end
    
%     for i=1:21
%         figure
%         hold on
%         for j=1:gestureNum
%             plot(feature{j}(:,i));
%         end
%         legend(filenames{1},filenames{2},filenames{3},filenames{4},filenames{5});
%     end
%     
    
    
    %ANN
    L=3; %3层
    sl=[50,30,5]; %每一层的神经元数
    X=[];
    y=[];
    for i=1:gestureNum
        X=[X;feature{i}];
        yy=zeros(gestureNum,size(feature{i},1));
        yy(i,:)=1;
        y=[y,yy];
    end
    [ theta1,theta2 ] = nerualnetwork(X,y,sl);
end

%% *********************************recognition****************
if 0
    load theta6.mat
    threshold=2e-4;
    
    index_ref=cell(gestureNum,1);
    for i=1:gestureNum
        index_ref{i}=segment(data{i});
    end
    
    point=[];
    index_test=cell(gestureNum,1);
    for i=1:gestureNum
        index_test{i}=zeros(size(data{i},1),1);
        for j=1:size(data{i},1)
            if  abs(mean(data{i}(j,:)))>threshold
                point=[point;j];
            else
                continue;
            end
            if length(point)>=2
                if point(end)-point(end-1)>20
                    point(1:end-1)=[];
                else
                    if point(end)-point(1)>150
                        X=featureExtract(data{i},[point(1),point(end)]);
                        y= recognizor( theta1,theta2,X );              
                        index_test{i}(j)=find(y==1);
                    end
                end
            end
        end
    end
    
    for i=1:gestureNum
        display(filenames{i});
       c=unique(index_test{i});
       for j=1:length(c)
           num=length(find(index_test{i}==c(j)));
           display([num2str(c(j)),' = ',num2str(num)]);
       end
    end
end   
    
    
