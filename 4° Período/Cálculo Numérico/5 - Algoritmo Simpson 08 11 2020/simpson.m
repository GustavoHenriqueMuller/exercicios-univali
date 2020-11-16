function [areaAproximada] = simpson(fx, a, b, n)
    areaTotal = 0
    width = (b-a)/n
    
    if mod(n+1, 2) != 0
        # Retorna se "n" (número de intervalos) não for par
        return
    endif    
    
    startingPoint = a
    endPoint = startingPoint + width*2
    midPoint = (startingPoint + endPoint)/2
    
    while(endPoint <= b)
        areaTotal += (width/3)*(fx(startingPoint) + 4*(fx(midPoint)) + fx(endPoint))
        
        startingPoint = endPoint
        endPoint = startingPoint + width*2
        midPoint = (startingPoint + endPoint)/2
    endwhile
    
    areaAproximada = areaTotal
endfunction
