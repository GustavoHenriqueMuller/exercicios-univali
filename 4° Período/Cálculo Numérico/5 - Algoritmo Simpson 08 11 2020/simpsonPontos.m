function [areaAproximada] = simpsonPontos(pontos, a, b)
    areaTotal = 0
    i = 1
    numeroPontos = length(pontos)
    numeroIntervalos = numeroPontos - 1
    width = (b-a)/numeroIntervalos
    
    if mod(numeroIntervalos, 2) != 0
        return
    endif    

    for i = 1 : 2 : numeroPontos-2
        areaTotal += (width/3) * (pontos(i) + (4*pontos(i+1)) + pontos(i+2))
    endfor
    
    areaAproximada = areaTotal
endfunction
