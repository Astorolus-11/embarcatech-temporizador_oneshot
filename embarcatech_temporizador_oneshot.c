#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

//Pinos:
const uint led_verde = 11;
const uint led_azul = 12;
const uint led_vermelho = 13;
const uint botao_a = 5;

//Protótipos das funções:
void setup(); //Configura os pinos
void button_pressed();
int64_t turn_off_callback(alarm_id_t id, void *user_data); // Desliga os LEDs



//Variáveis globais:
bool led_ativo = false;
static volatile uint32_t last_time = 0; // variável global tipo static só pode ser acessada neste arquivo
static int counter=0;


int main()
{   
    uint32_t tempo_atual=to_us_since_boot(get_absolute_time()); //Pega o tempo absoluto e transforma em us, desde o inicio do sistema
    setup();
    stdio_init_all();

    while (true) {
        button_pressed();
        sleep_ms(10);
    }
}
void setup(){
    //Inicializa os pinos:
    gpio_init(led_verde);
    gpio_init(led_azul);
    gpio_init(led_vermelho);
    gpio_init(botao_a);
    //Define entrada/saida:
    gpio_set_dir(led_verde,GPIO_OUT);
    gpio_set_dir(led_azul,GPIO_OUT);
    gpio_set_dir(led_vermelho,GPIO_OUT);
    gpio_set_dir(botao_a,GPIO_IN);
    //Habilita o pull-up do botão A:
    gpio_pull_up(botao_a);
    
}
void button_pressed(){
   uint32_t tempo_atual = to_us_since_boot(get_absolute_time());
    if(tempo_atual-last_time>200000){ // Debounce
       
            if(gpio_get(botao_a)==0 && led_ativo==false){ // Verifica se eu pressionei o botão e se os LEDs estão desligados
                gpio_put(led_verde,true);
                gpio_put(led_azul,true);
                gpio_put(led_vermelho,true);
                add_alarm_in_ms(3000,turn_off_callback,NULL,false);// Ao pressionar o botão, com 3 segundos chama a função de callback
                led_ativo=true;
                last_time=tempo_atual;
            }
             
            

        }
}
int64_t turn_off_callback(alarm_id_t id, void *user_data){ // Desliga 1 LED

    if(counter==0){ // Desliga um LED e chama a função novamente
    gpio_put(led_verde,false);
    gpio_put(led_azul,true);
    gpio_put(led_vermelho,true);
    add_alarm_in_ms(3000,turn_off_callback,NULL,false);
    counter++;
    }

    else if(counter==1){ // Desliga dois LEDs e chama a função novamente
    gpio_put(led_verde,false);
    gpio_put(led_azul,false);
    gpio_put(led_vermelho,true);
    counter++;
    add_alarm_in_ms(3000,turn_off_callback,NULL,false);
    }

    else if(counter==2){ // Desliga os três LEDs, zera o contador e led_ativo passa a ser falso
    gpio_put(led_verde,false);
    gpio_put(led_azul,false);
    gpio_put(led_vermelho,false);
    counter=0;
    led_ativo=false;
    }
    
   return 0;
}


