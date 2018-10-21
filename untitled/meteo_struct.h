#ifndef METEO_STRUCT_H
#define METEO_STRUCT_H

#include <string.h>

#define NUMBER_OF_AC_IN_TRAFFIC  10
#pragma pack ( push, 1 )
//-------------------------------------------------------------------------
// �����:

struct METEO_DATA
{
	METEO_DATA()
	{
		memset(this, 0, sizeof(*this));
	}

	char  message   ;                                                       // ������� ����������� = 11

    
    // ������� ����� �������� ������ (18 ������� ��������?)
	float Visibility;                                                       // ���������� ��������� ���������, [��], ��������� ����. 0...200                                                
	
    short CloudBase;                                                        // ������ ������ ������ ������� ��� ������� ����, [�], ��������� ����. 3000.                                                        
	short CloudUpper;                                                       // ������� ���� �������, [�], ��������� ����. 2000                                                
	short CloudSize ;                                                       // ��������� �������, [��], 0...10                                                      
	char  cloudsType;                                                       // ��� �������: 0- �������, 1- ��������
    
	char  cloudsSecondLay;                                                  // ������� ������� ���� ������� (�������� ������), 0/1                                               		                                        
	float SecLayHeight;                                                     // ������ ������� ���� ������� ��� ������� ����, [�], ��������� ����. 15000
	
    short Day;
	short Month;
	short Hours;                                                                               
	short Minutes;                                                        

    float local_visibility;                                                 // ��������� ��������� ��������� ������ ���� �����, �����, ������, [�], 500
	float rain;                                                             // ������������� �����, 0...1
	float snow;                                                             // ������������� �����, 0...1
	float hmist;                                                            // ������ ����� ������ ��� ������� ����, [�], ��������� ����. 0...1000   
	
    float wind_speed;                                                       // �������� �����, [�/c]
	float wind_psi;                                                         // ����������� ����� (������ ��� � ���������� �����), [����]

    float StarBright;                                                       // ������� �����, 0...1  ��� 0...100 
    
};

void deep_meteo_copy(METEO_DATA *_data,METEO_DATA *data );

struct _AirportData
{

    unsigned char 	packet_id;                              // ������������� ������� ������ (���������� ����� = 203)

    double  model_simulation_time;                  // ������� ����� � ������,                  [��]

    // �������� � ��� ������:
    char 	DEPARTURE_AIRPORT_CODE[4];              // ������������� ��������� ������           (4 ������� - ��� ��������� �� ICAO, �������� "LIPZ")
    char 	TAKEOFF_RUNWAY_CODE[4];                 // ������������� ������ ������              (�������� "16  ", "25L ", "01  ")
    char 	TAKEOFF_RUNWAY_BORDER_LIGHTS;           // ������� ���� ������,                     [0...100%]
    char 	DEPARTURE_AIRPORT_LIGHTS_TAXIING;       // �������� ���� ���������,                 [0...100%]
    char 	DEPARTURE_AIRPORT_LIGHTS_ILLUMINATION;  // ���� �������� ������� ���������,         [0...100%]
    char 	DEPARTURE_AIRPORT_OTHER_LIGHTS;         // ������� ������� ���� ��������� �����,    [0...100%]

    // �������� � ��� �������:
    char 	ARRIVAL_AIRPORT_CODE[4];                // ������������� ��������� �������          4 ������� - ��� ��������� �� ICAO, �������� "LIPZ")
    char 	LANDING_RUNWAY_CODE[4];                 // ������������� ������ �������             (�������� "16  ", "25R ", "01  ")
    char 	LANDING_RUNWAY_BORDER_LIGHTS;           // ������� ���� ������,                     [0...100%]
    char 	ARRIVAL_AIRPORT_LIGHTS_TAXIING;         // �������� ���� ���������,                 [0...100%]
    char 	ARRIVAL_AIRPORT_LIGHTS_ILLUMINATION;    // ���� �������� ������� ���������,         [0...100%]
    char 	ARRIVAL_AIRPORT_OTHER_LIGHTS;           // ������� ������� ���� ��������� �����,    [0...100%]

    // ������:
    char 	Reserved[16];
     _AirportData(){}

};

struct DATA_FROM_KD {

    char  message; // ������� ������ �� = 10
    double lat;
    double lon;
    double H;
    unsigned long surf;

    unsigned long time;
    float r_sign;

    double h_gear[4];

};

struct D3_POINT
{
    double X;
    double Z;
    float  H;
};

struct _DataToModel
{
    unsigned char   	packet_id;                              // ������� ������ (���������� ����� = 205)

    // ��� �������� ������ (������������ � �.�.):
    double 	simulation_time;                        // ������� �����,                           [��]

    D3_POINT p_coord;								// ������ [����], ������� [����], ������ �����. ����������� ��� �.�. �������� [�]

    // ������:
    float	Reserved[8];

};

#pragma pack ( pop )
#endif
