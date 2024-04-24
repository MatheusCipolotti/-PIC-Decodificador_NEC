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

<p align="center" width="100%">
  <img width="33%" src="https://github.com/MatheusCipolotti/-PIC-Decodificador_NEC/assets/102692462/f3cc7439-50b3-4830-bcba-37f4dd7631eb">
</p>
<p align="center" width="100%">
  Figura 2 - Circuito recomendado  
</p>

<p align="center" width="100%">
  <img width="33%" src="https://github.com/MatheusCipolotti/-PIC-Decodificador_NEC/assets/102692462/ba8efd98-8cb6-4a88-97c4-dcd725f17c30">
</p>
<p align="center" width="100%">
  Figura 3 - Pinout 
</p>

O resistor de 100R e o capacitor de 4,7uF são recomendados como um filtro contra espúrios indesejados.

## Aquisição do sinal
Utilizando o foto-receptor em uma protoboard, foi possível aquisitar com o circuito recomendado e um osciloscópio o sinal LIGA/DESLIGA de um controle remoto convencional.

<p align="center" width="100%">
  <img width="33%" src="https://github.com/MatheusCipolotti/-PIC-Decodificador_NEC/assets/102692462/166c9e75-f49a-483c-b402-44828d6bcb15">
</p>
<p align="center" width="100%">
  Figura 4 - Sinal completo  
</p>

<p align="center" width="100%">
  <img width="33%" src="https://github.com/MatheusCipolotti/-PIC-Decodificador_NEC/assets/102692462/b336fda1-04e9-470a-8dad-957019bd35c1">
</p>
<p align="center" width="100%">
  Figura 5 - Largura do pulso inicial
</p>

<p align="center" width="100%">
  <img width="33%" src="https://github.com/MatheusCipolotti/-PIC-Decodificador_NEC/assets/102692462/b1596099-9f33-4505-96a7-4c9f5ed31f1e">
</p>
<p align="center" width="100%">
  Figura 6 - Largura do pulso valor
</p>

<p align="center" width="100%">
  <img width="33%" src="https://github.com/MatheusCipolotti/-PIC-Decodificador_NEC/assets/102692462/9ee83a1f-4793-4567-9e94-2b3452d7fc9a">
</p>
<p align="center" width="100%">
  Figura 7 - Largura do pulso valor 1
</p>

Com os valores coletados é possível estabelecer a rotina do código para a decodificação desse sinal.

## Microcontrolador
Para essa experiência, foi utilizado o microcontrolador 16F877A, o mesmo utilizará um cristal externo de 20MHz e o código foi desenvolvido no MPLABX utilizando o compilador XC8 V2.46.
A estratégia utilizada para a captação eficiente desse sinal, foi o uso da interrupção externa do INT0 localizado no pino RB0, isso garante que a captação desse sinal seja tratada com alta prioridade pelo microcontrolador, evitando erros de pulling com o aumento do código.
O sinal decodificado é enviado via serial (UART), o sinal é convertido para USB pelo CI CH340C e recebido por qualquer computador que possua algum monitor serial instalado (por exemplo o PUTTY).

## Circuito
<p align="center" width="100%">
  <img width="33%" src="https://github.com/MatheusCipolotti/-PIC-Decodificador_NEC/assets/102692462/8696421c-e27e-4e4c-a81f-de9dc6e6b0db">
</p>

## Resultado
Abaixo é possível ver alguns códigos interpretados no PUTTY, os 3 primeiros se tratam do código LIGA/DESLIGA, os 3 últimos são o botão OK do controle remoto:
<p align="center" width="100%">
  <img width="33%" src="https://github.com/MatheusCipolotti/-PIC-Decodificador_NEC/assets/102692462/467b9fc7-26cd-4627-99a4-505570bed04a">
</p>
<p align="center" width="100%">
  Figura 8 - códigos recebidos pela serial
</p>

## Conclusão
Com essa implementação, o sinal de controles remotos de padrão NEC foi decodificado, consequentemente, com alterações nesse código, é possível obter os valores e acionar os pinos do microcontrolador, o que por sua vez pode acionar Relés, enviar mensagens específicas para um barramento SPI ou o que for necessário para aplicações que necessitem do uso de controles remotos, vale destacar que o exemplo demonstrado não está interpretando o sinal REPEAT. 




