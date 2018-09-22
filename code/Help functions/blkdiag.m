function y = blkdiag(varargin)
%BLKDIAG  Block diagonal concatenation of input arguments.
%
%                                   |A 0 .. 0|
%   Y = BLKDIAG(A,B,...)  produces  |0 B .. 0|
%                                   |0 0 ..  |
%
%   See also DIAG, HORZCAT, VERTCAT

% Wes Wang 9/9/94, 9/30/95.  Greg Wolodkin 1/30/98
% Copyright (c) 1984-98 by The MathWorks, Inc.
% $Revision: 1.2 $

y = [];
for k=1:nargin
  x = varargin{k};
  [p1,m1] = size(y); [p2,m2] = size(x);
  y = [y zeros(p1,m2); zeros(p2,m1) x];
end
