function [areaAproximada] = integralTrapezoidal(fx, a, b, qntTrapezios)
    areaTotal = 0
    areaBaseIndividual = (b-a)/qntTrapezios
    
    for i = 1 : qntTrapezios
        offsetInicial = areaBaseIndividual * (i-1)
        offsetFinal = areaBaseIndividual * (i)
        areaTrapezioIndividual = (areaBaseIndividual/2) * (fx(a + offsetInicial) + fx(a + offsetFinal))
        
        areaTotal += areaTrapezioIndividual
    endfor
    
    areaAproximada = areaTotal
endfunction
