clc;clear all;close all;
%% 串口配置
%---- 使用serialport进行串口配置 ----%
Port_List = serialportlist("available")   % 显示可用的串口信息
SerialObj = serialport("COM7",921600);   % 串口参数配置

data = read(SerialObj,30000,"uint8" );  
% 一次读取一个字节，将每个字节解释为一个 8 位无符号整数 (uint8)，并返回一个 double 数组
% 此处读取了3000个字节
% data_hex = dec2hex(data);

delete(SerialObj);                    % 使用完一定记得删除串口占用
% 
% %---- 使用serial进行串口配置 ----%
% instrfind                             % 查看已有的串口信息
% delete(instrfind);                    % 关闭遗忘的串口
% port = 'COM7';                       % 端口号选择dataport
% baudrate = 115200;                    % 波特率设置921600bit等于115200个字节
% S = serial(port,'baudrate',baudrate); % 串口设置
% S.InputBufferSize = 300;              % 输入串口缓冲区上限10000字节               
% S.Timeout = 5;                        % Timeout为完成读取或写入操作的等待时间，如果未指定其他值，则使用默认值 10 秒
% 
% try
%   fopen(S);                           % 打开串口对象
% catch err
%   fclose(instrfind);                  % 关闭被占用的串口
%   error('请确认选择了正确的串口');      % 输出错误提示
% end
% instrfind                             % 查看已有的串口信息（牢记使用虚拟串口时打开后需要记得关闭）
% 
% data = fread(S);                      % 直接将所有的数据进行接收，除非数据长度超过了数据缓存区的长度，超过即不显示,又或者超出等待时间
% fclose(S)
% delete(S)                             % 使用完一定记得删除串口占用



t = 1:1:length(data)
plot(t,data)