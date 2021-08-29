% mat: A matriz contendo, na primeira linha, os valores de "xi"
% e na segunda linha os valores de "yi".

function [resultado] = diffDiv(mat, xDesejado, grauAMenos = 0)
    colunas = columns(mat)
    
    % Cria a matriz completa
    for i = 3 : colunas - grauAMenos
        for j = 1 : colunas
            if j < colunas - (i - 3)
                mat(i, j) = (mat(i-1, j+1) - mat(i-1, j))/(mat(1, j + i-2) - mat(1, j))
            else
                mat(i, j) = 0
            endif
        endfor
    endfor
    
    % Calcula P(xDesejado)
    resultado = mat(2, 1)
    
    for i = 3 : rows(mat)
        temporario = 1
        
        for j = 1 : i-2
            temporario *= (xDesejado - mat(1, j))
        endfor
        
        resultado += temporario * mat(i, 1)
    endfor
endfunction