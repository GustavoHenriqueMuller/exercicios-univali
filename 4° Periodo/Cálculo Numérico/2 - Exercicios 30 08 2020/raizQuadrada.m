function [fx,ea,iter]=raizQuadrada(x,es,maxit)
    % Aproximação de raíz quadrada por método babilônico
    %   [fx,ea,iter]=IterMeth(x,es,maxit)
    % entrada :
    %   x = valor que terá a raíz quadrada calculada
    %   es = critério de parada (default = 0.0001)
    %   maxit = número máximo de iterações (default = 50)
    % saída :
    %   fx = valor estimado
    %   ea = erro relativo aproximado (%)
    %   iter = número de iterações

    % padrões (valores default):
    if nargin<2||isempty(es)
        es=0.0001;
    end
    if nargin<3||isempty(maxit)
        maxit=50;
    end
    % inicialização
    iter = 1; 
    sol = x;
    ea = 100;
    % cálculo iterativo
    while (1)
        sol_previa = sol;        
        iter = iter + 1;
        
        if sol ~= 0
            sol = (sol + (x/sol))/2;
            ea = abs((sol - sol_previa)/sol)*100;
        end
        
        if ea<=es || iter>=maxit
            break
        end
    end
    
    fx = sol;
end