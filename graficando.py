import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import pandas as pd
import sys

datos = sys.argv[1]
mu = float(sys.argv[2])
sigma = float(sys.argv[3])
print(mu, sigma)
a=mu-3*sigma
b=mu+3*sigma
x=np.linspace(a,b,500)
gaus=np.exp(-(x-mu)**2/(2*sigma**2))/(sigma*(np.sqrt(2*np.pi)))
data = np.loadtxt(datos)

plt.hist(data, 50, density=True, facecolor='g', alpha=0.75)
plt.plot(x,gaus)

plt.xlabel('X')
plt.ylabel('Probability')
plt.title('Histograma de los datos generados')
plt.savefig("sample.pdf")

