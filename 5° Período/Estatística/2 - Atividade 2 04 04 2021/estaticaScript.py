import math

def lerp(a,b,k):
    lo = min(a,b)
    hi = max(a,b)
    return lo + (hi - lo) * k

def mean(arr):
    return sum(arr)/len(arr)

def variance(arr):
    vectorMean = mean(arr)
    totalSum = 0

    for val in arr:
        totalSum += math.pow((val - vectorMean), 2)

    return totalSum/(len(arr)-1)

def mediumDeviation(arr):
    vectorMean = mean(arr)
    totalSum = 0

    for val in arr:
        totalSum += abs(val - vectorMean)

    return totalSum/len(arr)

def standartDeviation(arr):
    return math.sqrt(variance(arr))

def variationCoeficient(arr):
    return standartDeviation(arr)/mean(arr)

def main():
    valores = [0.73, 0.81, 0.85, 0.9]

    print("Média: {}".format(mean(valores)))
    print("Variância: {}".format(variance(valores)))
    print("Desvio Padrão: {}".format(standartDeviation(valores)))
    print("Desvio Médio: {}".format(mediumDeviation(valores)))
    print("Coeficiente de Variação: {}".format(variationCoeficient(valores)))
    
    input()

if __name__ == '__main__':
    main()