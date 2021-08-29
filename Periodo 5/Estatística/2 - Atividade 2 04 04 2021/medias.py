import math

def round(a):
    decimal = a - math.floor(a)

    if decimal >= 0.5:
        return math.ceil(a)
    else:
        return math.floor(a)

def median(arr):
    if len(arr) % 2 == 0:
        return (arr[int(len(arr)/2)] + arr[int(len(arr)/2) - 1]) / 2
    else:
        return arr[int(len(arr)/2)]

def mean(arr):
    return sum(arr)/len(arr)

def variance(arr):
    vectorMean = mean(arr)
    totalSum = 0

    for val in arr:
        totalSum += math.pow((val - vectorMean), 2)

    return totalSum/(len(arr) - 1)

def mediumDeviation(arr):
    vectorMean = mean(arr)
    totalSum = 0

    for val in arr:
        totalSum += abs(val - vectorMean)

    return totalSum/len(arr)

def standardDeviation(arr):
    return math.sqrt(variance(arr))

def variationCoeficient(arr):
    return standardDeviation(arr)/mean(arr)

def main():
    valores = [0.73, 0.81, 0.85, 0.9]

    print("Média: {}".format(mean(valores)))
    print("Variância: {}".format(variance(valores)))
    print("Desvio Padrão: {}".format(standardDeviation(valores)))
    print("Desvio Médio: {}".format(mediumDeviation(valores)))
    print("Coeficiente de Variação: {}".format(variationCoeficient(valores)))

    input()

if __name__ == '__main__':
    main()