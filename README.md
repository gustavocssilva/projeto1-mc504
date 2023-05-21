# MC504 - O Problema do Tour da UPA

##### Feito por: Gustavo Costa Salles Silva - R.A.: 198487

## Introdução do problema

O novo reitor da Unicamp no ano de 202X decide fazer uma coisa diferente esse ano para UPA, contratou uma empresa de ônibus de tour guiado para fazer uma volta pelo campus e apresentar a universidade para os visitantes.

Porém, a empresa contratada tem uma forma diferente de cobrança. Ela cobra por viagem feita. Como o reitor é ~~mão de vaca~~ economicamente responsável, ele estabeleceu algumas regras para as viagens:

1. Todas as pessoas interessadas em fazer o tour devem estar na fila assim que o horário de funcionamento começar, e não poderá entrar na fila quem chegar depois;

2. O ônibus do tour só sairá do ponto de partida quando estiver com a capacidade máxima do ônibus, e, caso o número de pessoas na fila seja menor que a capacidade, elas não poderam viajar já que o reitor não quer pagar por viagens que não estejam com a capacidade máxima.

## Implementação

O Problema do Tour da UPA é uma versão modificada do Roller Coaster Problem do The Little Book of Semaphores, que é o seguinte:

> Suponha que existam n threads de passageiros e uma thread de carro. Os passageiros repetidamente esperam para andar no carro, que comporta C passageiros, onde C < n. O carro só pode andar nos trilhos apenas quando ele estiver cheio.
> Detalhes adicionais são:
> - Passageiros devem invocar board e unboard.
> - O carro deve invocar load, run e unload.
> - Passageiros não podem subir no carro até ele ter invocado load.
> - O carro não pode partir até que C passageiros tenham embarcado.
> - Passageiros não podem desembarcar até o carro invocar unload.

A principal diferença do Problema do Tour da UPA para o Roller Coaster Problem é que a quantidade e os passageiros são definidos no começo do programa, então o onibus não fica esperando mais passageiros chegarem, apenas termina o dia.

Para implementar o os problema em C, foram usadas Threads para os passageiros e o onibus e semáforos para sinalizar os diferentes estados da viagem, como o run(), e unload(), além de usar Mutex para dar Lock no momento do passageiro subir e descer do onibus.

Mais detalhes da implementação podem ser visto nos comentários do código.