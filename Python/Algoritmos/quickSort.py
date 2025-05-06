
def QuickSort(array):
    if(len(array) < 2):
        return array;
    

    pivo = array[0]
    maiores = [i for i in array[1:] if i > pivo ]
    menores = [i for i in array[1:] if i <= pivo ]

    return QuickSort(menores) + [pivo] + QuickSort(maiores)



print(QuickSort([27,42,5,10,99]))
        
