% 定义系统参数
K = 2;      % 增益
T = 0.5;    % 时间常数(秒)
dt = 0.01;  % 自定义步进时间(秒)
t_end = 5*T; % 仿真总时长

% 创建传递函数
num = K;
den = [T 1];
sys = tf(num, den);

% 显示传递函数
disp('系统传递函数:');
disp(sys);

% 生成时间向量和阶跃输入
t = 0:dt:t_end;
u = ones(size(t)); % 阶跃信号

% 绘制响应曲线
figure;
lsim(sys,u,t); % 使用自定义步长仿真
grid on;
title('一阶系统阶跃响应');

% 添加标注(包含步进时间)
legend_str = sprintf('K=%.1f, T=%.1fs, dt=%.2fs',K,T,dt);
legend(legend_str,'Location','southeast');

text(0.6*T, 0.63*K, ['63.2% @ t=',num2str(T),'s'],...
     'BackgroundColor','white');
text(2.2*T, 0.9*K, ['rise time=',num2str(2.2*T),'s'],...
     'BackgroundColor','white');
