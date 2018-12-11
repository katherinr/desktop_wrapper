// ������ � ������

#pragma once

#pragma pack ( push, 1 )

// ��������� ��� �������� ������ ��� ��������� ��������������� �����
struct DATA_TO_SOUND_PLAYER{

    // �����, ��� - ��������������� ���������� � ������ ������
    double model_simulation_time;   
    
    // �������� �����
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

// ��������� ������� ���������� ��� ������� �������� ������ �� ����
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

// ��������� ��� �������� �������� � ������� �������� ������ �� ����
struct SOUND_FUNC_SETTINGS{

    unsigned char shutdown_counter;  // ������� ��� �������� ������ �� ���������� ������������ ��������� �����
    
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
