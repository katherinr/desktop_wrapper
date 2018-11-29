#ifndef METEOSTRUCT_H
#define METEOSTRUCT_H
#define NPR_PACKET_TYPE_VISUAL_DATA         201
#define NPR_PACKET_TYPE_METEO_DATA          202
#define NPR_PACKET_TYPE_AIRPORT_DATA        203
#define NPR_PACKET_TYPE_CORRECT_DATA        204
#define NPR_PACKET_TYPE_BACK_DATA           205
#include <QtGlobal>

#pragma pack ( push, 1 )

struct D3_POINT
{
    double X;
    double Z;
    float  H;
    D3_POINT()
        {
            memset(this, 0, sizeof(*this));
        }
};

struct D3_ANGLE
{
    float  C;
    float  P;
    float  R;
    D3_ANGLE()
        {
            memset(this, 0, sizeof(*this));
        }
};

// ������ ������ �������� ������:

struct _MainVisualData
{
    _MainVisualData()
    {
            memset(this, 0, sizeof(*this));
    }

    unsigned char    packet_id;                              // ������������� ������� ������ (���������� ����� = 201)

    double  model_simulation_time;                  // ������� ����� � ������,                  [��]

    // ��������� ����������� � ������ ������: 0 - �����, 1 - ��� ������ ������, 2 - ��� ������� ������
    char     num_correct;

    // ��������
    D3_POINT p_coord;								// ����������:  ������ [����], ������� [����], ������ ��� ������� ����  [�]
    D3_ANGLE p_angle;                               // ������� ���������: ���� ����� (������ ������� +), �������, �����, [����]

    // ������� (����� ��� �������� ������ �������� �� ������� ������������):
    float   N2_L;                                   // ������� ������ ���������,                [0...max%]
    float   N2_R;                                   // ������� ������� ��������� ���,           [0...max%]

    // �����������, ������ ����������
    float   Flaps;                                  // ��������� ���������,                     [����]
    float   Slats;                                  // ��������� ������ �����������,            [����]
    float   Stabilizer;                             // ��������� �������������,                 [����]

    float   Elevator_L;                             // ��������� ���� ������ (���.����),        [����]
    float   Elevator_R;                             // ��������� ���� ������ (����.����),       [����]
    float   Aileron_L;                              // ��������� ������ �������,                [����]
    float   Aileron_R;                              // ��������� ������� �������,               [����]
    float   Rudder;                                 // ��������� ���� �����������,              [����]

    // ��������, ��������� ������:      ���������� ��������, �.�. ������ ����
    float   Spoiler_L_OB;                           // ��������� ������ ����. ������������,     [����]
    float   Spoiler_L_CE;                           // ��������� ������ ����. ������������,     [����]
    float   Spoiler_L_IN;                           // ��������� ������ �����. ������������,    [����]
    float   Spoiler_R_OB;                           // ��������� ������� ����. ������������,    [����]
    float   Spoiler_R_CE;                           // ��������� ������� ����. ������������,    [����]
    float   Spoiler_R_IN;                           // ��������� ������� �����. ������������,   [����]
    float   GroudSpoiler_L_OB;                      // ��������� ������ ����. ����. �����,      [����]
    float   GroudSpoiler_L_IB;                      // ��������� ������ �����. ����. �����,     [����]
    float   GroudSpoiler_R_OB;                      // ��������� ������� ����. ����. �����,     [����]
    float   GroudSpoiler_R_IB;                      // ��������� ������� �����. ����. �����,    [����]

    // ����� (���������)
    float   Gear_N;                                 // ��������� ������� �����,                 [0/1]
    float   Gear_L;                                 // ��������� ����� �����,                   [0/1]
    float   Gear_R;                                 // ��������� ������ �����,                  [0/1]

    // ���� �������� �������� ������    (������������� ���������� - ��� �������� �������)
    float   Gear_SteeringAngle;                     // ���� �������� �������� ������,           [����]

    // ���������� (��������) ����       (���� ���� �����������, ������� � % ��� ����������� �������, ���� ���, �� ���)
    char    LandingLights;                          // ���������� ����,                         [0...100%]
    char    TaxiLight;                              // �������� ����,                           [0...100%]
    char    RunwayTurnoffLights;                    // ���� �������� � ���,                     [0...100%]
    char    NavigationLightRed;                     // ������������� ����� �������,             [0...100%]
    char    NavigationLightGreen;                   // ������������� ����� �������,             [0...100%]
    char    NavigationLightWhite;                   // ������������� ����� �����,               [0...100%]
    char    AntiCollisionBeaconRed;                 // ������� ������������ ����� ������,�����, [0...100%]
    char    AntiCollisionBeaconWhite;               // ����� ������������ ����� (������, �����),[0...100%]
    char    InternalLights;			                // ��������� ������ � ������ �������,		[0...100%]

    // ��� ��������
    char    SimulationRunning;                        // ������� ����, ��� ������������� (������) ���
    char    SimulationReset;                           // ������� ����������� �������������

    // �������������� ���������� ��� ��������
    float      Alpha;                                    // ���� �����,                                 [����]
    float      Beta;                                    // ���� ����������,                            [����]
    float      wx;                                        // ������� �������� ����� � ��������� ��,     [����/�]
    float      wy;                                        // ������� �������� �������� � ��������� ��,[����/�]
    float      wz;                                        // ������� �������� ������� � ��������� ��,    [����/�]
    float      nx;                                        // ������������ ������� ���������� nx � ��������� ��, [��]
    float      ny;                                        // ������������ ������� ���������� ny � ��������� ��, [��]
    float      nz;                                        // ������������ ������� ���������� nz � ��������� ��, [��]
    float    Vx_ef;                                    // ������������ ������� �������� Vx � ������ ��, [�/�]
    float    Vy_ef;                                    // ������������ ������� �������� Vy � ������ ��, [�/�]
    float    Vz_ef;                                    // ������������ ������� �������� Vz � ������ ��, [�/�]
    float   VCAS;                                   // ��������� ��������,                      [kt] (!)
    float   VTAS;                                   // �������� ��������,                       [kt] (!)
    float   M;                                      // ����� ����
    float   RadioAltitude;                          // ����������� �� ������,                   [�]
    char    WOW_L;                                  // ����� ������: ����� ������
    char    WOW_R;                                  // ����� ������: ������ ������
    char    WOW_N;                                  // ����� ������: ������� ������
    // ������:
    float   Reserved[8];

};



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������ ������ ������ � ������ � �������:

struct _MeteoData
{
    _MeteoData()
    {
            memset(this, 0, sizeof(*this));
    }
    unsigned char    packet_id;                              // ������������� ������� ������ (���������� ����� = 202)

    double  model_simulation_time;                  // ������� ����� � ������,                  [��]

    float   visibility;                             // ���������� ��������� ���������,          [��], ��������� ����. 0...200

    short   cloudBase;                              // ������ ������ ������ ������� ��� ������� ����, [�], ������. ����. 3000.
    short   cloudUpper;                             // ������� ���� �������,                    [�], ��������� ����. 2000
    short   cloudSize ;                             // ���� �������, [��],                      [0...10]
    char    cloudsType;                         	// ��� �������:                             0- �������, 1- ��������
    char    cloudsSecondLay;                        // ������� ������� ���� ������� (�������� ������), 0/1
    float   SecLayHeight;                           // ������ ������� ���� ������� ��� ������� ����, [�], ������. ����. 15000

    short   Day;
    short   Month;
    short   Hours;
    short   Minutes;

    float   local_visibility;                       // �����. ��������� ��������� ������ ���� �����, �����, ������, [�]
    float   rain;                                   // ������������� �����,                     [0...100%]
    float   snow;                                   // ������������� �����,                     [0...100%]
    float   hmist;                                  // ������ ����� ������ ��� ������� ����,    [�], ��������� ����. 0...1000

    float   wind_speed;                             // �������� �����,                          [�/c]
    float   wind_psi;                               // ����������� ����� (������ ��� � ���������� �����), [����]

    float   starBright;                             // ������� �����,                           [0...100%]

    // ������:
    float   Reserved[8];

};



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������ ������ ������ �� ��������� � ������:


struct _AirportData
{
    _AirportData()
        {
            memset(this, 0, sizeof(*this));
        }
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

};



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������ ��������� ������ (��� �������� � ������):

struct _DataToModel
{
    _DataToModel()
    {
        memset(this, 0, sizeof(*this));
    }
    unsigned char   	packet_id;                              // ������� ������ (���������� ����� = 205)

    // ��� �������� ������ (������������ � �.�.):
    double 	simulation_time;                        // ������� �����,                           [��]

    D3_POINT p_coord;								// ������ [����], ������� [����], ������ �����. ����������� ��� �.�. �������� [�]

    // ������:
    float	Reserved[8];

};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����� ���������:
struct _CorrectData
{
    _CorrectData()
    {
        memset(this, 0, sizeof(*this));
    }

    unsigned char   message;                                                         // ������� ������ Correct = 204

    char num_correct;                                                        // ���������: 0 - �����, 1 - �����, 2 - ������
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��� �����:
struct UDP_data_t
{
    UDP_data_t()
    {
        memset(this, 0, sizeof(*this));
    }

  bool isShowingWindow;	 //
  bool showCurTraj;	//
  bool showRoute; //
  bool followMainPlane;	//	
  bool isOrientingCamera;	  //
  double centerLat;
  double centerLon;
  float centerH;
  double seconds;

  double curLat;
  double curLon;
  float curH;
  float curPsi;
  float curTheta;
  float curGamma;

  struct botAcData
  {
    bool visibility;
    double lat;
    double lon;
    float H;
    float psi;
  };

  botAcData bots[10];

  quint8 currWPT;
  int updateRoute;

  double routeLat[54];
  double routeLon[54];
  float routeAlt[54];
};

#pragma pack ( pop )

#endif
