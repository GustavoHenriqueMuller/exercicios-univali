function [raizAproximada] = NewtonRaphson(fx, fxdev, xfirst, tol)
    currentTol = 0
    it = 0
    maxIt = 50
    xcurrent = xfirst
    
    while((currentTol == 0 || currentTol >= tol) && (it <= maxIt))
        it = it + 1
        xlast = xcurrent        
        xcurrent = xlast - fx(xlast)/fxdev(xlast);
        
        currentTol = abs((xcurrent - xlast)/xcurrent * 100)
    endwhile
    
    raizAproximada = xcurrent
endfunction
