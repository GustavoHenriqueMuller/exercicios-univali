function [resultados] = gaussSeidel(matrix, valoresIniciais, tolAbsoluta = 0.01, maxIt = 50)
    matrixRows = length(valoresIniciais)
    matrixColumns = matrixRows + 1
    
    resultadosItPassada = valoresIniciais
    resultados = valoresIniciais
    residuo = []
    maiorResiduo = []
    
    it = 0
    
    # Isola a variável correspondente à linha na direita
    for i = 1 : matrixRows   
        for j = 1 : matrixColumns
            if j == i
                temp = matrix(i, j)
                matrix(i, j) = -1 * matrix(i, matrixColumns)
                matrix(i, matrixColumns) = -1 * temp
            endif
        endfor
    endfor
    
    # Divide toda a equação pelo coeficiente da variável isolada no loop passado
    for i = 1 : matrixRows
        for j = 1 : matrixColumns-1
            matrix(i, j) = matrix(i,j)/matrix(i, matrixColumns)
        endfor
        
        matrix(i, matrixColumns) = 1
    endfor
    
    # Começa a iterar, construindo os resultados
    while(it < maxIt && (isempty(maiorResiduo) || maiorResiduo >= tolAbsoluta))
        resultadosItPassada = resultados
        
        for i = 1 : matrixRows
            result = 0
            
            for j = 1 : matrixColumns-1
                # O valor "matrix(i, j)" se i == j é um escalar e não uma
                # variável. Nesse caso, não multiplicamos por "resultados(j)"
                if j != i
                    result += matrix(i, j) * resultados(j)
                else
                    result += matrix(i, j)
                endif
            endfor
            
            resultados(i) = result
        endfor
        
        residuo = abs(abs(resultados) - abs(resultadosItPassada))
        maiorResiduo = max(residuo)
        
        it += 1
    endwhile
endfunction
