# Escultor 3D em C++

## Discentes
- Murilo de Lima Barros
- Leonardo Pessoa Cavalcanti

## Links Úteis
- [Página do professor](https://agostinhobritojr.github.io/curso/progav-dca1202/escultor.html)
- [Documentação do programa](https://murilobarros304.github.io/minha-pag/doc-escultor/)

## Sobre o Projeto
O projeto **Escultor** é uma aplicação orientada a objetos em C++ que permite desenhar e modelar figuras geométricas 3D em uma matriz de blocos (Voxels). Através do polimorfismo, comandos para criar esferas, caixas, elipsoides ou remover essas mesmas formas (cortes) são aplicados dinamicamente na matriz e em seguida exportados para arquivos no formato `.off`.

### Novas Funcionalidades
- **Modo Interativo**: Agora você pode editar, criar e cortar formas em tempo real digitando pelo próprio terminal, linha por linha!
- **Preview Automático no Geomview**: Ao dar vida à matriz (utilizando a instrução `dim nx ny nz` no modo interativo), o sistema vai gerar o `interativo.off` automaticamente e abrir a visualização em tempo real do Geomview em plano de fundo.
- **Argumentos de CLI**: Suporte a parâmetros via terminal (flags).
- **Comando `salvar`**: Salve seu progresso quando quiser com `salvar nome_do_arquivo` pelo modo interativo.

## Como compilar usando o CMake (Linux)

Para manter sua pasta principal limpa e evitar conflitos entre binários e código fonte, utilizaremos o diretório `build`:

1. Instale o CMake pelo seu gerenciador de pacotes (exemplo com Debian/Ubuntu):
   ```bash
   sudo apt update
   sudo apt install cmake
   ```
2. Abra o terminal na pasta raiz do seu projeto e crie o diretório de compilação:
   ```bash
   mkdir build
   cd build
   ```
3. Mande o CMake gerar os arquivos de configuração (o `..` refere-se à pasta anterior):
   ```bash
   cmake ..
   ```
4. Finalmente, compile o seu executável:
   ```bash
   make
   ```

## Modo de Uso

O arquivo executável `./escultor` foi gerado. Você tem agora três modos de execução:

### 1. Modo Interativo em Tempo Real
```bash
./escultor -i
```
O prompt interativo será iniciado. Comece digitando as dimensões `dim nx ny nz`. 
O visualizador `geomview` vai aparecer pra você poder ver as modificações! Use o comando especial `salvar meu_modelo` no terminal para criar a cópia final.

### 2. Leitura de um arquivo TXT customizado
```bash
./escultor caminho/para/meu_arquivo.txt
```
O software irá ler rapidamente o arquivo informado e salvar o modelo automaticamente como `output.off`.

### 3. Modo Padrão
```bash
./escultor
```
A aplicação simplesmente irá buscar e interpretar as instruções que estiverem escritas num arquivo chamado `input.txt` em seu diretório de compilação.

## Demonstração
Aqui está uma escultura modelada utilizando o sistema e visualizada dentro do Geomview:

![Escultura de demonstração criada com o software](https://github.com/MuriloBarros304/escultor/blob/main/img-geomview.png?raw=true)
