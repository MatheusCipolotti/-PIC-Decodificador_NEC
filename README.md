# [PIC] Decodificador NEC
## Objetivo
Grande parte dos equipamentos eletrônicos residenciais, utilizam transmissão e recepção de dados infravermelho, nesse repositório, demonstro a construção de um receptor que decodifica e interpreta esses dados utilizando o microcontrolador PIC16F877A.
## Protocolo NEC
O protocolo NEC, define um formato padrão para a comunicação entre um transmissor (como um controle remoto) e um receptor (como um dispositivo eletrônico que está sendo controlado, por exemplo, uma TV), quando você pressiona um botão em um controle remoto, ele emite pulsos de luz infravermelha. Cada botão pressionado gera uma sequência específica de pulsos, os pulsos infravermelhos são codificados de acordo com o protocolo NEC. Este protocolo organiza os pulsos em grupos de dados que representam informações como o comando pressionado, o dispositivo alvo e verificações de erro para garantir a precisão da comunicação.
O protocolo NEC também inclui sinais de sincronização para garantir que o transmissor e o receptor estejam em sintonia. Além disso, ele permite a repetição de sinais para garantir que o comando seja recebido mesmo em condições adversas, como obstruções entre o controle remoto e o dispositivo, o dispositivo receptor, como a TV, possui um receptor infravermelho que decodifica os pulsos de acordo com o protocolo NEC. Ele então executa a ação correspondente ao comando recebido, como alterar o volume, mudar de canal ou ligar/desligar.
## TSOP1838
Este componente se trata de um circuito foto-receptor da série TSOP18XX, capaz de detectar sinais modulados em 38KHz, muito utilizado nos receptores de televisão, DVDs e outros dispositivos residenciais.

<p align="center" width="100%">
  <img width="33%" src="https://github.com/MatheusCipolotti/-PIC-Decodificador_NEC/assets/102692462/33f85461-b8a1-4235-a7d5-0b55400bbc10"> 
</p>
<p align="center" width="100%">
  Figura 1 - Foto-receptor TSOP1838  
</p>

Verificando o Datasheet, temos acesso ao pinout e o circuito recomendado:

