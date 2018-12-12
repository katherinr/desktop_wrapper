// Отсылка данных для приложения по сети по протоколу UDP

#ifndef udp_send_to_app_h
#define udp_send_to_app_h

#include "winsock2.h"

#include "elbird_sound_data.h"                                   
#include "math.h"      
#include "C_rate_limiter.h"    

//-------------------------------------------------------------------------

class CSendToSound {
private:
	// сохранение значений параметров с предыдущего шага
	double          N_left_prev;
	char            N_left_StopCounter;
	double          N_rght_prev;
	char            N_rght_StopCounter;

	double          Flaps_prev;
	unsigned char   Flaps_down_StopCounter;
	unsigned char   Flaps_up_StopCounter;

	double          Abrks_prev;
	unsigned char   Abrks_on_StopCounter;
	unsigned char   Abrks_off_StopCounter;

	double          LG_prev;
	unsigned char   LG_down_StopCounter;
	unsigned char   LG_up_StopCounter;

	char            LG_touchdown_nose_prev;
	char            LG_touchdown_left_prev;
	char            LG_touchdown_rght_prev;
	unsigned char   LG_touchdown_nose_RunCounter;
	unsigned char   LG_touchdown_left_RunCounter;
	unsigned char   LG_touchdown_rght_RunCounter;

	char            Play_beep_prev;
	unsigned char   Play_beep_RunCounter;

	char simulation_status_prev;

	Cratelimiter LG_ratelim;
	DATA_TO_SOUND_PLAYER m_sendPacket;

public:

	CSendToSound() // конструктор класса вызывается при создании объекта
	{ 
	}

	~CSendToSound()  // деструктор класса вызывается при уничтожении объекта
	{
	}

	//-------------------------------------------------------------------------
	// Задание параметров  
	void Initialize(double Tperiod);

	//-------------------------------------------------------------------------
	// Выполнение нового шага   
	void Update(const SOUND_FUNC_INPUT& sound_inp, const SOUND_FUNC_SETTINGS& sound_set);

	//-------------------------------------------------------------------------
	// Завершение вычислений  
	void Terminate();

	const DATA_TO_SOUND_PLAYER* getSendPacketPtr();
};

#endif
