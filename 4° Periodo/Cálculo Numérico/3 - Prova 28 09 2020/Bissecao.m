function [raizAproximada] = Bissecao(fx, a, b, tol)
    currentTol = 0
    it = 0
    maxIt = 50
    
    while((currentTol == 0 || currentTol >= tol) && (it <= maxIt))
        it = it + 1
      
        c = (a + b)/2
        if sign(fx(c)) != sign(fx(a))
            b = c
        elseif sign(fx(c)) != sign(fx(b))
            a = c
        else
            return
        endif
        
        if (exist("prevC", "var") == 1)
            currentTol = abs((c-prevC)/prevC * 100)
        endif
        
        prevC = c
        raizAproximada = c
    endwhile
    
    raizAproximada = min([abs(fx(a)), abs(fx(b)), abs(fx(c))])
endfunction