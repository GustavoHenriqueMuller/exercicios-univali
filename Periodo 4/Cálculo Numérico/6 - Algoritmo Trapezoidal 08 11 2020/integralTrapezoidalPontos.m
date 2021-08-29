function [areaAproximada] = integralTrapezoidalPontos(pontos, a, b)
    areaTotal = 0
    qntTrapezios = length(pontos)-1
    areaBaseIndividual = (b-a)/qntTrapezios
    
    for i = 1 : qntTrapezios
        areaTrapezioIndividual = (areaBaseIndividual/2) * (pontos(i) + pontos(i+1))
        areaTotal += areaTrapezioIndividual
    endfor
    
    areaAproximada = areaTotal
endfunction
