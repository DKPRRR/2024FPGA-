% 设置串口参数
serialPort = 'COM7'; % 根据实际情况修改串口号
baudRate = 921600; % 根据实际情况修改波特率

% 创建串口对象
s = serial(serialPort, 'BaudRate', baudRate, 'DataBits', 8, 'StopBits', 1, 'Parity', 'none', 'FlowControl', 'none');

% 打开串口
fopen(s);

% 预分配数据存储
numSamples = 1022; % 根据实际情况修改样本数量
data = zeros(numSamples, 8);

% 接收数据
for i = 1:numSamples
    rawData = fread(s, 1, 'uint8'); % 读取一个字节
    for j = 1:8
        data(i, j) = bitget(rawData, j); % 解码每个通道的数据
    end
end

% 关闭串口
fclose(s);
delete(s);
clear s;

% 绘制数据
figure;
for i = 1:8
    subplot(8, 1, i);
    plot(data(:, i));
    title(['通道 ', num2str(i)]);
    ylim([-0.5 1.5]);
end