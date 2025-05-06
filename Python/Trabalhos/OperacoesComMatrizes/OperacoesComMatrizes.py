def mostrar_menu():
    print("\nEscolha uma opção:")
    print("1 - Somar Matrizes")
    print("2 - Subtrair Matrizes")
    print("3 - Multiplicar Matrizes")
    print("4 - Dividir Matrizes")
    print("5 - Sair")
    return input("Opção: ")

def verificar_entrada(mensagem):
    while True:
        try:
            return float(input(mensagem))
        except ValueError:
            print("Valor inválido. Tente novamente.")

def atribuir_matriz(linhas, colunas):
    matriz = []
    for i in range(linhas):
        linha = []
        for j in range(colunas):
            valor = verificar_entrada(f"Digite o valor da posição [{i},{j}]: ")
            linha.append(valor)
        matriz.append(linha)
    return matriz

def somar_matrizes(matriz1, matriz2):
    if len(matriz1) != len(matriz2) or len(matriz1[0]) != len(matriz2[0]):
        print("As matrizes devem ter as mesmas dimensões.")
        return

    linhas = len(matriz1)
    colunas = len(matriz1[0])
    resultado = []

    for i in range(linhas):
        linha_resultado = []
        for j in range(colunas):
            linha_resultado.append(matriz1[i][j] + matriz2[i][j])
        resultado.append(linha_resultado)
    imprimir_matriz(resultado)


def subtrair_matrizes(matriz1, matriz2):
    
    if len(matriz1) != len(matriz2) or len(matriz1[0]) != len(matriz2[0]):
        print("As matrizes devem ter as mesmas dimensões.")
        return
    
    linhas = len(matriz1)
    colunas = len(matriz1[0])
    resultado = []

    for i in range(linhas):
        linha_resultado = []
        for j in range(colunas):
            linha_resultado.append(matriz1[i][j] - matriz2[i][j])
        resultado.append(linha_resultado)
    imprimir_matriz(resultado)

def multiplicar_matrizes(matriz1, matriz2):
    if not pode_multiplicar(len(matriz1[0]), len(matriz2)):
        raise ValueError("Número de colunas da matriz 1 deve ser igual ao número de linhas da matriz 2.")

    resultado = []
    for i in range(len(matriz1)):
        linha_resultado = []
        for j in range(len(matriz2[0])):
            soma = 0
            for k in range(len(matriz2)):
                soma += matriz1[i][k] * matriz2[k][j]
            linha_resultado.append(soma)
        resultado.append(linha_resultado)
    imprimir_matriz(resultado)

def dividir_matrizes(matriz1, matriz2):
    det = verificar_determinante(matriz2)
    if det == 0:
        print("A matriz 2 não pode ser invertida. Determinante igual a 0.")
        return

    inv = [
        [matriz2[1][1]/det, -matriz2[0][1]/det],
        [-matriz2[1][0]/det, matriz2[0][0]/det]
    ]
    multiplicar_matrizes(matriz1, inv)

def verificar_determinante(matriz):
    return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0]

def imprimir_matriz(matriz):
    print("Resultado:")
    for linha in matriz:
        print(" ".join(f"{v:.2f}" for v in linha))

def pode_multiplicar(coluna1, linha2):
    if(coluna1 == linha2):
        return True
    return False

# Programa principal
while True:
    opcao = mostrar_menu()

    if opcao == "1":
        tamanho = int(verificar_entrada("Insira o tamanho das linhas e colunas: "))
        print("Matriz 1:")
        matriz1 = atribuir_matriz(tamanho, tamanho)
        print("Matriz 2:")
        matriz2 = atribuir_matriz(tamanho, tamanho)
        somar_matrizes(matriz1, matriz2)

    elif opcao == "2":
        tamanho = int(verificar_entrada("Insira o tamanho das linhas e colunas: "))
        print("Matriz 1:")
        matriz1 = atribuir_matriz(tamanho, tamanho)
        print("Matriz 2:")
        matriz2 = atribuir_matriz(tamanho, tamanho)
        subtrair_matrizes(matriz1, matriz2)

    elif opcao == "3":
        linha1 = int(verificar_entrada("Linhas da matriz 1: "))
        coluna1 = int(verificar_entrada("Colunas da matriz 1: "))
        linha2 = int(verificar_entrada("Linhas da matriz 2: "))
        coluna2 = int(verificar_entrada("Colunas da matriz 2: "))
        if not pode_multiplicar(coluna1, linha2):
            print("Não é possível multiplicar essas matrizes. Colunas da matriz 1 devem ser iguais às linhas da matriz 2.")
            continue
        print("Matriz 1:")
        matriz1 = atribuir_matriz(linha1, coluna1)
        print("Matriz 2:")
        matriz2 = atribuir_matriz(linha2, coluna2)
        multiplicar_matrizes(matriz1, matriz2)

    elif opcao == "4":
        print("A divisão só é permitida para matrizes 2x2.")
        print("Matriz 1:")
        matriz1 = atribuir_matriz(2, 2)
        print("Matriz 2:")
        matriz2 = atribuir_matriz(2, 2)
        dividir_matrizes(matriz1, matriz2)

    elif opcao == "5":
        print("Saindo...")
        break

    else:
        print("Opção inválida. Tente novamente.")
