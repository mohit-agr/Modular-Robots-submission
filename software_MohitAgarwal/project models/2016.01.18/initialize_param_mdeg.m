
clc;
close all;

%% Init. the parameters of the model

L   = 0.18e-3; % Henry
R   = 0.15;    % Ohm 
Kr  = 160;     % gear reduction ratio
Km = 0.0429;  % Nm/A (V*s/mdeg) 
% Km = 0.0429 / ((180/pi) * 1000);  % Nm/A (V*s/mdeg) 

Jeq = 0.2740;  % Kg*m^2
Bv = 10 / ((180/pi) * 1000);       % Nms/mdeg
Bc = 0.6;      % Nm

Tv = (Jeq/Bv) ;      % mdeg/Nms
zeta = 1;       % damping ratio
wn = 150 * (180/pi) * 1000;       % natural frequency. Tr >= 10*Ts [mdeg/s]

Kp = wn / (2*zeta);
Kv = wn^2 * Bv / (Kp*Kr*Km);
