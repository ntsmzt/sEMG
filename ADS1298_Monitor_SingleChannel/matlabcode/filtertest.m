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
    Fs = 2000;       % 采样频率
    N = 2^nextpow2(L); %采样点数，采样点数越大，分辨的频率越精确，N>=L，超出的部分信号补为0
    
    yraw=cell(3,1);
    Araw=cell(3,1);
    Praw=cell(3,1);
    f = Fs/N*(0:1:N-1); %频率
    for i=1:3
        yraw{i} = fft(rawdata(i+1,:),N)/N*2;   %除以N乘以2才是真实幅值，N越大，幅值精度越高
        Araw{i}=abs(yraw{i});  %幅值
        Praw{i}=angle(yraw{i});  %相值
    end
    
    for i=1:3
        figure('NumberTitle', 'off', 'Name', ['raw-','channel',num2str(i)]);
        subplot(2,1,1);
        plot(f(1:N/2),Araw{i}(1:N/2));   %函数fft返回值的数据结构具有对称性,因此我们只取前一半
        title('幅值频谱')
        xlabel('频率(Hz)')
        ylabel('幅值')
        
        subplot(2,1,2);
        plot(f(1:N/2),Praw{i}(1:N/2));
        title('相位谱频')
        xlabel('频率(Hz)')
        ylabel('相位')
    end
    
    yfiltered=cell(3,1);
    Afiltered=cell(3,1);
    Pfiltered=cell(3,1);
    f = Fs/N*(0:1:N-1); %频率
    for i=1:3
        yfiltered{i} = fft(filtereddata(i+1,:),N)/N*2;   %除以N乘以2才是真实幅值，N越大，幅值精度越高
        Afiltered{i}=abs(yfiltered{i});  %幅值
        Pfiltered{i}=angle(yfiltered{i});  %相值
    end
    
    for i=1:3
        figure('NumberTitle', 'off', 'Name', ['filterd-','channel',num2str(i)]);
        subplot(2,1,1);
        plot(f(1:N/2),Afiltered{i}(1:N/2));   %函数fft返回值的数据结构具有对称性,因此我们只取前一半
        title('幅值频谱')
        xlabel('频率(Hz)')
        ylabel('幅值')
        
        subplot(2,1,2);
        plot(f(1:N/2),Pfiltered{i}(1:N/2));
        title('相位谱频')
        xlabel('频率(Hz)')
        ylabel('相位')
    end
end

%% *******************************wavelet************************、
if wavelet
    for i=1:3
        figure('NumberTitle', 'off', 'Name', ['channel',num2str(i)]);
        %使用小波函数'db6'对信号进行3层分解    
        [c,l] = wavedec((filtereddata(:,i+1))',3,'db6');    
        %估计尺度1的噪声标准差    
        sigma = wnoisest(c,l,1);    
        alpha = 2;    
        %获取消噪过程中的阈值    
        thr = wbmpen(c,l,sigma,alpha);    
        keepapp = 1;    
        %对信号进行消噪    
        xd = wdencmp('gbl',c,l,'db6',3,thr,'s',keepapp);    
        subplot(3,1,1);    
        plot(rawdata(:,1)/250,rawdata(:,i+1));    
        title('原始信号');  
        xlim([0,12]);
        subplot(3,1,2);   
        plot(filtereddata(:,1)/250,filtereddata(:,i+1));    
        title('filtered信号');  
        xlim([0,12]);
        subplot(3,1,3);
        plot(rawdata(:,1)/250,xd);    
        title('filtered and wavlet消噪后的信号');
        xlim([0,12]);
    end
end