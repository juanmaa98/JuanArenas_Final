import matplotlib.pylab as plt
import numpy as np

N=20000
Barco1=[4,100]
Barco2=[10,5]
Barco3=[12,80]
Barco4=[80,50]
Barco5=[50,50]
Barco6=[40,200]

t1=73
t2=28
t3=59
t4=52
t5=39
t6=137

xin=200*np.random.random()-100
yin=200*np.random.random()-100
vsin=1000
tlin=10

xcam=np.zeros([])
ycam=np.zeros([])
vscam=np.zeros([])
tlcam=np.zeros([])

xcam=np.append(xin)
ycam=np.append(yin)
vscam=np.append(vsin)
tlcam=np.append(tlin)

for i in range(N):
	xnuevo=np.random.normal(xcam[i],0.1)
	ynuevo=np.random.normal(ycam[i],0.1)
	vscam=np.random.normal(vscam[i],0.1)
	tlcam=np.random.normal(tlcam[i],0.1)
	



print("coordenada x:",x,"+/-",dx)
print("coordenada y:",y,"+/-",dy)
print("tiempo de lanzamiento:",tl,"+/-",dtl)
print("velocidad del sonido:",vs,"+/-",dvs)