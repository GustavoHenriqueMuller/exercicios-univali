from math import *

xArr = [2,4,6,8,10,12,15]
yArr = [51,51,54,53,60,65,66]

# SXX
lhs = 0
for i in range(len(xArr)):
    lhs += xArr[i] * xArr[i]

lhs *= len(xArr)
sxx = lhs - (pow(sum(xArr), 2))

# SYY
lhs = 0
for i in range(len(xArr)):
    lhs += yArr[i] * yArr[i]

lhs *= len(xArr)
syy = lhs - (pow(sum(yArr), 2))

# SXY
lhs = 0
for i in range(len(xArr)):
    lhs += xArr[i] * yArr[i]

lhs *= len(xArr)
sxy = lhs - (sum(xArr) * sum(yArr))

print('SXX: ' + str(sxx))
print('SXY: ' + str(syy))
print('SXY: ' + str(sxy))
print('r: ' + str(sxy/sqrt(sxx * syy)))
input()