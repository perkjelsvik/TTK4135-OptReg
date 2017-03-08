%% --------------------- PART 10.3 -----------------*
run('Part_10_2.m')
addpath('Data logs')

%% [---- 10.2.4 - Implement QP Simulink ----]
% Plot travel
figure();
f = load('travel_10_2.mat');
plot(f.ans(1,:),f.ans(2,:), t,180*u,'r--', 'LineWidth',2); grid on;

%% [---- Task 10.3.1 Q,R and K (LQR) ----]
Q_lqr = diag([3 1 .05 .1]);
R_lqr = diag([.1]);
K_lqr = dlqr(A,B,Q_lqr,R_lqr);

%% [---- Task 10.3.2 Implement feedback ----]

x_opt = [x1 x2 x3 x4];

figure();
f = load('travel_10_3.mat');
plot(f.ans(1,:),f.ans(2,:), t,180*u,'r--', 'LineWidth',2); grid on;
