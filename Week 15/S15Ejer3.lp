% ====================================================
% IMPLEMENTANDO UNA "SUMA"...
% suma (Lista, SumaTotal) : SumtaTotal es la Suma de los elementos de la lista


% ====================================================
% Caso Base: lista este vacia -> SumaTotal es 0
% ====================================================
suma([], 0).


% ====================================================
% Caso Recursivo: (Header + Suma de la Cola)
% ====================================================
suma([H | T], SumaTotal) :- suma(T, SumaCola), SumaTotal is H + SumaCola.


% ====================================================
% INTERACCION DE CONSULTAS...
% ====================================================
?- suma([10, 25, 5, 3, 3, 11, 100, 200, 1500, 88], R).

?- suma([], R).