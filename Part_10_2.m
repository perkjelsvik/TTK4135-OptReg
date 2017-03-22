%% *---------------- PART 10.2 -------------------------*
run('init.m')
addpath('Help functions')
%% [---- 10.2.1 - Continuous time state space ----]
A_c = [0 1 0 0; 
       0 0 -K_2 0;
       0 0 0 1;
       0 0 -K_1*K_pp -K_1*K_pd];
B_c = [0; 0; 0; K_1*K_pp];

%% [---- 10.2.2 - Forward Euler Method ----]
I = eye(4);
delta_t = 0.25;
A = I + delta_t*A_c;
B = delta_t*B_c;

%% [---- 10.2.3 - Optimal trajectory ----]
% Inital values
lambda_0 = pi;
lambda_f = 0;
x0 = [lambda_0 ;0 ;0 ;0];
xf = [lambda_f ;0 ;0 ;0]; 
Q1 = 2*diag([1 0 0 0]);
q0 = 1;
A1 = A;
B1 = B;
time_padding = 5;

% Number of states and inputs
mx = size(A1,2);                % Number of states (number of columns in A)
mu = size(B1,2);                % Number of inputs(number of columns in B)
N = 100;                        % Time horizon for states
M = N;                          % Time horizon for inputs
n = N*mx+M*mu;

% Generating A_eq, B_eq and Q
A_eq = gena2(A1, B1, N, mx, mu);
B_eq = zeros(size(A_eq,1),1);
B_eq(1:mx) = A1*x0;
Q = 2*genq2(Q1,q0,N,M,mu);

% Initialize z
c  = zeros(n,1);                 
z  = zeros(n,1);
z0 = z;

% Bounds
pk      = 30*pi/180;
ul 	    = -pk;                          % Lower bound on control -- u1
uu 	    = pk;                           % Upper bound on control -- u1

xl      = -Inf*ones(mx,1);              % Lower bound on states (no bound)
xu      = Inf*ones(mx,1);               % Upper bound on states (no bound)
xl(3)   = ul;                           % Lower bound on state x3
xu(3)   = uu;                           % Upper bound on state x3

% Generate constraints on measurements and inputs
[vlb,vub]   = genbegr2(N,M,xl,xu,ul,uu);
vlb(n)      = 0;                        % We want the last input to be zero
vub(n)      = 0;                        % We want the last input to be zero

% Using QP to find Z and lambda
tic
[z, lambda] = quadprog(Q,c,[],[],A_eq,B_eq,vlb,vub,x0);
t1 = toc;

% Calculate objective value
phi1 = 0.0;
PhiOut = zeros(n,1);
for i=1:n
  phi1=phi1+Q(i,i)*z(i)*z(i);
  PhiOut(i) = phi1;
end

% Extract control inputs and states
u  = [z(N*mx+1:n);z(n)]; % Control input from solution

x1 = [x0(1);z(1:mx:N*mx)];              % State x1 from solution
x2 = [x0(2);z(2:mx:N*mx)];              % State x2 from solution
x3 = [x0(3);z(3:mx:N*mx)];              % State x3 from solution
x4 = [x0(4);z(4:mx:N*mx)];              % State x4 from solution

padded_zeros = time_padding/delta_t;
zero_padding = zeros(padded_zeros,1);
unit_padding  = ones(padded_zeros,1);

u   = [zero_padding; u; zero_padding];
x1  = [lambda_0*unit_padding; x1; zero_padding];
x2  = [zero_padding; x2; zero_padding];
x3  = [zero_padding; x3; zero_padding];
x4  = [zero_padding; x4; zero_padding];


% Plotting
t = 0:delta_t:delta_t*(length(u)-1);

figure();
hold on;
subplot(511)
stairs(t,u),grid
ylabel('u')
subplot(512)
plot(t,x1,'r',t,x1,'mo'),grid
ylabel('lambda')
subplot(513)
plot(t,x2,'r',t,x2','mo'),grid
ylabel('r')
subplot(514)
plot(t,x3,'r',t,x3,'mo'),grid
ylabel('p')
subplot(515)
plot(t,x4,'r',t,x4','mo'),grid
xlabel('tid (s)'),ylabel('pdot')



% Input imported to helicopter
calculated_input.time = t;
calculated_input.signals.values = u;
calculated_input.signals.dimensions = 1;
figure();
plot(calculated_input.time, calculated_input.signals.values)