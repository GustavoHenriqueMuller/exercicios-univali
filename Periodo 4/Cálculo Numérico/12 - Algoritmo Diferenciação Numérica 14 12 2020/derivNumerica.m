% fx: função de x
% x1: um ponto qualquer
% x2: outro ponto qualquer

function [result] = derivNumerica(fx, x1, x2)
    rightPoint = max(x1, x2)
    leftPoint = min(x1, x2)
    result = (fx(rightPoint) - fx(leftPoint))/(rightPoint - leftPoint)
endfunction