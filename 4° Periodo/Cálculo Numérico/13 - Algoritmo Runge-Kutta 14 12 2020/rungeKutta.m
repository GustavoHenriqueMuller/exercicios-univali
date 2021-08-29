% fx: função de "x" (derivada)
% x0: valor inicial de "x"
% y0: valor inicial de "y"
% step: valor entre cada "x" (conhecido como "h")
% stepAmount: quantidade de vezes para aplicar o step.

function [result] = rungeKutta(fx, x0, y0, step, stepAmount)
    x = x0
    y = y0
    
    for i = 1 : stepAmount
        k1 = fx(x, y)
        k2 = fx(x + step/2, y + step/2 * k1)
        k3 = fx(x + step/2, y + step/2 * k2)
        k4 = fx(x + step, y + step * k3)
        
        y = y + step/6 * (k1 + 2*k2 + 2*k3 + k4)
        x += step
        
        result = y
    endfor
endfunction