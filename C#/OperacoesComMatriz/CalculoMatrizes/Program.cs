int opcaoMenu = 0;
int linhaMatriz1 = 0;
int linhaMatriz2 = 0;
int colunaMatriz1 = 0;
int colunaMatriz2 = 0;

do
{
    MostrarMenu();

    string opcao = Console.ReadLine()!;
    opcaoMenu = VerificaEntradaMenu(opcao);

    Console.Clear();

    switch (opcaoMenu)
        {
        case 1:
            Console.WriteLine("|----------------------------------------------OBSERVAÇÃO-----------------------------------------------|");
            Console.WriteLine("| A adição de matrizes só é possível com matrizes quadradas.                                            |");
            Console.WriteLine("| Desta Maneira, escolha o tamanho das linhas e das colunas das matrizes.                               |");
            Console.WriteLine("|-------------------------------------------------------------------------------------------------------|");
            Console.WriteLine("");
            Console.WriteLine("Insira o tamanho das linhas e colunas: ");
            string entradaAdicao = Console.ReadLine()!;
            int tamanhoMatrizAdicao = (int)VerificaEntrada(entradaAdicao);

            Console.Clear();
            Console.WriteLine("Matriz 1:");
            float[,] matrizSoma1 = AtribuirMatriz(tamanhoMatrizAdicao, tamanhoMatrizAdicao);

            Console.WriteLine("Matriz 2:");
            float[,] matrizSoma2 = AtribuirMatriz(tamanhoMatrizAdicao, tamanhoMatrizAdicao);

            Console.WriteLine("Aperte qualquer tecla para continuar...");
            Console.ReadKey();
            Console.WriteLine("Adição das Matrizes:");

            SomarMatrizes(matrizSoma1, matrizSoma2);

            Console.WriteLine("Aperte qualquer tecla para continuar...");
            Console.ReadKey();
            linhaMatriz1 = 0;
            linhaMatriz2 = 0;
            colunaMatriz1 = 0;
            colunaMatriz2 = 0;
            break;
        case 2:

            Console.WriteLine("|----------------------------------------------OBSERVAÇÃO-----------------------------------------------|");
            Console.WriteLine("| A Subtração de matrizes só é possível com matrizes quadradas.                                         |");
            Console.WriteLine("| Desta Maneira, escolha o tamanho das linhas e das colunas das matrizes.                               |");
            Console.WriteLine("|-------------------------------------------------------------------------------------------------------|");
            Console.WriteLine("");
            Console.WriteLine("Insira o tamanho das linhas e colunas: ");
            string entradaSub = Console.ReadLine()!;
            int tamanhoMatrizSub = (int)VerificaEntrada(entradaSub);

            Console.Clear();
            Console.WriteLine("Matriz 1:");
            float[,] matrizSub1 = AtribuirMatriz(tamanhoMatrizSub, tamanhoMatrizSub);

            Console.Clear();
            Console.WriteLine("Matriz 2:");
            float[,] matrizSub2 = AtribuirMatriz(tamanhoMatrizSub, tamanhoMatrizSub);

            Console.WriteLine("Aperte qualquer tecla para continuar...");
            Console.ReadKey();
            Console.WriteLine("Subtração das Matrizes:");

            SubtrairMatrizes(matrizSub1, matrizSub2);

            Console.WriteLine("Aperte qualquer tecla para continuar...");
            Console.ReadKey();
            linhaMatriz1 = 0;
            linhaMatriz2 = 0;
            colunaMatriz1 = 0;
            colunaMatriz2 = 0;
            break;
        case 3:

            do
            {
                int[] valores = AtribuirValores();
                linhaMatriz1 = valores[0];
                colunaMatriz1 = valores[1];
                linhaMatriz2 = valores[2];
                colunaMatriz2 = valores[3];

            } while (!VerificaSePodeMulti(colunaMatriz1,linhaMatriz2));

            Console.Clear();
            Console.WriteLine("Matriz 1:");
            float[,] matrizMulti1 = AtribuirMatriz(linhaMatriz1,colunaMatriz1);

            Console.Clear();
            Console.WriteLine("Matriz 2:");
            float[,] matrizMulti2 = AtribuirMatriz(linhaMatriz2, colunaMatriz2);

            Console.WriteLine("Aperte qualquer tecla para continuar...");
            Console.ReadKey();

            MultiplicarMatrizes(matrizMulti1, matrizMulti2);

            Console.WriteLine("Aperte qualquer tecla para continuar...");
            Console.ReadKey();
            linhaMatriz1 = 0;
            linhaMatriz2 = 0;
            colunaMatriz1 = 0;
            colunaMatriz2 = 0;
            break;
        case 4:

            Console.WriteLine("|----------------------------------------------OBSERVAÇÃO-----------------------------------------------|");
            Console.WriteLine("|A divisão de matrizes só é possível com matrizes quadradas de 2x2 e com determinante diferente de zero.|");
            Console.WriteLine("|-------------------------------------------------------------------------------------------------------|");
            Console.WriteLine("Aperte qualquer tecla para continuar...");
            Console.ReadKey();

            Console.Clear();
            Console.WriteLine("Matriz 1:");
            float[,] matrizDivisao1 = AtribuirMatriz(2,2);

            Console.Clear();
            Console.WriteLine("Matriz 2 (usada na divisão):");
            float[,] matrizDivisao2 = AtribuirMatriz(2, 2);

            Console.WriteLine("Aperte qualquer tecla para continuar...");
            Console.ReadKey();

            DividirMatrizes(matrizDivisao1, matrizDivisao2);

            Console.WriteLine("Aperte qualquer tecla para continuar...");
            Console.ReadKey();
            linhaMatriz1 = 0;
            linhaMatriz2 = 0;
            colunaMatriz1 = 0;
            colunaMatriz2 = 0;
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

void SomarMatrizes(float[,] matriz1, float[,] matriz2)
{
    float[,] resultado = new float[matriz1.GetLength(0),matriz1.GetLength(1)];

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

void SubtrairMatrizes(float[,] matriz1, float[,] matriz2)
{
    float[,] resultado = new float[matriz1.GetLength(0), matriz2.GetLength(0)];

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
    string entrada;

    Console.WriteLine("Digite o número de linhas da matriz 1:");
    entrada = Console.ReadLine()!;
    linhaMatriz1 = (int)VerificaEntrada(entrada);

    Console.WriteLine("Digite o número de colunas da matriz 1:");
    entrada = Console.ReadLine()!;
    colunaMatriz1 = (int)VerificaEntrada(entrada);

    Console.WriteLine("Digite o número de linhas da matriz 2:");
    entrada = Console.ReadLine()!;
    linhaMatriz2 = (int)VerificaEntrada(entrada);

    Console.WriteLine("Digite o número de colunas da matriz 2:");
    entrada = Console.ReadLine()!;
    colunaMatriz2 = (int)VerificaEntrada(entrada);

    return new int[] { linhaMatriz1, colunaMatriz1, linhaMatriz2, colunaMatriz2 };
}

float[,] AtribuirMatriz(int linha, int coluna)
{
    float[,] matriz = new float[linha, coluna];
    string entrada;

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            Console.WriteLine($"Digite o valor da posição [{i},{j}]:");

            entrada = Console.ReadLine()!;
            matriz[i, j] = VerificaEntrada(entrada);
        }
    }
    
    return matriz;
} 

int VerificaEntradaMenu(string entrada)
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

float VerificaEntrada(string entrada)
{
    int countErros = 0;
    float saida = 0;
    bool isValid = float.TryParse(entrada, out saida);
    while (!isValid)
    {
        Console.WriteLine("Valor inválido.");
        if (countErros >= 3)
        {
            Console.Clear();
        }
        Console.WriteLine("Por favor, insira novamente: ");
        entrada = Console.ReadLine()!;
        isValid = float.TryParse(entrada, out saida);
        countErros++;
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

void MultiplicarMatrizes(float[,] matriz1, float[,] matriz2)
{

    float[,] resultado = new float[matriz1.GetLength(0), matriz2.GetLength(1)];


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

    Console.WriteLine("Resultado: ");
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
bool VerificaSePodeMulti(int colunaMatriz1, int linhaMatriz2)
{
    if (colunaMatriz1 == linhaMatriz2)
    {
        return true;
    }
    else
    {
        Console.WriteLine("As matrizes não podem ser multiplicadas.");
        Console.WriteLine("Para realizar multiplicação de matrizes o número de colunas da matriz 1 deve ser igual ao número de linhas da matriz 2.");
        Console.WriteLine("Por favor, insira novamente.");
        Console.WriteLine("Aperte qualquer tecla para continuar...");
        Console.ReadKey();
        return false;
    }
}
void DividirMatrizes(float[,] matriz1, float[,] matriz2)
{

    float determinante = VerificaDeterminante(matriz2);

    if (determinante != 0)
    {
        float[,] matrizInversa = new float[2, 2];

        float inversor = 1 / determinante;

        // Invertendo matriz
        matrizInversa[0, 0] = matriz2[1, 1] * inversor;
        matrizInversa[0, 1] = -matriz2[0, 1] * inversor;
        matrizInversa[1, 0] = -matriz2[1, 0] * inversor;
        matrizInversa[1, 1] = matriz2[0, 0] * inversor;

        MultiplicarMatrizes(matriz1, matrizInversa);
    }
    else
    {
        Console.WriteLine("As matrizes não podem ser divididas.");
        Console.WriteLine("Para realizar divisão de matrizes a matriz 2 deve ser quadrada e ter determinante diferente de zero.");
        Console.WriteLine($"A matriz 2 possui determinante igual {determinante}");
    }

}
float VerificaDeterminante(float[,] matriz)
{
    return matriz[0, 0] * matriz[1, 1] - matriz[0, 1] * matriz[1, 0];
}

