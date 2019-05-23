import matplotlib.pylab as plt
import numpy as np

N=20000
datos=np.genfromtxt("datos.dat")

y=datos[:,2]
x=datos[:,1]

plt.plot(x,y)
plt.title("Trayectoria de la particula")
plt.savefig("ArenasJuan_final_15.pdf")