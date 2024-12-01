# Sistema de Gestão de Pizzaria  

## Descrição  
Este projeto é um sistema interativo de gerenciamento de uma pizzaria, que permite administrar cardápios, ingredientes e vendas. O programa é escrito em C utilizando a versão **C17** e é compilado com o GNU. Ele suporta funcionalidades como CRUD de pizzas e ingredientes, venda de pizzas com cálculo dinâmico de preços, e exportação/importação de dados para arquivos.  

---

## Especificações Técnicas  

- [x] **1. Estruturas Necessárias**  
  - **Struct Pizzas**:  
    - Id (inteiro) – chave de pizza.  
    - Nome (string) — Nome da pizza.  
    - Tamanho (char) — Tamanho da pizza (P, M, G).  
    - Preço (float) — Valor base da pizza.  
    - Ingredientes (Struct Ingredientes) — Array com os ingredientes padrão da pizza.  

  - **Struct Ingredientes**:  
    - Id (inteiro) – chave ingrediente.  
    - Nome (string) — Nome do ingrediente.  
    - Preço (float) — Custo do ingrediente.  

- [ ] **2. Funcionalidades Requeridas**  
  - **CRUD de Pizzas**:  
    - Permitir ao usuário adicionar, visualizar, editar e remover pizzas do cardápio.  
  - **CRUD de Ingredientes**:  
    - Permitir ao usuário adicionar, visualizar, editar e remover ingredientes disponíveis na pizzaria.  
  - **Vender Pizza**:  
    - Permitir ao usuário registrar uma venda de pizza, com a possibilidade de:  
      - Selecionar uma pizza do cardápio.  
      - Adicionar ingredientes adicionais, além dos padrão da pizza selecionada.  
      - O preço final da pizza deve incluir o valor base mais o custo de qualquer ingrediente extra.  
  - **Exportar e Importar Dados**:  
    - Implementar funcionalidade para salvar (exportar) o cardápio de pizzas e a lista de ingredientes para um arquivo.  
    - Permitir a leitura (importação) desses dados a partir do arquivo, para carregar o cardápio e ingredientes ao reiniciar o sistema.  

- [x] **3. Estruturação do Código**  
  - Criação de arquivos header (.h) para organizar as funções CRUD de pizzas e de ingredientes. Cada header deve conter as definições das estruturas e das funções relacionadas:  
    - `pizza.h`: Definição do struct Pizza e declarações das funções CRUD para pizzas.  
    - `ingrediente.h`: Definição do struct Ingrediente e declarações das funções CRUD para ingredientes.  
  - O código fonte para as implementações das funções deve ser dividido em arquivos `.c` correspondentes:  
    - `pizza.c` — Implementa as funções CRUD para Pizza.  
    - `ingrediente.c` — Implementa as funções CRUD para Ingrediente.  
  - Um arquivo principal `main.c` deverá gerenciar o fluxo do programa e chamar as funções necessárias de cada módulo.  

- [ ] **4. Compilação com Makefile**  
  - Criação de um Makefile para facilitar a compilação do programa. O Makefile deve conter instruções para:  
    - Compilar cada arquivo `.c` em um arquivo objeto (.o).  
    - Linkar os objetos para criar o executável final (`pizzaria.exe`).  
    - Adicionar as regras:  
      - **all**: Compila o programa.  
      - **clean**: Remove arquivos objetos e o executável.  
      - **run**: Executa o programa.  

- [ ] **5. Considerações para Implementação**  
  - Cada ação do CRUD deve ser feita por meio de menus interativos.  
  - Valide os dados de entrada para evitar erros.  
  - Cada pizza deve poder ter seu próprio conjunto de ingredientes padrão.  
  - Ingredientes adicionais podem ser escolhidos durante o processo de venda, e o preço final deverá ser atualizado conforme o valor dos ingredientes adicionados.  

- [ ] **6. Critérios de Avaliação**  
  - Correção e funcionalidade completa de todas as operações CRUD.  
  - Implementação correta do cálculo de preços ao adicionar ingredientes extras.  
  - Uso eficiente das operações de exportação e importação para gerenciamento de dados.  
  - Organização do código e boas práticas de programação, incluindo o uso de funções para modularização das tarefas.  

---

## Compilação e Execução  

### Requisitos  
- **Compilador**: GCC (GNU Compiler Collection).  
- **Sistema Operacional**: Windows/Linux/Mac.  

### Makefile  
- **Comandos**  
  - `make all`: Compila o programa.  
  - `make clean`: Remove arquivos objeto e executável.  
  - `make run`: Compila e executa o programa.  

### Passos para Compilação  
1. Abra o terminal.  
2. Navegue até o diretório do projeto.  
3. Execute `make all` para compilar.  
4. Execute `make run` para rodar o programa.  

---

## Contato  
Para dúvidas ou sugestões, entre em contato com o desenvolvedor através do repositório do projeto.  
