
clc;
close all;

%% Init. the parameters of the model

L   = 0.18e-3; % Henry
R   = 0.15;    % Ohm 
Kr  = 160;     % gear reduction ratio
Km = 0.0429;  % Nm/A (V*s/rad) 

Jeq = 0.2740;  % Kg*m^2
Bv = 8;       % Nms/rad
Bc = 0.6;      % Nm

Tv = Jeq/Bv;
zeta = 1;       % damping ratio
wn = 100;       % natural frequency. Tr >= 10*Ts [rad/s]

Kp = wn / (2*zeta);
Kv = wn^2 * Bv / (Kp*Kr*Km);
% Kv = 380; 
% Kp = 100;
% Kp = (Kv*Kr*Km) / (4*Bv*(zeta^2));
% wn = sqrt( ( Kp*Kv*Kr*Km) / Bv);

%% Parameters for filter
Tr_f = 2;          % s
wn_f = 2*pi/Tr_f;  % rad/s
zeta_f = 0.9;
s = tf(1, [(1/(wn_f^2)) (2*zeta_f/wn_f) 1]);

z_f = c2d(s, 0.004);
num = cell2mat(z_f.num);
den = cell2mat(z_f.den);
