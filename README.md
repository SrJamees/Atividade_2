# Semáforo com Raspberry Pi Pico W

Este projeto implementa um sistema de semáforo usando um Raspberry Pi Pico W. O sistema é controlado por um botão que inicia a temporização dos LEDs (vermelho, amarelo e verde) com um atraso de 3 segundos entre cada estado. O código foi desenvolvido para ser executado no simulador Wokwi e também em hardware físico.

## 🚦 Funcionalidades

- **Temporização automática**: Os LEDs mudam de estado a cada 3 segundos.
- **Controle por botão**: O sistema é ativado por um botão (pushbutton).
- **Simulação no Wokwi**: O código é compatível com o simulador Wokwi para testes rápidos.
- **Uso do LED RGB**: Utiliza um LED RGB para simular as cores do semáforo.

## 🛠️ Componentes Necessários

- **Raspberry Pi Pico W**
- **LED RGB** (ou 3 LEDs: vermelho, amarelo e verde)
- **Resistores de 330 Ω** (para os LEDs)
- **Botão (Pushbutton)**
- **Jumpers e protoboard** (para conexões)

## 📋 Diagrama do Circuito

O circuito pode ser simulado no Wokwi usando o seguinte diagrama:

```json
{
  "version": 1,
  "author": "James",
  "editor": "wokwi",
  "parts": [
    {
      "type": "wokwi-pi-pico",
      "id": "pico",
      "top": 20,
      "left": 60,
      "attrs": { "env": "arduino-community" }
    },
    {
      "type": "wokwi-led",
      "id": "led1",
      "top": 3,
      "left": 0,
      "attrs": { "color": "red" }
    },
    {
      "type": "wokwi-led",
      "id": "led2",
      "top": 48,
      "left": 0,
      "attrs": { "color": "green" }
    },
    {
      "type": "wokwi-led",
      "id": "led3",
      "top": 98,
      "left": 0,
      "attrs": { "color": "blue" }
    },
    {
      "type": "wokwi-resistor",
      "id": "r1",
      "top": 10,
      "left": 50,
      "attrs": { "value": "330" }
    },
    {
      "type": "wokwi-resistor",
      "id": "r2",
      "top": 55,
      "left": 50,
      "attrs": { "value": "330" }
    },
    {
      "type": "wokwi-resistor",
      "id": "r3",
      "top": 105,
      "left": 50,
      "attrs": { "value": "330" }
    },
    {
      "type": "wokwi-pushbutton",
      "id": "button",
      "top": 150,
      "left": 0,
      "attrs": { "color": "gray" }
    }
  ],
  "connections": [
    [ "pico:GND", "led1:C", "black", [] ],
    [ "pico:GP11", "r1:1", "blue", [] ],
    [ "r1:2", "led1:A", "blue", [] ],
    [ "pico:GND", "led2:C", "black", [] ],
    [ "pico:GP12", "r2:1", "blue", [] ],
    [ "r2:2", "led2:A", "blue", [] ],
    [ "pico:GND", "led3:C", "black", [] ],
    [ "pico:GP13", "r3:1", "blue", [] ],
    [ "r3:2", "led3:A", "blue", [] ],
    [ "pico:GP10", "button:1.l", "green", [] ],
    [ "button:1.r", "pico:GND", "black", [] ],
    [ "$serialMonitor:RX", "pico:GP0", "", [] ]
  ]
}
