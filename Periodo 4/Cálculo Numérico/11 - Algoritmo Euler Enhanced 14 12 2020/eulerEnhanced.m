% fx: função de "x" (derivada)
% x0: valor inicial de "x"
% y0: valor inicial de "y"
% step: valor entre cada "x" (conhecido como "h")
% stepAmount: quantidade de vezes para aplicar o step.

function [result] = eulerEnhanced(fx, x0, y0, step, stepAmount)
    x = x0
    y = y0
    
    for i = 1 : stepAmount
        firstSlope = fx(x, y)
        yNext = y + firstSlope * step
        x += step
        
        secondSlope = fx(x, yNext)
        finalSlope = (firstSlope + secondSlope)/2
        y = y + finalSlope * step
        
        result = y
    endfor
endfunction