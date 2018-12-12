// ќграничение скорости изменени€ сигнала (Rate limiter)
// fsr - falling slew rate - максимальна€ скорость падени€ выходного сигнала 
// rsr - rising slew rate  - максимальна€ скорость нарастани€ выходного сигнала 
// Ќапример: Update(-5, 5, u);

#include "C_rate_limiter.h"


//-------------------------------------------------------------------------    
// »нициализаци€: задание параметров

    void Cratelimiter::Initialize(double in_dt, double in_ic)
    {
        dt=in_dt;        
        y_k_1=in_ic ;
        y_k=in_ic ;
        
    };

//-------------------------------------------------------------------------
// ¬ывод текущего значени€
    
    double Cratelimiter::Output() {
        return y_k;            
    };   
    
//-------------------------------------------------------------------------    
// ¬ывод текущего значени€ и выполнение нового шага вычислений
    
    double Cratelimiter::Update(double fsr, double rsr, double u) 
    {                                
        double dv = (u - y_k) / dt;
        
        if(dv > 0)
            if(dv > rsr)
                y_k = y_k_1 + rsr*dt;
            else
                y_k = u;
        else
            if(dv < fsr)
                y_k = y_k_1 + fsr*dt;
            else
                y_k = u;
              
        y_k_1=y_k;    
     
        return y_k;
    };

//-------------------------------------------------------------------------    
// «авершение вычислений
    
    void Cratelimiter::Terminate()   {                        
        
        y_k_1=0;   
        y_k=0;
          
    };
    

    

