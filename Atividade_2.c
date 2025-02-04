#include "pico/stdlib.h"
#include <stdio.h>

// Defina os pinos do LED RGB
#define LED_RED 11
#define LED_GREEN 12
#define LED_BLUE 13

// Defina o pino do botão
#define BUTTON_PIN 10

// Variável para controlar o estado do semáforo
typedef enum {
    STATE_RED,
    STATE_YELLOW,
    STATE_GREEN
} TrafficLightState;

TrafficLightState current_state = STATE_RED;

// Função para desligar todos os LEDs
void turn_off_all_leds() {
    gpio_put(LED_RED, 0);
    gpio_put(LED_GREEN, 0);
    gpio_put(LED_BLUE, 0);
}

// Função de callback do alarme (one-shot)
int64_t alarm_callback(alarm_id_t id, void *user_data) {
    // Desliga todos os LEDs
    turn_off_all_leds();

    // Alterna o estado do semáforo
    switch (current_state) {
        case STATE_RED:
            gpio_put(LED_GREEN, 1); // Liga verde
            current_state = STATE_GREEN;
            break;
        case STATE_YELLOW:
            gpio_put(LED_RED, 1); // Liga vermelho
            current_state = STATE_RED;
            break;
        case STATE_GREEN:
            gpio_put(LED_BLUE, 1); // Liga azul (simula amarelo)
            current_state = STATE_YELLOW;
            break;
    }

    // Configura um novo alarme para 3 segundos
    add_alarm_in_ms(3000, alarm_callback, NULL, false);
    return 0; // Retorno não utilizado
}

int main() {
    // No Wokwi, a comunicação serial já está configurada automaticamente.
    // Portanto, não é necessário chamar stdio_init_all().

    // Inicializa os pinos dos LEDs como saída
    gpio_init(LED_RED);
    gpio_init(LED_GREEN);
    gpio_init(LED_BLUE);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_set_dir(LED_BLUE, GPIO_OUT);

    // Inicializa o pino do botão como entrada
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN); // Habilita o resistor de pull-up

    // Liga o LED vermelho inicialmente
    gpio_put(LED_RED, 1);

    // Variável para controlar o estado do botão
    bool button_pressed = false;

    // Loop principal
    while (1) {
        // Verifica se o botão foi pressionado
        if (gpio_get(BUTTON_PIN) == 0 && !button_pressed) {
            button_pressed = true;

            // Configura o primeiro alarme para 3 segundos
            add_alarm_in_ms(3000, alarm_callback, NULL, false);
        }

        // Aguarda 1 segundo e imprime uma mensagem
        sleep_ms(1000);
        printf("Estado atual: %d\n", current_state);
    }

    return 0;
}