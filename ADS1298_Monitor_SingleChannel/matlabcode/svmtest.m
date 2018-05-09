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
%     data{i}(:,3)=[]; %ȥ��ͨ��3������
end

%     �����ȡ
    point=cell(gestureNum,1);
    for i=1:gestureNum
        point{i}=segment(data{i});
    end
    %     ������ȡ
    feature=cell(gestureNum,1);
    for i=1:gestureNum
        feature{i}=featureExtract(data{i},point{i});
    end

%������ left and right

traindata=[feature{1};feature{2}];
trainlabel=[ones(size(feature{1},1),1);-ones(size(feature{2},1),1)];
% Train the SVM  
model = svmtrain(traindata, trainlabel);  
