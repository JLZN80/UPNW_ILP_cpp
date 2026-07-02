% ====================================================
% IMPLEMENTANDO "PERTENENCIA"...
% ====================================================
% Si "X" es miembro de la lista de sospechosos?
% Lista: [elem1, elem2, elem3, ...]
% Lista: [Header | Tail]


% ====================================================
% Caso Base (DONDE SE DETIENE): X SEA el Header - La persona SI ESTA en la lista de sospechoso
% ====================================================
miembro(X, [X | _]).


% ====================================================
% Case Recursivo (DONDE DEBE REPERTIR): X NO SEA el Header
% Buscar en la cola T (Aplicar Header - Cola)
% ====================================================
miembro(X, [_ | T]) :- miembro(X, T).


% ====================================================
% INTERACCION DE CONSULTAS...
% ====================================================
% Ejecutamos las consultas para verificar si una persona es miembro de la lista de sospechosos
% ====================================================

?- miembro(carlos, [ana, jorge, luis, carlos]).