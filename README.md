# **Projeto WattWalk: Sistema de Captação de Energia Cinética com Arduino**

## **Descrição do Projeto**
Este projeto tem como objetivo demonstrar um sistema que captura energia cinética gerada por passos humanos e a converte em energia elétrica utilizável. Utilizando componentes como uma célula de carga, LEDs, e um módulo Arduino Uno, criamos um protótipo funcional e escalável. O sistema é ideal para aplicações educativas ou como base para o desenvolvimento de soluções sustentáveis em ambientes de alto tráfego, como calçadas, shoppings e estádios.

Este projeto foi desenvolvido com o auxílio do **GitHub Copilot**, que auxiliou na construção do código, e das **WokWi Docs**, usadas como material de referência para a simulação do circuito.

---

## **Características Técnicas**
- **Arduino Uno**: Controlador principal responsável pelo processamento dos dados.
- **Célula de carga (HX711)**: Sensor para medir a pressão exercida por passos, gerando sinais elétricos.
- **LEDs**: Atuam como indicadores visuais para demonstrar a energia gerada.
- **Receptor IR e controle remoto**: Permitem controle remoto e flexibilidade operacional.
- **Encoder rotativo (KY-040)**: Ajusta parâmetros como sensibilidade ou modo de operação.
- **Potenciômetro**: Para calibrar a célula de carga ou ajustar limites.
- **WokWi Simulation**: Simulação completa do circuito, permitindo fácil replicação e validação.

---

## **Instruções de Uso**
### **1. Pré-requisitos**
- Arduino IDE instalado na máquina.
- Conta no [Wokwi](https://wokwi.com/) para acessar o modelo de simulação.
- Componentes físicos para montagem (opcional):
  - Arduino Uno.
  - Célula de carga com módulo HX711.
  - LEDs e resistores.
  - Potenciômetro.
  - Encoder rotativo.
  - Receptor IR e controle remoto.

### **2. Como Executar no Simulador**
1. Acesse o link do modelo simulado no Wokwi: **[Simulação do Projeto](https://wokwi.com/projects/414960452763111425)**
2. Clique em **"Start Simulation"** para iniciar o circuito.
3. Interaja com os componentes:
   - Ajuste o potenciômetro e observe as mudanças no LED.
   - Use o controle remoto para alterar modos de operação.
   - Simule pressão na célula de carga para ativar os LEDs.

### **3. Como Executar no Hardware Físico**
1. Faça o download do código fonte no arquivo `main.cpp`.
2. Conecte o Arduino Uno ao computador via cabo USB.
3. Abra o código no **Arduino IDE** e selecione a porta correta.
4. Carregue o código para o Arduino.
5. Conecte os componentes conforme o diagrama do circuito.
6. Ative o sistema e observe os LEDs indicando a energia gerada.

---

## **Requisitos**
### **Hardware**
- Arduino Uno.
- Célula de carga com módulo HX711.
- LED e resistores (220Ω).
- Potenciômetro.
- Encoder rotativo (KY-040).
- Receptor IR e controle remoto.

### **Software**
- **Arduino IDE** para carregar o código.
- **WokWi** para simulação e testes do circuito.

---

## **Código Fonte**
O código foi escrito em C++ utilizando a biblioteca padrão do Arduino para interação com sensores e atuadores. O arquivo fonte está disponível como `main.cpp`. Para detalhes do código, consulte o repositório ou o arquivo diretamente.

---

## **Simulação no WokWi**
A simulação completa do circuito está disponível no WokWi para fácil acesso e reprodução. Clique no link abaixo para acessar a simulação:
- [Link para Simulação no WokWi](https://wokwi.com/projects/414960452763111425)

---

## **Resultados Esperados**
- Demonstrar a geração de energia a partir de pressão mecânica aplicada na célula de carga.
- Oferecer uma interface interativa com controle remoto e feedback visual usando LEDs.
- Criar uma base escalável para soluções maiores em ambientes urbanos.

---

## **Licença**
Este projeto é de código aberto sob a licença MIT. Contribuições e melhorias são bem-vindas.

---

## **Agradecimentos**
- **GitHub Copilot**: Auxílio no desenvolvimento do código.
- **WokWi Docs**: Referência para a simulação e documentação técnica.

---

## **Participantes**
- **Matheus Ricardo Parreira da Silva**: RM560099.
- **Marcos Vinicius Gonçalves Santos**: RM560062.
