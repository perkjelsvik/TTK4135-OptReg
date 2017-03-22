function y = blkdiag2(varargin)

% BLKDIAG2  Block diagonal concatenation of input arguments.
%
%                                   |A 0 .. 0|
%   Y = BLKDIAG2(A,N)  produces     |0 A .. 0|
%                                   |0 0 .. A|
%   where 	size(A) = [m,n]
%			size(Y) = [N*m,N*n]
%
%   See also DIAG, HORZCAT, VERTCAT

% Wes Wang 9/9/94, 9/30/95.  Greg Wolodkin 1/30/98
% Copyright (c) 1984-98 by The MathWorks, Inc.
% $Revision: 1.2 $

% Modified version of blkdiag.m
% Geir Stian Landsverk 3/8/01


x = varargin{1};
[p2,m2] = size(x);
y = [];
for k = 1:varargin{2}
  [p1,m1] = size(y); 
  y = [y zeros(p1,m2); zeros(p2,m1) x];
end
