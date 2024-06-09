# Sobre o projeto

## Discentes:
- Murilo de Lima Barros
- Leonardo Pessoa Cavalcanti

## Links úteis
- Página do professor: https://agostinhobritojr.github.io/curso/progav-dca1202/escultor.html
- Repositório no Github: https://github.com/MuriloBarros304/escultor
- Documentação do programa: https://murilobarros304.github.io/minha-pag/doc-escultor/

## Modo de uso
- Crie um arquivo contendo os comandos de desenho seguindo o exemplo input.txt
- Adicione o caminho relativo do arquivo de entrada no ReadTXT
- Adicione o caminho relativo do arquivo de saída no writeOFF
- Compile e execute o projeto
- Aguarde a mensagem "Arquivo de saída salvo"
- Abra o arquivo OFF com o software de sua preferência

## Exemplo
![Modelagem de demonstração](https://github.com/MuriloBarros304/escultor/blob/main/img-geomview.png?raw-true)

## Resumo
A classe Sculptor se encarrega de criar um objeto que representa uma matriz 3D 
de um tipo estruturado Voxel com os atributos cor, transparência, e se será um 
bloco ou vazio. Toda a matriz é alocada dinamicamente no construtor da classe Sculptor.
A classe abstrata pura FiguraGeometrica possui os atributos básicos de uma figura 
e os passa por herança para todas as classes que realizam desenhos e cortes na 
matriz de voxels, os comandos de desenhos são lidos em um arquivo TXT, traduzidos 
para objetos do tipo FiguraGeometrica e têm seus endereços alocados e armazenados 
em um vetor de ponteiros, o vetor é varrido e o método draw() da classe abstrata 
é chamado para que a matriz 3D seja alterada, após isso o método writeOFF() salva
um arquivo OFF da modelagem 3D.