import tkinter as tk
from tkinter import ttk
from tkinter.ttk import *
import sqlite3
from tkinter import messagebox

# Criando conexão
def conexao_banco():
    try:
        conexao = sqlite3.connect("produtos.db")
        return conexao
    except sqlite3.Error as e:
        print("Erro ao conectar com o banco de dados:", e)

# Criando tabela
try:
    conexao = conexao_banco()
    c = conexao.cursor()
    c.execute("""CREATE TABLE IF NOT EXISTS produtos(
    nome VARCHAR(100) NOT NULL,
    descricao VARCHAR(250) NOT NULL,
    valor INTEGER NOT NULL,
    disponivel BOOLEAN NOT NULL
    )
    """)
        
except sqlite3.Error as e: 
    print("Erro ao ao criar a tabela:", e)


# Janela da interface e suas configurações 
janela = tk.Tk()
janela.title("Ferramenta de Cadastro")
janela.geometry('1240x600')

# Não deixe alterar altura e largura
janela.resizable(height=False,width=False)


#Estilo da interface
estilo = Style(janela)
estilo.theme_use("clam")

def excluir_produtos():
    conexao = conexao_banco()
    c = conexao.cursor()

    if messagebox.askyesno("Alerta","Tem certeza que deseja apagar tudo?"):
        c.execute("DELETE FROM produtos")
    
    excluir_lista()
    criar_lista()

    conexao.commit()
    conexao.close()
    
def cadastrar_produto():
    conexao = conexao_banco()
    c = conexao.cursor()
    if (entry_nome.get() and entry_descricao.get() and entry_valor.get() and entry_disponivel.get()):
        if not(entry_valor.get().isnumeric()):
            return messagebox.showinfo("Alerta","Por favor, Insira um número válido para o valor.")
        

        elif verificar_entradas(entry_nome.get()) or verificar_entradas(entry_descricao.get()):
            return messagebox.showinfo("Alerta","Por favor, Não insira caracteres especiais na descrição e no nome.")
        

        elif any(x.isdigit() for x in entry_nome.get()):
            return messagebox.showinfo("Alerta", " Por favor, não coloque números no nome.")
        

        elif entry_disponivel.get().upper() != "SIM" and entry_disponivel.get().upper() != "NÃO":
            return messagebox.showinfo("Alerta", "Por favor, insira valores de apenas Sim ou Não na disponibilidade")
        
        else:
            if int(entry_valor.get()) < 1:
                return messagebox.showinfo("Alerta","Por favor, Insira um número positivo para o valor.")
        
            c.execute("INSERT INTO produtos VALUES (:nome,:descricao,:valor,:disponivel)",
                    {
                        'nome': entry_nome.get(),
                        'descricao': entry_descricao.get(),
                        'valor': entry_valor.get(),
                        'disponivel': entry_disponivel.get().upper()
                    })


            entry_nome.delete(0,"end")
            entry_descricao.delete(0,"end")
            entry_valor.delete(0,"end")
            entry_disponivel.delete(0,"end")

            excluir_lista()
            criar_lista()
            
            filtrar_produto("nome")

            conexao.commit()
            conexao.close()
    else:
        return messagebox.showinfo("Alerta","Por favor, preencha todos os campos.")

def verificar_entradas(entrada):
    if type(entrada) is str:  
        lista_verificacao = entrada.split(" ")
        vereficacao = ""
        if vereficacao.join(lista_verificacao).isalnum():
            return False
        else:
            return True
        
def filtrar_produto(filtro):
    conexao = conexao_banco()
    c = conexao.cursor()
    c.execute(f"SELECT * FROM produtos ORDER BY {filtro} ")
    lista_produto = c.fetchall()
    
    excluir_lista()
    criar_lista()

    for elem in lista_produto:
        lista_cursos.insert('','end',values=elem)

    #excluir_lista()
    conexao.commit()
    conexao.close()

def filtrar_produto_nome():
    filtrar_produto("nome")

def filtrar_produto_valor():
    filtrar_produto("valor")

def excluir_lista():
    lista_cursos.destroy()

def criar_lista():
    global lista_cursos
    lista_cabecalho = ["Nome", "Descrição", "Valor", "Disponível"]

    lista_cursos = ttk.Treeview(janela,selectmode="extended",columns=lista_cabecalho,show="headings")
    lista_cursos.grid(row=8,column=3,sticky="ns")

    hd = ["nw","nw","n","n"]
    h = [150, 180, 80, 80]
    n = 0
    for elem in lista_cabecalho:
        lista_cursos.heading(elem, text=elem.title(), anchor="nw")
        lista_cursos.column(elem,width=h[n], anchor=hd[n])
        n += 1


#Labels
label_nome = tk.Label(janela,text="Nome")
label_nome.grid(row=1,column=0,padx=10, pady=10)

label_descricao = tk.Label(janela,text="Descrição")
label_descricao.grid(row=2,column=0,padx=10, pady=10)

label_valor = tk.Label(janela,text="Valor")
label_valor.grid(row=3,column=0,padx=10, pady=10)

label_disponivel = tk.Label(janela,text="Disponível para Venda")
label_disponivel.grid(row=4,column=0,padx=10, pady=10)


#Entradas
entry_nome = tk.Entry(janela,text="Nome", width = 30)
entry_nome.grid(row=1,column=1,padx=10, pady=10)

entry_descricao = tk.Entry(janela,text="Descrição", width = 30)
entry_descricao.grid(row=2,column=1,padx=10, pady=10)

entry_valor = tk.Entry(janela,text="Valor" , width = 30)
entry_valor.grid(row=3,column=1,padx=10, pady=10)

disponivel = ["Sim", "Não"]

entry_disponivel = ttk.Combobox(janela, width = 27)
entry_disponivel.grid(row=4,column=1,padx=10, pady=10)
entry_disponivel['values'] = (disponivel)


#Lista 
criar_lista()


#Botões
botao_cadastrar = tk.Button(janela,text="Cadastrar Produto",overrelief="ridge", command = cadastrar_produto)
botao_cadastrar.grid(row=5,column=0,padx=10, pady=10)

botao_filtrar_nome = tk.Button(janela,text="Filtrar Produtos por Nome",overrelief="ridge", command = filtrar_produto_nome)
botao_filtrar_nome.grid(row=4,column=3,padx=10, pady=10)

botao_filtrar_valor = tk.Button(janela,text="Filtrar Produtos por Valor",overrelief="ridge", command = filtrar_produto_valor)
botao_filtrar_valor.grid(row=5,column=3,padx=10, pady=10)

botao_excluir = tk.Button(janela,text="Excluir Produtos",overrelief="ridge", command = excluir_produtos)
botao_excluir.grid(row=5,column=1,padx=10, pady=10)


janela.mainloop()
