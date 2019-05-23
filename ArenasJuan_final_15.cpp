#include<iostream>
#include<fstream>
using namespace std;

float m=7294.29;
int q=2;

int vder(float t, float x, float y,float Ex,float Ey,float vx,float vy,float& ax,float& ay){
    ax=q*Ex/m;
    ay=q*Ey/m;
}


int main(){
    float dt=0.1;
    float x0=1;
    float y0=0;
    float v0x=0;
    float v0y=1;
    int N=(10-0)/dt+1;
    
    float x[N]={0};
    float y[N]={0};
    float vx[N]={0};
    float vy[N]={0};
    float t[N]={0};
    
    float Ex[N]={0};
    float Ey[N]={0};
    
    x[0]=x0;
    y[0]=y0;
    vx[0]=v0x;
    vy[0]=v0y;
    
    for(int i=0;i<N;i++){
        t[i]=i*dt;
        
        if(t[i]<7&&t[i]>=3){
            Ex[i]=0;
            Ey[i]=3;
        }
    }
    
    for(int i=1;i<N;i++){
        float ax=0;
        float ay=0;
        
        vder(t[i-1], x[i-1], y[i-1],Ex[i-1],Ey[i-1],vx[i-1],vy[i-1],ax,ay);
        
        float k1vx=dt*ax;
        float k1vy=dt*ay;
        float k1x=dt*vx[i-1];
        float k1y=dt*vy[i-1];
        
        vder(t[i-1]+dt*0.5, x[i-1]+k1x*0.5, y[i-1]+k1y*0.5,Ex[i-1],Ey[i-1],vx[i-1]+k1vx*0.5,vy[i-1]+k1vy*0.5,ax,ay);
        
        float k2vx=dt*ax;
        float k2vy=dt*ay;
        float k2x=dt*(vx[i-1]+0.5*k1vx);
        float k2y=dt*vy[i-1]+0.5*k1vy;
        
        vder(t[i-1]+dt*0.5, x[i-1]+k2x*0.5, y[i-1]+k2y*0.5,Ex[i-1],Ey[i-1],vx[i-1]+k2vx*0.5,vy[i-1]+k2vy*0.5,ax,ay);
        
        float k3vx=dt*ax;
        float k3vy=dt*ay;
        float k3x=dt*(vx[i-1]+0.5*k2vx);
        float k3y=dt*vy[i-1]+0.5*k2vy;
        
        vder(t[i-1]+dt,x[i-1]+k3x, y[i-1]+k3y,Ex[i-1],Ey[i-1],vx[i-1]+k3vx,vy[i-1]+k3vy,ax,ay);
        
        float k4vx=dt*ax;
        float k4vy=dt*ay;
        float k4x=dt*(vx[i-1]+0.5*k3vx);
        float k4y=dt*vy[i-1]+0.5*k3vy;
        
        float ktvx=(1.0/6.0)*(k1vx+2*k2vx+2*k3vx+k4vx);
        float ktvy=(1.0/6.0)*(k1vy+2*k2vy+2*k3vy+k4vy);
        float ktx=(1.0/6.0)*(k1x+2*k2x+2*k3x+k4x);
        float kty=(1.0/6.0)*(k1y+2*k2y+2*k3y+k4y);
        
        vx[i]=vx[i-1]+ktvx;
        vy[i]=vy[i-1]+ktvy;
        x[i]=x[i-1]+ktx;
        y[i]=y[i-1]+kty;
    }
    
    ofstream outfile;
    outfile.open("datos.dat");
    for(int i=0;i<N;i++){
        outfile<<t[i]<<" "<<x[i]<<" "<<y[i]<<endl;        
    }
    outfile.close();
    return 0;
}