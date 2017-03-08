%% --------------------- PART 10.4 -----------------*
run('init.m')   % closes all figures, clears all and clc + init parameters
addpath('Help functions')

global N alpha lambda_t beta nx
%% [---- Task 10.4.1 System on continous state space ----]
A_c = [ 0     1     0       0        0       0      ;       % travel
        0     0   -K_2      0        0       0      ;       % travel dot
        0     0     0       1        0       0      ;       % pitch
        0     0 -K_1*K_pp -K_1*K_pd  0       0      ;       % pitch dot
        0     0     0       0        0       1      ;       % elevation
        0     0     0       0   -K_3*K_ep -K_3*K_ed ;];     % elevation dot

B_c = [ 0       0      ;
        0       0      ;
        0       0      ;
     K_1*K_pp   0      ;
        0       0      ;
        0    K_3*K_ep  ;];
    
%% [---- Task 10.4.2 Forward Euler Method ----]
I = eye(6);
delta_t = 0.25;
A = I + delta_t*A_c;
B = delta_t*B_c;

%% [---- Task 10.4.3 SQP ----]
q1 = 1; q2 = q1;
alpha = 0.2;    beta = 20;
lambda_0 = pi;  lambda_f = 0;   lambda_t = 2*pi/3;
time_padding = 5; sim_t = 35;

% Number of states and inputs
nx = size(A,2);                % Number of states (number of columns in A)
nu = size(B,2);                % Number of inputs(number of columns in B)
N = 40;                        % Time horizon for states
M = N;                         % Time horizon for inputs
n = N*nx+M*nu;

x0 = [lambda_0 ;0 ;0 ;0; 0; 0];
xf = [lambda_f; 0; 0; 0; 0; 0];
x = zeros(N*6,1);
x(1:6) = x0;
Q_1 = 2*diag([1 0 0 0 0 0]);
P_1 = diag([q1 q1]);

% Generating A_eq, B_eq and Q
A_eq = gena2(A, B, N, nx, nu);
B_eq = zeros(size(A_eq,1),1);
B_eq(1:nx) = A*x0;
G = 2*genq2(Q_1,P_1,N,M,nu);

% Initialize z                 
z  = zeros(n,1);
z0 = z;

% Bounds
pk      = 30*pi/180;
ul 	    = [-pk; -inf];                   % Lower bound on control -- u1
uu 	    = [pk; inf];                     % Upper bound on control -- u1

xl(1:nx,1)    = -Inf*ones(nx,1);         % Lower bound on states (no bound)
xu(1:nx,1)    = Inf*ones(nx,1);          % Upper bound on states (no bound)
xl(3)   = ul(1);                         % Lower bound on state x3
xu(3)   = uu(1);                         % Upper bound on state x3

% Generate constraints on measurements and inputs
[vlb,vub]   = genbegr2(N,M,xl,xu,ul,uu);
vlb(n)      = 0;                        % We want the last input to be zero
vub(n)      = 0;                        % We want the last input to be zero

f = @(z) 1/2*z'*G*z;
opt = optimoptions('fmincon','Algorithm','sqp','MaxFunEvals',7000);
tic
[Z, ZVAL, EXITFLAG] = fmincon(f, z0, [], [], A_eq, B_eq, ...
    vlb, vub, @constraints, opt);
toc

% Extract control inputs and states
u1 = [Z(N*nx+1:nu:n);Z(n-1)];           % Control input 1 from solution
u2 = [Z(N*nx+2:nu:n);Z(n)];             % Control input 2 from solution
x1 = [x0(1);Z(1:nx:N*nx)];              % State x1 from solution
x2 = [x0(2);Z(2:nx:N*nx)];              % State x2 from solution
x3 = [x0(3);Z(3:nx:N*nx)];              % State x3 from solution
x4 = [x0(4);Z(4:nx:N*nx)];              % State x4 from solution
x5 = [x0(5);Z(5:nx:N*nx)];              % State x5 from solution
x6 = [x0(6);Z(6:nx:N*nx)];              % State x6 from solution

num_pads = time_padding/delta_t;
zero_padding = zeros(num_pads,1);
unit_padding  = ones(num_pads,1);

u1  = [zero_padding; u1; zero_padding];
u2  = [zero_padding; u2; zero_padding];
x1  = [lambda_0*unit_padding; x1; zero_padding];
x2  = [zero_padding; x2; zero_padding];
x3  = [zero_padding; x3; zero_padding];
x4  = [zero_padding; x4; zero_padding];
x5  = [zero_padding; x5; zero_padding];
x6  = [zero_padding; x6; zero_padding];

t = 0:delta_t:delta_t*(length(u1)-1);

figure(); 
subplot(nx,1,1); 
plot(t,x1); grid on;
title('travel')
subplot(nx,1,2)
plot(t,x2); grid on;
title('travel dot')
subplot(nx,1,3)
plot(t,x3); grid on;
title('pitch')
subplot(nx,1,4)
plot(t,x4); grid on;
title('pitch dot')
subplot(nx,1,5)
plot(t,x5); grid on;
title('elevation')
subplot(nx,1,6)
plot(t,x6); grid on;
title('elevation dot')

% Input imported to helicopter
x_opt = [x1 x2 x3 x4 x5 x6];
u = [u1 u2];
calculated_input.time = t;
calculated_input.signals.values = u;
calculated_input.signals.dimensions = 2;
figure();
stem(t, calculated_input.signals.values, 'Linewidth', 2); grid on;
legend({'p_c', 'e_c'}, 'location', 'NorthEast', 'FontSize', 36)
