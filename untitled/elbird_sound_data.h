// работа с звуком

#pragma once

#pragma pack ( push, 1 )

// структура для отправки данных для программы воспроизведения звука
struct DATA_TO_SOUND_PLAYER{

    // время, сек - вспомогательная информация в начале пакета
    double model_simulation_time;   
    
    // основная часть
    char engine_noise_min_l;
    char engine_noise_max_l;
    char engine_noise_min_r;
    char engine_noise_max_r;
    char sound_flaps_down;
    char sound_flaps_up;
    char sound_airbrakes_on;
    char sound_airbrakes_off;
    char sound_landing_gear_down;
    char sound_landing_gear_up;
    char sound_touchdown_nose;
    char sound_touchdown_left;
    char sound_touchdown_rght;
    char sound_beep;
    
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// структура входных аргументов для функции отправки данных на звук
// (char simulation_status, double model_time, double N_left_curr, double N_rght_curr, double Flaps_curr,  double Abrks_curr, double LG_curr,
struct SOUND_FUNC_INPUT{

    char simulation_status;                                        
    
    double model_time;
    double N_left_curr;
    double N_rght_curr;
    double Flaps_curr;
    double Abrks_curr;
    char LG_curr;
    char LG_touchdown_nose;
    char LG_touchdown_left;
    char LG_touchdown_rght;
    char beep;
    
    
};

// структура для передачи настроек в функцию отправки данных на звук
struct SOUND_FUNC_SETTINGS{

    unsigned char shutdown_counter;  // сколько раз отсылать сигнал на завершение проигрывания звукового файла
    
    double loudness_idle;
    double loudness_max;
    double loudness_flaps;
    double loudness_abrks;
    double loudness_lg;
    double ratelim_lg_lower;
    double ratelim_lg_upper;
    double loudness_touchdown_l_r;
    double loudness_touchdown_n;
    double loudness_beep;
    
};

#pragma pack ( pop )
