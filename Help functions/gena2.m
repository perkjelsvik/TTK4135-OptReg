function A = gena2(A1,B1,N,mx,mu)

% Funksjon for aa bygge opp A-matrisa som brukes i QP-problemet 
%                                                               
%       min sum(xi'Q1xi + ui'P1ui)                              
%       x,u                                                     
%                                                               
% i det tidsdiskrete systemet. Innholder et system for hvert    
% tidsskritt og er på formen                                    
%                                                               
%      -                    -                                   
%      |I        |-B1       |                                   
%  A = |-A1 I    |  -B1     |                                   
%      |   . .   |     .    |                                   
%      |   -A1 I |      -B1 |                                   
%      -                    -                                   
%                                                               
% Kall: A = gena2(A1,B1,N,mx,mu)                                
%                                                               
% A1 - A matrise i tidsdiskret modell                           
% B1 - B matrise i tidsdiskret modell                           
% N  - Tidshorisont (antall tidsskritt), antar M=N
% mx - Antall tilstander                                        
% mu - Antall pådrag                                            
%                                                               
% 08.03.2001 Geir Stian Landsverk                               
                                                              

A 	= zeros(N*mx,N*mx+N*mu);
b1	= blkdiag2(-B1,N);
a1	= eye(N*mx);
for i=1:(N-1)
  a1([(i*mx+1):((i+1)*mx)],[((i-1)*mx+1):(i*mx)])=-A1;
end
A	= [a1 b1];