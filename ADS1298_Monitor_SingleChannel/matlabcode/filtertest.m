clear
close all
FFT=false;
wavelet=true;
%% *******************************data*************************
readpath='..\data\';
filename='filtertest1';
ext={'.rawdat','.filtereddat'};
rawdata=textread([readpath,filename,ext{1}]);
filtereddata=textread([readpath,filename,ext{2}]);
L=size(rawdata,1);
figure
subplot(2,1,1);
hold on
plot(rawdata(:,1)/250,rawdata(:,2),'r');
plot(rawdata(:,1)/250,rawdata(:,3),'b');
plot(rawdata(:,1)/250,rawdata(:,4),'k');
xlabel('time(s)');
ylabel('Voltage(V)');
legend('channel 1','channel 2','channel 3');
title('rawdata');
xlim([0,12]);
subplot(2,1,2);
hold on
plot(filtereddata(:,1)/250,filtereddata(:,2),'r');
plot(filtereddata(:,1)/250,filtereddata(:,3),'b');
plot(filtereddata(:,1)/250,filtereddata(:,4),'k');
xlabel('time(s)');
ylabel('Voltage(V)');
legend('channel 1','channel 2','channel 3');
title('filtereddata');
xlim([0,12]);

%% **********************FFT*****************************************
if FFT
    Fs = 2000;       % ����Ƶ��
    N = 2^nextpow2(L); %������������������Խ�󣬷ֱ��Ƶ��Խ��ȷ��N>=L�������Ĳ����źŲ�Ϊ0
    
    yraw=cell(3,1);
    Araw=cell(3,1);
    Praw=cell(3,1);
    f = Fs/N*(0:1:N-1); %Ƶ��
    for i=1:3
        yraw{i} = fft(rawdata(i+1,:),N)/N*2;   %����N����2������ʵ��ֵ��NԽ�󣬷�ֵ����Խ��
        Araw{i}=abs(yraw{i});  %��ֵ
        Praw{i}=angle(yraw{i});  %��ֵ
    end
    
    for i=1:3
        figure('NumberTitle', 'off', 'Name', ['raw-','channel',num2str(i)]);
        subplot(2,1,1);
        plot(f(1:N/2),Araw{i}(1:N/2));   %����fft����ֵ�����ݽṹ���жԳ���,�������ֻȡǰһ��
        title('��ֵƵ��')
        xlabel('Ƶ��(Hz)')
        ylabel('��ֵ')
        
        subplot(2,1,2);
        plot(f(1:N/2),Praw{i}(1:N/2));
        title('��λ��Ƶ')
        xlabel('Ƶ��(Hz)')
        ylabel('��λ')
    end
    
    yfiltered=cell(3,1);
    Afiltered=cell(3,1);
    Pfiltered=cell(3,1);
    f = Fs/N*(0:1:N-1); %Ƶ��
    for i=1:3
        yfiltered{i} = fft(filtereddata(i+1,:),N)/N*2;   %����N����2������ʵ��ֵ��NԽ�󣬷�ֵ����Խ��
        Afiltered{i}=abs(yfiltered{i});  %��ֵ
        Pfiltered{i}=angle(yfiltered{i});  %��ֵ
    end
    
    for i=1:3
        figure('NumberTitle', 'off', 'Name', ['filterd-','channel',num2str(i)]);
        subplot(2,1,1);
        plot(f(1:N/2),Afiltered{i}(1:N/2));   %����fft����ֵ�����ݽṹ���жԳ���,�������ֻȡǰһ��
        title('��ֵƵ��')
        xlabel('Ƶ��(Hz)')
        ylabel('��ֵ')
        
        subplot(2,1,2);
        plot(f(1:N/2),Pfiltered{i}(1:N/2));
        title('��λ��Ƶ')
        xlabel('Ƶ��(Hz)')
        ylabel('��λ')
    end
end

%% *******************************wavelet************************��
if wavelet
    for i=1:3
        figure('NumberTitle', 'off', 'Name', ['channel',num2str(i)]);
        %ʹ��С������'db6'���źŽ���3��ֽ�    
        [c,l] = wavedec((filtereddata(:,i+1))',3,'db6');    
        %���Ƴ߶�1��������׼��    
        sigma = wnoisest(c,l,1);    
        alpha = 2;    
        %��ȡ��������е���ֵ    
        thr = wbmpen(c,l,sigma,alpha);    
        keepapp = 1;    
        %���źŽ�������    
        xd = wdencmp('gbl',c,l,'db6',3,thr,'s',keepapp);    
        subplot(3,1,1);    
        plot(rawdata(:,1)/250,rawdata(:,i+1));    
        title('ԭʼ�ź�');  
        xlim([0,12]);
        subplot(3,1,2);   
        plot(filtereddata(:,1)/250,filtereddata(:,i+1));    
        title('filtered�ź�');  
        xlim([0,12]);
        subplot(3,1,3);
        plot(rawdata(:,1)/250,xd);    
        title('filtered and wavlet�������ź�');
        xlim([0,12]);
    end
end