function [vlb,vub] = genBegr2(N,M,xl,xu,ul,uu);

 
% Funksjon som genererer begrensninger paa paadragene og tilstandene.
%
% Kall: [vlb,vub] = genBegr2(N,M,xl,xu,ul,uu)
%
% N     - Tidshorisont for tilstander   (antall tidsskritt)
% M     - Tidshorisont for pådrag       (M<N ved pådragsblokkering)
% xl    - Nedre grense for tilstandene  (kolonnevektor  - mx*1)
% xu    - Øvre grense for tilstander    (kolonnevektor  - mx*1)
% ul    - Nedre grense for pådrag       (kolonnevektor  - mu*1)
% uu    - Øvre grense for pådrag        (kolonnevektor  - mu*1)
%
% Oppdatert 29/3-2001 av Geir Stian Landsverk

vlb_x	= repmat(xl,N,1);			% Lager begrensning for hvert tidsskritt
vub_x	= repmat(xu,N,1);			% Lager begrensning for hvert tidsskritt

vlb_u	= repmat(ul,M,1);			% Lager begrensning for hvert tidsskritt
vub_u	= repmat(uu,M,1);			% Lager begrensning for hvert tidsskritt

vlb	    = [vlb_x; vlb_u];			% Setter sammen begrensningene for xl og ul
vub	    = [vub_x; vub_u];			% Setter sammen begrensningene for xu og uu


