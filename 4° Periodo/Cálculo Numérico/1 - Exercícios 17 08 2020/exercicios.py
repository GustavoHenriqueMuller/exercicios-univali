# Para executar qualquer exercício, apenas copie o comentário respectivo acima sem o hashtag.
# Cole ele em baixo da última função, fora de qualquer escopo.

# exercicioA()
def exercicioA():
    nome = input("Digite o seu nome: ")
    idade = int(input("Digite a sua idade: "))
    
    print(nome + ", você já viveu " + str(idade * 365) + " dias.")

# exercicioB()
def exercicioB():
    distanciaPercorrida = int(input("Digite a distância percorrida: "))
    combustivelLitros = int(input("Digite a quantidade de combustível gasta (L): "))
    autonomia = combustivelLitros/distanciaPercorrida
    
    if autonomia <= 15:
        print("O seu carro é econômico (" + str(autonomia) + ").")
    else:
        print("O seu carro não é econômico (" + str(autonomia) + ").")
       
# exercicioC()
def exercicioC():
    soma = 0
    
    for i in range(100):
        if i % 5 == 0:
            soma += i
            
    print("Soma: " + str(soma))
    
# exercicioD()
def exercicioD():
    for i in range(100):
        print(i**2)
        
# exercicioE([0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29])
def exercicioE(vetor):
    for i in range(len(vetor)):
        if i % 2 != 0:
            print(vetor[i])

# exercicioF([[1,2,3], [4,5,6]])
def exercicioF(matriz):
    matrizNova = [[0,0,0], [0,0,0]]

    for i in range(len(matriz)):
        for j in range(len(matriz[i])):
            matrizNova[i][j] = matriz[i][j]**3
            
    print("Matriz de Entrada")
    for i in range(len(matriz)):
        for j in range(len(matriz[i])):
            print(matriz[i][j])
    
    print("\nMatriz Gerada (Cubo)")
    for i in range(len(matrizNova)):
        for j in range(len(matrizNova[i])):
            print(matrizNova[i][j])
