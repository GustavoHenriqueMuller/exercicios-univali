import math
import numpy
import medias

def sturges(arr):
    return medias.round(math.log(len(arr), 2) + 1)

def intervalAmplitude(arr):
    qnt = sturges(arr)

    return (arr[-1] - arr[0])/qnt

def intervaloEmIndice(arr, index):
    h = intervalAmplitude(arr)
    return math.floor((arr[index] - arr[0])/h)

def numericalIntervals(arr):
    intervals = []
    qnt = sturges(arr)
    h = intervalAmplitude(arr)

    for i in range(qnt + 1):
        intervals.append(arr[0] + i * h)

    return intervals

def absoluteFrequencies(arr):
    intervals = numericalIntervals(arr)
    qnt = sturges(arr)
    h = intervalAmplitude(arr)
    freqs = []

    for i in range(len(intervals) - 1):
        freqs.append(0)

    for i in range(len(arr)):
        currInterval = intervaloEmIndice(arr, i)

        if currInterval == qnt:
            currInterval -= 1

        freqs[currInterval] += 1

    return freqs

def mediumPoints(arr):
    intervals = numericalIntervals(arr)
    xm = []

    for i in range(len(intervals) - 1):
        xm.append((intervals[i] + intervals[i + 1])/2)

    return xm

def relativeFrequencies(arr):    
    freqsAbs = absoluteFrequencies(arr)
    qnt = len(arr)
    freqs = []

    for freq in freqsAbs:
        freqs.append(freq/qnt * 100)

    return freqs

def freqAbsDesc(arr, isRelative):    
    freqsAbs = absoluteFrequencies(arr)
    freqs = []    

    for i in range(len(freqsAbs)):
        freqs.append(freqsAbs[i] if not isRelative else freqsAbs[i]/len(arr) * 100)

        if len(freqs) > 1:
            freqs[-1] += freqs[-2]

    return freqs

def freqAbsAsc(arr, isRelative):    
    freqsAbs = absoluteFrequencies(arr)
    currVal = len(arr)
    freqs = []

    for i in range(len(freqsAbs)):
        freqs.append(currVal if not isRelative else currVal/len(arr) * 100)
        currVal -= freqsAbs[i]

    return freqs

def div():
    print("_" * 90)
    print()

def main():
    valores = [14.0, 14.1, 14.13, 14.17, 14.2, 14.2, 14.3, 14.3, 14.3, 14.35, 14.4, 14.5, 14.6, 14.7, 14.8, 14.8, 14.9, 15.0, 15.1, 15.2, 15.6, 15.6, 15.7, 15.8, 15.9]

    div()
    print("Intervalos Numéricos: {}".format(numericalIntervals(valores)))
    print("Pontos Médios (xm): {}".format(mediumPoints(valores)))
    print("Frequências Absolutas (fa): {}".format(absoluteFrequencies(valores)))
    print("Frequências Relativas (fr %): {}".format(relativeFrequencies(valores)))
    div()
    print("Frequências Absoluta Desc. (fa desc): {}".format(freqAbsDesc(valores, False)))
    print("Frequências Absoluta Asc. (fa asc): {}".format(freqAbsAsc(valores, False)))
    div()
    print("Frequências Relativa Desc. (fr desc): {}".format(freqAbsDesc(valores, True)))
    print("Frequências Relativa Asc. (fr desc): {}".format(freqAbsAsc(valores, True)))
    div()
    print("Média: {}".format(medias.mean(valores)))
    print("Mediana: {}".format(medias.median(valores)))
    print("Variância: {}".format(medias.variance(valores)))
    print("Desvio Padrão: {}".format(medias.standardDeviation(valores)))
    print("Coeficiente de Variação: {}".format(medias.variationCoeficient(valores)))
    div()

if __name__ == '__main__':
    main()