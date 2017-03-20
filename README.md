# ProjetoNavio
 navio está dividido em 4 setores para o armazenamento de containers. Cada setor tem um espaço inicial para armazenar 4 containers, mas como é possível fazer o empilhamento deles, esse valor pode chegar ao no máximo 16 containers por setor. Dessa forma esse navio pode armazenar no máximo 64 containers.

Para fazer o carregamento do navio e necessário observar a distribuição dos pesos dos containers de forma equilibrada para que o navio não afunde. A tolerância para que o navio não afunde é que o peso máximo de um setor não pode ser maior do que 15 toneladas em relação aos pesos individuais dos outros setores. Por exemplo: se o setor III pesa no momento 30 toneladas, os demais setores devem ter o peso mínimo de 15 toneladas para que o navio não afunde. O navio afundaria se, por exemplo, o peso do setor I for de 5 toneladas e o peso do setor III for de 30 toneladas.

Exemplo:

Peso Atual do Setor 1: 15

Peso Atual do Setor 2: 5

Peso Atual do Setor 3: 17

Peso Atual do Setor 4: 12

 

Se colocar um container de 6 toneladas no setor 3 o navio afunda, em função do setor 2.

Se colocar um container de 6 toneladas no setor 2 o navio não afunda.

 

 

 

No porto no qual o navio está atracado, existe uma área de armazenagem para os containers que permite guardar no máximo 200 containers. Cada container tem o peso mínimo de 1 tonelada e o peso máximo de 15 toneladas.

Faça uma aplicação em C que primeiro receba os containers na área de armazenagem do porto. O usuário deverá informar o peso do container e esse ser guardado nessa área de armazenagem, respeitando o limite máximo de 200 containers o mínimo de 0. NÃO PODE ORDENAR OS CONTAINERS NO PORTO. Após guardar os containers na área de armazenagem, faça o carregamento no navio tendo cuidado para NÃO afundar o navio. Finalize a aplicação quando o navio estiver cheio, quando não existirem mais containers na área de armazenagem ou quando no for possível carregar novos containers no navio.

Não é necessário otimizar a carregamento do navio. Faça o carregamento da forma mais simples possível, sem ter a preocupação se o navio será carregado da melhor forma possível, ou seja, não é necessário garantir o carregamento máximo do navio ao sair do porto.
