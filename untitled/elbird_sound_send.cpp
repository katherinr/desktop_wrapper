// ������ ������������ ������ ��� SoundPlayer � �� �������� ��� ����������� �������� �� SoundPlayer �� UDP

#include "elbird_sound_send.h"

//-------------------------------------------------------------------------
// �������������: ����� ���������� � 0
void CSendToSound::Initialize(double Tperiod)
{
    // ��������� ��������:
    N_left_prev             = 0;
    N_left_StopCounter      = 0;
    N_rght_prev             = 0;
    N_rght_StopCounter      = 0;
    
    Flaps_prev              = 0;
    Flaps_down_StopCounter  = 0; 
    Flaps_up_StopCounter    = 0; 
    
    Abrks_prev              = 0;
    Abrks_on_StopCounter    = 0; 
    Abrks_off_StopCounter   = 0;
    
    LG_prev                 = 0;
    LG_down_StopCounter     = 0; 
    LG_up_StopCounter       = 0;
    
    LG_touchdown_nose_prev  = 0;
    LG_touchdown_left_prev  = 0;
    LG_touchdown_rght_prev  = 0;
    LG_touchdown_nose_RunCounter = 0;
    LG_touchdown_left_RunCounter = 0;
    LG_touchdown_rght_RunCounter = 0;
    
    Play_beep_prev          = 0;
    Play_beep_RunCounter    = 0;
    
    // ��� ����� - ����������� ���� �� ������ � �� ������
    LG_ratelim.Initialize(Tperiod, 0); 
    
	m_sendPacket = { 0 };
};


//-------------------------------------------------------------------------
// ����� �������� �������� � ���������� ������ ���� ����������
// ����������� ������ �� �������� �� UDP
void CSendToSound::Update(const SOUND_FUNC_INPUT& sound_inp, const SOUND_FUNC_SETTINGS& sound_set )
{
    // ������� ������
    char simulation_status          = sound_inp.simulation_status;
    double model_time               = sound_inp.model_time;
    double N_left_curr              = sound_inp.N_left_curr;
    double N_rght_curr              = sound_inp.N_rght_curr;
    double Flaps_curr               = sound_inp.Flaps_curr;
    double Abrks_curr               = sound_inp.Abrks_curr;
    char   LG_curr                  = sound_inp.LG_curr;
    char   LG_touchdown_nose        = sound_inp.LG_touchdown_nose;
    char   LG_touchdown_left        = sound_inp.LG_touchdown_left;
    char   LG_touchdown_rght        = sound_inp.LG_touchdown_rght;
    char   Play_beep                = sound_inp.beep;
    
    // ��������� ��������� � �.�.
    double loudness_idle            = (sound_set.loudness_idle)/100;
    double loudness_max             = (sound_set.loudness_max)/100;
    unsigned char loudness_flaps    = (unsigned char)sound_set.loudness_flaps;
    unsigned char loudness_abrks    = (unsigned char)sound_set.loudness_abrks;  
    unsigned char loudness_lg       = (unsigned char)sound_set.loudness_lg;          
    double ratelim_lg_lower         = sound_set.ratelim_lg_lower;      
    double ratelim_lg_upper         = sound_set.ratelim_lg_upper;  
    unsigned char loudness_touchdown_n   = (unsigned char)sound_set.loudness_touchdown_n;  
    unsigned char loudness_touchdown_l_r = (unsigned char)sound_set.loudness_touchdown_l_r;  
    unsigned char loudness_beep     = (unsigned char)sound_set.loudness_beep; 
    // ������� ��� �������� � ���� ����������� ������ (255) ��� ����������
    unsigned char shutdown_counter  = sound_set.shutdown_counter;         
    
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // ��������� �������� �������� ������ ���������:
    int in_loop = 1;

    if (N_left_curr<  0.)       {N_left_curr=  0.;}
    // ��� ��������� ������������� - ���������� ���� ������
    if (simulation_status<1)    {N_left_curr=  0.;}
    
    // ������� ����������� ��������: +100  
    double sndval_n_l_idle = 0.;
    double sndval_n_l_max  = 0.;
    
    if (N_left_curr>0.5)
    {
        if (N_left_curr>100.) {N_left_curr=100.;}
        
        sndval_n_l_idle = (100.-N_left_curr);
        sndval_n_l_max  = (     N_left_curr);
        
        if (sndval_n_l_idle>0.5) 
        { 
            sndval_n_l_idle = sndval_n_l_idle*loudness_idle; 
            if (sndval_n_l_idle<1.) {sndval_n_l_idle=1.;}
            sndval_n_l_idle = sndval_n_l_idle + 100.*(double)in_loop; 
        }
        else                     
        { 
            sndval_n_l_idle = 255; 
        }
        
        sndval_n_l_max = sndval_n_l_max*loudness_max;
        if (sndval_n_l_max<1.) {sndval_n_l_max=1.;}
        sndval_n_l_max = sndval_n_l_max+100.*((double)(in_loop));
    }

    // ���� ����������� ������, ����� �������� ��������� ����������� �������� 255, ��� ����� �������:
    if (N_left_curr<0.5 && N_left_prev>0) { N_left_StopCounter = shutdown_counter;}
    
    // �������� ������� ��������� ��������� ��� (�� ��������) ��� ����������:
    if (N_left_StopCounter>0)
    {   
        sndval_n_l_idle = 255;  
        sndval_n_l_max  = 255;
        N_left_StopCounter = N_left_StopCounter-1;
    } 
    
    // ���������� �������� ��� ��������� �� ��������� ����
    N_left_prev = N_left_curr;
    
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // ��������� �������� �������� ������� ���������:

    if (N_rght_curr<  0.)       {N_rght_curr=  0.;}
    // ��� ��������� ������������� - ���������� ���� ������
    if (simulation_status<1)    {N_rght_curr=  0.;}
    
    // ������� ����������� ��������: +100  
    double sndval_n_r_idle = 0.;
    double sndval_n_r_max  = 0.;
    
    if (N_rght_curr>0.5)
    {
        if (N_rght_curr>100.) {N_rght_curr=100.;}
        
        sndval_n_r_idle = (100.-N_rght_curr);
        sndval_n_r_max  = (     N_rght_curr);
        
        if (sndval_n_r_idle>0.5) 
        { 
            sndval_n_r_idle = sndval_n_r_idle*loudness_idle; 
            if (sndval_n_r_idle<1.) {sndval_n_r_idle=1.;}
            sndval_n_r_idle = sndval_n_r_idle + 100.*(double)in_loop; 
        }
        else                     
        { sndval_n_r_idle = 255; }
        
        sndval_n_r_max = sndval_n_r_max*loudness_max;
        if (sndval_n_r_max<1.) {sndval_n_r_max=1.;}
        sndval_n_r_max = sndval_n_r_max+100.*((double)(in_loop));
    }

    // ���� ����������� ������, ����� �������� ��������� ����������� �������� 255, ��� ����� �������:
    if (N_rght_curr<0.5 && N_rght_prev>0) { N_rght_StopCounter = shutdown_counter;}
    
    // �������� ������� ��������� ��������� ��� (�� ��������) ��� ����������:
    if (N_rght_StopCounter>0)
    {   
        sndval_n_r_idle = 255;  
        sndval_n_r_max  = 255;
        N_rght_StopCounter = N_rght_StopCounter-1;
    } 
    
    // ���������� �������� ��� ��������� �� ��������� ����
    N_rght_prev = N_rght_curr;
    
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // ��������� �������� ��������� ���������:
        
    unsigned char sndval_flaps_down=0;
    unsigned char sndval_flaps_up  =0;
    
    if (Flaps_curr>Flaps_prev  &&  simulation_status>0)
    { sndval_flaps_down = loudness_flaps+100; } // ������ ��������� (100), ����������� ������ (+100)
    if (Flaps_curr<Flaps_prev  &&  simulation_status>0)
    { sndval_flaps_up   = loudness_flaps+100; } // ������ ��������� (100), ����������� ������ (+100)
    
    // ���� ����������� ������, ����� �������� ��������� ����������� �������� 255, ��� ����� �������:
    if ( fabs(Flaps_curr - Flaps_prev)<1e-8  ||  Flaps_curr<Flaps_prev || simulation_status<simulation_status_prev) 
    { 
        Flaps_down_StopCounter = shutdown_counter;
    }   
    
    if ( fabs(Flaps_curr - Flaps_prev)<1e-8  ||  Flaps_curr>Flaps_prev || simulation_status<simulation_status_prev) 
    {         
        Flaps_up_StopCounter   = shutdown_counter;
    }
    
    // �������� ������� ��������� ��������� ��� (�� ��������) ��� ����������:
    if (Flaps_down_StopCounter>0)
    {   
        sndval_flaps_down  = 255;  
        Flaps_down_StopCounter = Flaps_down_StopCounter-1;
    } 
    if (Flaps_up_StopCounter>0)
    {   
        sndval_flaps_up  = 255;  
        Flaps_up_StopCounter = Flaps_up_StopCounter-1;
    } 
    
    Flaps_prev = Flaps_curr;
    
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // ��������� �������� ��������� ��:
        
    unsigned char sndval_abrks_on=0;
    unsigned char sndval_abrks_off  =0;
    
    if (Abrks_curr>Abrks_prev  &&  simulation_status>0)
    { sndval_abrks_on   = loudness_abrks+100; } // ������ ��������� (100), ����������� ������ (+100)
    if (Abrks_curr<Abrks_prev  &&  simulation_status>0)
    { sndval_abrks_off  = loudness_abrks+100; } // ������ ��������� (100), ����������� ������ (+100)
    
    // ���� ����������� ������, ����� �������� ��������� ����������� �������� 255, ��� ����� �������:
    if ( fabs(Abrks_curr - Abrks_prev)<1e-8  ||  Abrks_curr<Abrks_prev || simulation_status<simulation_status_prev) 
    { 
        Abrks_on_StopCounter = shutdown_counter;
    }   
    
    if ( fabs(Abrks_curr - Abrks_prev)<1e-8  ||  Abrks_curr>Abrks_prev || simulation_status<simulation_status_prev) 
    {         
        Abrks_off_StopCounter   = shutdown_counter;
    }
    
    // �������� ������� ��������� ��������� ��� (�� ��������) ��� ����������:
    if (Abrks_on_StopCounter>0)
    {   
        sndval_abrks_on  = 255;  
        Abrks_on_StopCounter = Abrks_on_StopCounter-1;
    } 
    if (Abrks_off_StopCounter>0)
    {   
        sndval_abrks_off  = 255;  
        Abrks_off_StopCounter = Abrks_off_StopCounter-1;
    } 
    
    Abrks_prev = Abrks_curr;
    
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // ��������� �������� ��������� ����� (����������� �������):
        
    // ����� ������������ ������������ �������� ���� �����,
    // ��� ��� �� ������ �������� ������ ��������� ����� 0/1
    double LG_ltd=LG_ratelim.Update(ratelim_lg_lower, ratelim_lg_upper, (double)LG_curr); 
    
    unsigned char sndval_lg_down=0;
    unsigned char sndval_lg_up  =0;
    
    if (LG_ltd>LG_prev  &&  simulation_status>0)
    { sndval_lg_down   = loudness_lg+100; } // ������ ��������� (100), ����������� ������ (+100)
    if (LG_ltd<LG_prev  &&  simulation_status>0)
    { sndval_lg_up     = loudness_lg+100; } // ������ ��������� (100), ����������� ������ (+100)
    
    // ���� ����������� ������, ����� �������� ��������� ����������� �������� 255, ��� ����� �������:
    if ( fabs(LG_ltd - LG_prev)<1e-8  ||  LG_ltd<LG_prev || simulation_status<simulation_status_prev) 
    { 
        LG_down_StopCounter = shutdown_counter;
    }   
    
    if ( fabs(LG_ltd - LG_prev)<1e-8  ||  LG_ltd>LG_prev || simulation_status<simulation_status_prev) 
    {         
        LG_up_StopCounter   = shutdown_counter;
    }
    
    // �������� ������� ��������� ��������� ��� (�� ��������) ��� ����������:
    if (LG_down_StopCounter>0)
    {   
        sndval_lg_down  = 255;  
        LG_down_StopCounter = LG_down_StopCounter-1;
    } 
    if (LG_up_StopCounter>0)
    {   
        sndval_lg_up  = 255;  
        LG_up_StopCounter = LG_up_StopCounter-1;
    } 
    
    LG_prev = LG_ltd;
    
    //    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //    ��������� �������� ��������� ����� (������������� �������):

    //     unsigned char sndval_lg_down=0;
    //     unsigned char sndval_lg_up  =0;
    // 
    //     if (LG_curr>LG_prev)
    //     { sndval_lg_down   = 100; } // ������ ��������� (100)
    //     if (LG_curr<LG_prev)
    //     { sndval_lg_up  = 100; }    // ������ ��������� (100)
    // 
    //     LG_prev = LG_curr;

    
    
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // ��������� ��������� ������� �������, �����, ������ ������:
    // �������� - ������� ��� �������������� ���������, ��� ��� ����� �������

    unsigned char sndval_touchdown_nose=0;
    
    if (LG_touchdown_nose>LG_touchdown_nose_prev  &&  simulation_status>0)
    { LG_touchdown_nose_RunCounter = shutdown_counter; }    

    // ��� ���������� ������ �� ������ ������������ ���������� ��������� ���:
    if (LG_touchdown_nose_RunCounter>0)
    { 
        sndval_touchdown_nose = loudness_touchdown_n; 
        LG_touchdown_nose_RunCounter = LG_touchdown_nose_RunCounter - 1;
    }
    
    LG_touchdown_nose_prev = LG_touchdown_nose;
    
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
    
    unsigned char sndval_touchdown_left=0;
    
    if (LG_touchdown_left>LG_touchdown_left_prev  &&  simulation_status>0)
    { LG_touchdown_left_RunCounter = shutdown_counter; }    
    
    // ��� ���������� ������ �� ������ ������������ ���������� ��������� ���:
    if (LG_touchdown_left_RunCounter>0)
    { 
        sndval_touchdown_left = loudness_touchdown_l_r; 
        LG_touchdown_left_RunCounter = LG_touchdown_left_RunCounter - 1;
    }
    
    LG_touchdown_left_prev = LG_touchdown_left;
    
    
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
    unsigned char sndval_touchdown_rght=0;
    
    if (LG_touchdown_rght>LG_touchdown_rght_prev  &&  simulation_status>0)
    { LG_touchdown_rght_RunCounter = shutdown_counter; }    

    // ��� ���������� ������ �� ������ ������������ ���������� ��������� ���:
    if (LG_touchdown_rght_RunCounter>0)
    { 
        sndval_touchdown_rght = loudness_touchdown_l_r; 
        LG_touchdown_rght_RunCounter = LG_touchdown_rght_RunCounter - 1;
    }
    
    LG_touchdown_rght_prev = LG_touchdown_rght;

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // ��������� �������� "���":
    // �������� - ������ ��� �������������� ���������, ��� ��� ���� �������

    unsigned char sndval_beep=0;
    
    if (Play_beep>Play_beep_prev  &&  simulation_status>0)
    { Play_beep_RunCounter = shutdown_counter; }    

    // ��� ���������� ������ �� ������ ������������ ���������� ��������� ���:
    if (Play_beep_RunCounter>0)
    { 
        sndval_beep = loudness_beep; 
        Play_beep_RunCounter = Play_beep_RunCounter - 1;
    }
    
    Play_beep_prev = Play_beep;
    
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
    
    simulation_status_prev=simulation_status;
    
    // ���������� ������ ��� �������� �� ����:
    m_sendPacket.model_simulation_time      = model_time;
    m_sendPacket.engine_noise_min_l         = (unsigned char)(sndval_n_l_idle);
    m_sendPacket.engine_noise_max_l         = (unsigned char)(sndval_n_l_max);
    m_sendPacket.engine_noise_min_r         = (unsigned char)(sndval_n_r_idle);
    m_sendPacket.engine_noise_max_r         = (unsigned char)(sndval_n_r_max);
    m_sendPacket.sound_flaps_down           = (unsigned char)(sndval_flaps_down);
    m_sendPacket.sound_flaps_up             = (unsigned char)(sndval_flaps_up);
    m_sendPacket.sound_airbrakes_on         = (unsigned char)(sndval_abrks_on);
    m_sendPacket.sound_airbrakes_off        = (unsigned char)(sndval_abrks_off);
    m_sendPacket.sound_landing_gear_down    = (unsigned char)(sndval_lg_down);
    m_sendPacket.sound_landing_gear_up      = (unsigned char)(sndval_lg_up);
    m_sendPacket.sound_touchdown_nose       = (unsigned char)(sndval_touchdown_nose);
    m_sendPacket.sound_touchdown_left       = (unsigned char)(sndval_touchdown_left);
    m_sendPacket.sound_touchdown_rght       = (unsigned char)(sndval_touchdown_rght);
    m_sendPacket.sound_beep                 = (unsigned char)(sndval_beep);
};

// ���������� ��������� �� ����� ��� �������� �� SoundPlayer
// ����� ����������� � CSendToSound::Update
const DATA_TO_SOUND_PLAYER* CSendToSound::getSendPacketPtr()
{
	return &m_sendPacket;
}

//-------------------------------------------------------------------------
// ���������� ����������
void CSendToSound::Terminate()   {  
    LG_ratelim.Terminate(); 
	m_sendPacket = {0}; 
}






