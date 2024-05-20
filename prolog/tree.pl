% the lists of the mothers
mother(lisa, abe).
mother(lisa, sarah).
mother(nancy, john).
mother(sarah, susan).
mother(susan, jack).
mother(mary, jill).

% lists of the fathers
father(tony, abe).
father(tony, sarah).
father(abe, john).
father(bill, susan).
father(john, jill).
father(rob, phil).
father(rob, jack).
father(jack, jim).

% get the parents to find the same gen
parent(X, Y) :- mother(X, Y).
parent(X, Y) :- father(X, Y).

% get the same generations
same_generation(X, Y) :-
    parent(Z, X),
    parent(Z, Y),
    X \= Y.

same_generation(X, Y) :-
    parent(Z, X),
    parent(W, Y),
