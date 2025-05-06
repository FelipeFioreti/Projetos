def binarySearch(valor ,array):
    maior = len(array) - 1
    menor = 0

    while(menor <= maior):
        meio = (menor + maior) / 2

        if(array[meio] == valor):
            return meio

        if(array[meio] < valor):
            menor = meio + 1
        else:
            maior = meio - 1

    return menor


print(binarySearch(20,[10,20,30,40,50,60,70,80]))

