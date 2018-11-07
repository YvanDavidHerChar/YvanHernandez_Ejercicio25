import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import sys

datos = sys.argv[1]
mu = float(sys.argv[2])
sigma = float(sys.argv[3])
x=np.linspace(mu-3*sigma,mu+3*sigma,500)
gaus=np.exp(-(x-mu)**2/(2*sigma**2))/(sigma*(np.sqrt(2*np.pi)))
data = np.loadtxt(datos)
data = data[~np.isnan(data)]
fig1 = plt.figure()
plt.hist(data, bins=40, normed=1, facecolor='blue', alpha=0.5)
plt.plot(x,gaus)

fig1.savefig("sample.pdf")
