# Projeto utilizando LEDs com temporizador do tipo One Shot

## 1. Propósito
Esse projeto tem como propósito utilizar técnicas de debouncing e temporização, sendo mais específico o temporizador de um disparo (One Shot) no Raspberry Pi Pico W RP2040. Ele poderá ser simulado tanto
pela placa quanto pelo Wokwi integrado no vscode.


## 2. Vídeo de demonstração
https://www.dropbox.com/scl/fi/ocn3zk77ksjdm5srexbng/WhatsApp-Video-2025-02-03-at-22.47.12.mp4?rlkey=ub6k0ct7bfth7t4foa7mq5qs5&st=ed1scpix&dl=0



## 3. Funcionalidades
- A cada 3 segundos um LED é apagado quando pressionar o push button:
- 1. O LED verde será o primeiro a ser apagado;
  2. O LED azul será apagado com mais 3 segundos;
  3. O LED vermelho será apagado por ultimo;
  4. Não será possível repetir o processo até que todos os LEDs estejam apagados.


## 4. Pré-requisitos
1. Ter o [Pico SDK](https://github.com/raspberrypi/pico-sdk) instalado na máquina;
2. Ter o [ARM GNU Toolchain](https://developer.arm.com/Tools%20and%20Software/GNU%20Toolchain) instalado;
3. Ter o [Visual Studio Code](https://code.visualstudio.com/download) instalado;
4. Ter este repositório clonado na sua máquina;
5. Ter as seguintes extensões instaladas no seu VS Code para o correto funcionamento:
- [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools);
- [CMake](https://marketplace.visualstudio.com/items?itemName=twxs.cmake);
- [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools);
- [Raspberry Pi Pico](https://marketplace.visualstudio.com/items?itemName=raspberry-pi.raspberry-pi-pico);

##  5. Como executar o projeto e simular:
1. Clonar o repositório: https://github.com/Astorolus-11/embarcatech-temporizador_oneshot
2. Abrir a pasta clonada através do import project:

   ![image](https://github.com/user-attachments/assets/9ea528e1-0253-4cf8-b6c6-8532be0fc1b4)

3. Abrir o arquivo diagram.json:

   ![image](https://github.com/user-attachments/assets/028cb510-04e5-4d61-9484-523f9c3b5579)

4. Para executar na placa clique em Run que está localizada no rodapé do vscode (A placa precisa já está conectada e com o bootsel ativado):

   ![image](https://github.com/user-attachments/assets/36b14dce-1309-4f0c-a7f3-3cd7edb2b336)

  # Pronto! Já está tudo pronto para simular o projeto!


