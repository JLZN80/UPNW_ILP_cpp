% ====================================================
% IMPLEMENTANDO UN "CONTADOR"...
% ====================================================
% longitud (Lista, N) : N es la longitud de la lista

% ====================================================
% Caso Base: lista este vacia -> longitud 0
% ====================================================
longitud([], 0).

% ====================================================
% Caso Recursivo: 1 + longitud de la cola
% ====================================================
longitud([_ | T], N) :- longitud(T, N_Cola), N is N_Cola + 1.


% ====================================================
% Lista = [ Header | Tail ]
% longitud( [guerrero,lapadula,cueva,concha], N). (N = 1)
% paso 1: [lapadula, cueva, concha], N1 is N = N1 + 1 (N = 2)
% paso 2: [cueva, concha], N2 is N = N1 + 1 (N = 3)
% paso 3: [concha], N3 is N = N2 + 1 (N = 4)
% paso 4: [], N4 = 0
% ====================================================


% ====================================================
% INTERACCION DE CONSULTAS...
% ====================================================
?- longitud([guerrero,lapadula,cueva,concha], R).