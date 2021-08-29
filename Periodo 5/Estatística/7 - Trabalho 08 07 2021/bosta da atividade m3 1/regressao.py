from math import *

xArr = [2,4,6,8,10,12,15]
yArr = [51,51,54,53,60,65,66]

# CALCULAR M

# NUMERADOR
soma = 0

for i in range(len(xArr)):
    soma += xArr[i] * yArr[i]

soma *= len(xArr)
numerador = soma - (sum(xArr) * sum(yArr))

# DENOMINADOR
soma = 0

for i in range(len(xArr)):
    soma += xArr[i] * xArr[i]

soma *= len(xArr)
denominador = soma - pow(sum(xArr), 2)

m = numerador/denominador

# CALCULAR B
soma = 0

for i in range(len(xArr)):
    soma += xArr[i] * xArr[i]

soma *= sum(yArr)

soma2 = 0
for i in range(len(yArr)):
    soma2 += xArr[i] * yArr[i]

soma2 *= sum(xArr)

numerador = soma - soma2

soma = 0
for i in range(len(yArr)):
    soma += xArr[i] * xArr[i]

soma *= len(xArr)
denominador = soma - pow(sum(xArr), 2)

b = numerador/denominador

print("m: " + str(m))
print("b: " + str(b))
input()