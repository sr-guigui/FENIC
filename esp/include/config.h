#pragma once
/*
 ==========================================================================
  LeiaLab · Robô ESP32 — CONFIGURAÇÕES ATUALIZADAS
 ==========================================================================
*/
#include <Arduino.h>

constexpr const char* WIFI_SSID  = "NOME_DA_REDE_WIFI";
constexpr const char* WIFI_SENHA = "SENHA_DA_REDE_WIFI";

constexpr bool    USAR_IP_FIXO       = false;
constexpr uint8_t IP_FIXO[4]         = {192, 168, 0, 50};
constexpr uint8_t IP_GATEWAY[4]      = {192, 168, 0, 1};
constexpr uint8_t IP_MASCARA[4]      = {255, 255, 255, 0};

constexpr int PIN_EN  = 23;
constexpr int PIN_IN1 = 19;
constexpr int PIN_IN2 = 32;
constexpr int PIN_IN3 = 21;
constexpr int PIN_IN4 = 22;

constexpr int PIN_COR_S0  = 33;
constexpr int PIN_COR_S1  = 25;
constexpr int PIN_COR_S2  = 16;
constexpr int PIN_COR_S3  = 17;
constexpr int PIN_COR_OUT = 5;

constexpr int PIN_TRIG = 27;
constexpr int PIN_ECHO = 26;

constexpr int PIN_LED_R = 14;
constexpr int PIN_LED_G = 12;
constexpr int PIN_LED_B = 13;

// ==========================================================================
//  AJUSTES DE DIREÇÃO DOS MOTORES
// ==========================================================================
// Se uma roda girar ao contrário (ré quando devia ser frente), altere aqui:
constexpr bool INVERTER_MOTOR_ESQ = false;
constexpr bool INVERTER_MOTOR_DIR = false;
// Se os lados (esquerda/direita) estiverem trocados:
constexpr bool TROCAR_LADOS = false;

constexpr bool LED_ANODO_COMUM = false;

constexpr int   VELOCIDADE_REF    = 70;
constexpr float CM_POR_SEG_REF    = 22.0f;
constexpr float GRAUS_POR_SEG_REF = 200.0f;

constexpr int PWM_MINIMO = 110;
constexpr int KICK_MS    = 40;
constexpr int FREIO_MS   = 60;

constexpr int   MAX_REPETICOES   = 100;
constexpr int   MAX_PROFUNDIDADE = 8;
constexpr float MAX_CM_BLOCO     = 200.0f;
constexpr float MAX_GRAUS_BLOCO  = 720.0f;

constexpr float DISTANCIA_PADRAO_CM = 20.0f;
constexpr float DISTANCIA_MAXIMA_CM = 300.0f;

constexpr int COR_BRANCO_PADRAO[3] = {40, 40, 45};
constexpr int COR_PRETO_PADRAO[3]  = {400, 400, 420};
constexpr int COR_AMOSTRAS         = 4;
constexpr int COR_ESTABILIZA_MS    = 10;

constexpr int COR_LIMITE_PRETO   = 45;
constexpr int COR_LIMITE_BRANCO  = 120;
constexpr int COR_SATURACAO_MIN  = 25;
constexpr float HUE_VERMELHO_ATE = 25.0f;
constexpr float HUE_AMARELO_ATE  = 85.0f;
constexpr float HUE_VERDE_ATE    = 170.0f;
constexpr float HUE_AZUL_ATE     = 290.0f;
constexpr float HUE_VERMELHO_DE  = 335.0f;

constexpr unsigned long LED_ERRO_MS = 1500;
