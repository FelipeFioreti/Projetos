

//int[,] matriz = new int[linhas, colunas];

int[,] matriz1 = new int[,]
{
    { 1, 2},
    { 4, 5},
};



int[,] matriz2 = new int[,]
{
    { 3, 7},
    { 2, 8},
    { 5, 1}
};



int opcaoMenu = 0;
int linhaMatriz1 = 0;
int linhaMatriz2 = 0;
int colunaMatriz1 = 0;
int colunaMatriz2 = 0;
do
{
    MostrarMenu();

    string opcao = Console.ReadLine()!;
    opcaoMenu = VerificarEntrada(opcao);

    Console.Clear();

    switch (opcaoMenu)
        {
        case 1:
            do
            {
                int[] valores = AtribuirValores();
                linhaMatriz1 = valores[0];
                colunaMatriz1 = valores[1];
                linhaMatriz2 = valores[2];
                colunaMatriz2 = valores[3];
            } while (!VerificarMatriz(linhaMatriz1, colunaMatriz1, linhaMatriz2, colunaMatriz2));

            Console.Clear();
            Console.WriteLine("Matriz 1:");
            // int[,] matriz1 = AtribuirMatriz(linhaMatriz1,colunaMatriz1);

            Console.Clear();
            Console.WriteLine("Matriz 2:");
            //int[,] matriz2 = AtribuirMatriz(linhaMatriz2, colunaMatriz2);

            Console.WriteLine("Aperte qualquer tecla para continuar...");
            Console.ReadKey();
            Console.WriteLine("Adição das Matrizes:");

            SomarMatrizes(matriz1, matriz2);

            Console.WriteLine("Aperte qualquer tecla para continuar...");
            Console.ReadKey();
            break;
        case 2:

            do
            {
                int[] valores = AtribuirValores();
                linhaMatriz1 = valores[0];
                colunaMatriz1 = valores[1];
                linhaMatriz2 = valores[2];
                colunaMatriz2 = valores[3];
            } while (!VerificarMatriz(linhaMatriz1, colunaMatriz1, linhaMatriz2, colunaMatriz2));

            Console.Clear();
            Console.WriteLine("Matriz 1:");
            // int[,] matriz1 = AtribuirMatriz(linhaMatriz1,colunaMatriz1);

            Console.Clear();
            Console.WriteLine("Matriz 2:");
            //int[,] matriz2 = AtribuirMatriz(linhaMatriz2, colunaMatriz2);

            Console.WriteLine("Aperte qualquer tecla para continuar...");
            Console.ReadKey();
            Console.WriteLine("Subtração das Matrizes:");

            SubtrairMatrizes(matriz1, matriz2);

            Console.WriteLine("Aperte qualquer tecla para continuar...");
            Console.ReadKey();
            break;
        case 3:

            Console.Clear();
            Console.WriteLine("Matriz 1:");
            // int[,] matriz1 = AtribuirMatriz(linhaMatriz1,colunaMatriz1);

            Console.Clear();
            Console.WriteLine("Matriz 2:");
            //int[,] matriz2 = AtribuirMatriz(linhaMatriz2, colunaMatriz2);

            Console.WriteLine("Aperte qualquer tecla para continuar...");
            Console.ReadKey();
            Console.WriteLine("Multipliação das Matrizes:");

            MultiplicarMatrizes(matriz1, matriz2);

            Console.WriteLine("Aperte qualquer tecla para continuar...");
            Console.ReadKey();
            break;
        case 4:


            Console.Clear();
            Console.WriteLine("Matriz 1:");
            // int[,] matriz1 = AtribuirMatriz(linhaMatriz1,colunaMatriz1);

            Console.Clear();
            Console.WriteLine("Matriz 2:");
            //int[,] matriz2 = AtribuirMatriz(linhaMatriz2, colunaMatriz2);

            Console.WriteLine("Aperte qualquer tecla para continuar...");
            Console.ReadKey();
            Console.WriteLine("Divisão das Matrizes:");

            DividirMatrizes(matriz1, matriz2);

            Console.WriteLine("Aperte qualquer tecla para continuar...");
            Console.ReadKey();
            break;
        case 5:
            Console.WriteLine("Saindo...");
            
            break;
        default:
            Console.WriteLine("Escolha uma opção válida.");
            Console.ReadKey();
            break;
        }
} while (opcaoMenu != 5);

void SomarMatrizes(int[,] matriz1, int[,] matriz2)
{
    int[,] resultado = new int[matriz1.GetLength(0),matriz2.GetLength(0)];

    for (int i = 0; i < matriz1.GetLength(0); i++)
    {
        for (int j = 0; j < matriz1.GetLength(1); j++)
        {
            resultado[i, j] = matriz1[i, j] + matriz2[i, j];
        }
    }

    for (int i = 0; i < resultado.GetLength(0); i++)
    {
        for (int j = 0; j < resultado.GetLength(1); j++)
        {
            Console.Write($"{resultado[i, j]} ");
        }
        Console.WriteLine();
    }
    Console.ReadKey();

}

void SubtrairMatrizes(int[,] matriz1, int[,] matriz2)
{
    int[,] resultado = new int[matriz1.GetLength(0), matriz2.GetLength(0)];

    for (int i = 0; i < matriz1.GetLength(0); i++)
    {
        for (int j = 0; j < matriz1.GetLength(1); j++)
        {
            resultado[i, j] = matriz1[i, j] - matriz2[i, j];
        }
    }

    for (int i = 0; i < resultado.GetLength(0); i++)
    {
        for (int j = 0; j < resultado.GetLength(1); j++)
        {
            Console.Write($"{resultado[i, j]} ");
        }
        Console.WriteLine();
    }
    Console.ReadKey();
}


int[] AtribuirValores()
{
    Console.WriteLine("Digite o número de linhas da matriz 1:");
    linhaMatriz1 = int.Parse(Console.ReadLine());

    Console.WriteLine("Digite o número de colunas da matriz 1:");
    colunaMatriz1 = int.Parse(Console.ReadLine());

    Console.WriteLine("Digite o número de linhas da matriz 2:");
    linhaMatriz2 = int.Parse(Console.ReadLine());

    Console.WriteLine("Digite o número de colunas da matriz 2:");
    colunaMatriz2 = int.Parse(Console.ReadLine());

    return new int[] { linhaMatriz1, colunaMatriz1, linhaMatriz2, colunaMatriz2 };
}

int[,] AtribuirMatriz(int linha, int coluna)
{
    int[,] matriz = new int[linha, coluna];

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            Console.WriteLine($"Digite o valor da posição [{i},{j}]:");
            matriz[i, j] = int.Parse(Console.ReadLine());
        }
    }
    
    return matriz;
} 

bool VerificarMatriz(int linhaMatriz1, int colunaMatriz1, int linhaMatriz2, int colunaMatriz2)
{
    if (linhaMatriz1 == linhaMatriz2 && colunaMatriz1 == colunaMatriz2)
    {
        return true;
    }
    
    Console.WriteLine("As matrizes não possuem as mesmas dimensões.");
    
    return false;    
}

int VerificarEntrada(string entrada)
{
    int saida = 0;
    bool isValid = int.TryParse(entrada, out saida);

    while (!isValid)
    {
        Console.WriteLine("Opção inválida. Tente novamente.");
        Console.WriteLine("Aperte qualquer tecla para continuar...");
        Console.ReadKey();
        MostrarMenu();
        entrada = Console.ReadLine()!;
        isValid = int.TryParse(entrada, out saida);
        
    }

    return saida;
}

void MostrarMenu(){
    Console.Clear();
    Console.WriteLine("Escolha uma opção:");
    Console.WriteLine("1 - Somar Matrizes");
    Console.WriteLine("2 - Subtrair Matrizes");
    Console.WriteLine("3 - Multiplicar Matrizes");
    Console.WriteLine("4 - Dividir Matrizes");
    Console.WriteLine("5 - Sair");
    Console.WriteLine("");
    Console.Write("Opção: ");
}

void MultiplicarMatrizes(int[,] matriz1, int[,] matriz2)
{
    if (matriz1.GetLength(1) == matriz2.GetLength(0))
    {
        int[,] resultado = new int[matriz1.GetLength(0), matriz2.GetLength(1)];


        for (int i = 0; i < matriz1.GetLength(0); i++)
        {
            for (int j = 0; j < matriz2.GetLength(1); j++)
            {
                resultado[i, j] = 0;
                for (int k = 0; k < matriz2.GetLength(0); k++)
                {
                    resultado[i, j] += matriz1[i, k] * matriz2[k, j];
                }

            }
        }

        for (int i = 0; i < resultado.GetLength(0); i++)
        {
            for (int j = 0; j < resultado.GetLength(1); j++)
            {
                Console.Write($"{resultado[i, j]} ");
            }
            Console.WriteLine();
            Console.ReadKey();

        }
    }
    else
    {
        Console.WriteLine("As matrizes não podem ser multiplicadas.");
        Console.WriteLine("Para realizar multiplicação de matrizes o número de colunas da matriz 1 deve ser igual ao número de linhas da matriz 2.");
        Console.WriteLine($"A matriz 1 possui {matriz1.GetLength(1)} colunas e a matriz 2 possui {matriz2.GetLength(0)} linhas.");
        
    }
}


void DividirMatrizes(int[,] matriz1, int[,] matriz2)
{

}