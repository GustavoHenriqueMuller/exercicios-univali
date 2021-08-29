% fx: função de "x" (derivada)
% x0: valor inicial de "x"
% y0: valor inicial de "y"
% step: valor entre cada "x" (conhecido como "h")
% stepAmount: quantidade de vezes para aplicar o step.

function [result] = euler(fx, x0, y0, step, stepAmount)
    x = x0
    y = y0
    
    for i = 1 : stepAmount
        slope = fx(x, y)
        y = y + slope * step
        x += step
        
        result = y
    endfor
endfunction