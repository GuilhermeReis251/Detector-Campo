# Projeto IoT: Sistema Passa Bola ⚽

## 👥 Integrantes
- Guilherme Guimarães dos Reis Sousa - 564226
- Leonardo Yukio Iwagoe Ribeiro - 562864
- Victor Pereira de Andrade Santos - 561548
- Paolo Rodrigues de Macedo Junior - 565898
- Vinicius Gama Quina Silva - 561617

---

## 📌 Descrição do Projeto
O **Sistema Passa Bola** é uma aplicação de **IoT (Internet das Coisas) que utiliza ESP32, Node-RED e MQTT para simular a troca de mensagens entre jogadores em um ambiente digital.

A proposta é demonstrar como a tecnologia IoT pode ser usada em cenários esportivos para comunicação, interação e simulação de estratégias**, explorando conceitos de conectividade em tempo real.

**Funcionalidades:**
-  Envio e recebimento de mensagens entre dispositivos simulados (ESP32).
-  Comunicação via protocolo **MQTT**.
-  Visualização e interação em tempo real através de **dashboard no Node-RED**.
-  Simulação 100% virtual, sem necessidade de hardware físico.

O projeto mostra como a **IoT pode ser aplicada no contexto esportivo**, criando novas formas de interação e análise dentro e fora do campo.

---

##  Arquitetura do Projeto
O projeto possui duas partes principais:

1. **Dispositivos IoT (ESP32):**
   - Simulados no Wokwi.
   - Publicam e recebem mensagens via MQTT.
   - Representam os "jogadores" no sistema Passa Bola.

2. **Dashboard (Node-RED):**
   - Recebe os dados via MQTT.
   - Exibe em tempo real as mensagens enviadas/recebidas.
   - Permite interação e simulação de estratégias.

---

##  Componentes

### IoT Devices (Dispositivos Virtuais)
- **ESP32 simulados no Wokwi**  
Função: enviar e receber mensagens representando a comunicação entre jogadores.

### Backend
- **Broker MQTT (broker.hivemq.com ou Mosquitto local)**  
Função: intermediar a comunicação entre os dispositivos e o Node-RED.

### Frontend
- **Node-RED Dashboard**  
Função: exibir em tempo real as mensagens publicadas e recebidas pelos dispositivos.

---

##  Recursos Necessários

### Software
- [Wokwi](https://wokwi.com/) (simulador online)
- [Node-RED](https://nodered.org/)
- Node.js (para rodar o Node-RED)

### Bibliotecas no Wokwi
- PubSubClient (MQTT)
- WiFi

### Hardware Virtual
- ESP32 (simulado no Wokwi)

---

##  Instruções de Uso

### 1. Wokwi
1. Abra o projeto do ESP32 no Wokwi.  
2. Copie o código `esp32-passabola.ino` para o editor.  
3. Clique em **Start Simulation** para iniciar a troca de mensagens via MQTT.  

### 2. Node-RED
1. Abra o Node-RED no navegador (`http://localhost:1880`).  
2. Vá em **Menu → Manage Palette → Install** e instale o pacote `node-red-dashboard`.  
3. Importe o fluxo do arquivo `node-red-flow.json`.  
4. Clique em **Deploy**.  
5. Acesse o dashboard em `http://localhost:1880/ui` para visualizar e interagir com o sistema Passa Bola.  