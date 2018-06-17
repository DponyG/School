% take.pro
% Samuel Grenon
% CS 331 
% Exc D 

take(_, [], []).
take(0, _, []).

% Takes a number N and two lists. Returns true if
%		first N elements are identical in each list.
take(N, [X|Xs], [X|Es]):- M is N-1, take(M,Xs,Es).