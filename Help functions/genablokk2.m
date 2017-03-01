function A = genablokk2(A1,B1,N,M,mx,mu,t1,t2)

% Funksjon for aa bygge opp A-matrisa som brukes i QP-problemet 
%                                                               
%       min sum(xi'Q1xi + ui'P1ui)                              
%       x,u                                                     
%                                                               
% i det tidsdiskrete systemet med pådragsblokkering (delt i tre intervaller).
% Innholder et system for hvert tidsskritt og er på formen                                    
%                                                               
%                 k<t1 k>t1                                             
%      -                  -                                   
%      |I        |-B1     |                                   
%  A = |-A1 I    |-B1     |                                   
%      |   . .   |    -B1 |                                   
%      |   -A1 I |    -B1 |                                   
%      -                  -                                   
%                                                               
% Kall: A = gena2(A1,B1,N,M,mx,mu,t1,t2)                                
%                                                               
% A1 - A matrise i tidsdiskret modell                           
% B1 - B matrise i tidsdiskret modell                           
% N  - Tidshorisont (antall tidsskritt)
% M  - Antall ulike pådrag
% mx - Antall tilstander                                        
% mu - Antall pådrag
% t1 - Tidsskritt hvor pådraget endres første gang
% t2 - Tidsskritt hvor pådraget endres andre gang
%                                                               
% 08.03.2001 Geir Stian Landsverk                               
                                                              
% B1-blokken i A
b1 = [];                % Første pådrag
for k = 1:t1-1
   b1 = [b1;-B1];
end

b2 = [];                % Andre pådrag
for k = t1:t2-1
   b2 = [b2;-B1];
end

b3 = [];                % Tredje pådrag
for k = t2:N
   b3 = [b3;-B1];
end

b4 = blkdiag(b1,b2,b3);

% A1-blokken i A

a1	= eye(N*mx);
for i=1:(N-1)
  a1([(i*mx+1):((i+1)*mx)],[((i-1)*mx+1):(i*mx)])=-A1;
end

% Bygger A-matrisen fra de to blokkene
A 	= zeros(N*mx,N*mx+M*mu);
A	= [a1 b4];