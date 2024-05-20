% create the empty lists
sumlists([], [], []).

% cases in which the lists are different lengths
sumlists([], [SecondHead|SecondTail], [SecondHead|SumTail]) :-
    SecondHead >= 0,
    sumlists([], SecondTail, SumTail).

sumlists([FirstHead|FirstTail], [], [FirstHead|SumTail]) :-
    FirstHead >= 0,
    sumlists(FirstTail, [], SumTail).

% sum of the lists
sumlists([FirstHead|FirstTail], [SecondHead|SecondTail], [SumHead|SumTail]) :-
    SumHead is FirstHead + SecondHead,
    SumHead >= 0,
    sumlists(FirstTail, SecondTail, SumTail).