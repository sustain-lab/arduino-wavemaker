#!/usr/bin/env python3

import matplotlib.pyplot as plt
import numpy as np

# number of samples
n = 500

# generate a sine from 0 to 2*pi, last point excluded
sine = np.sin(np.linspace(0, 2 * np.pi, n, endpoint=False))

signalA = np.array([int(round(s)) for s in 255 * (0.5 * (1 - sine))])
signalB = 255 - signalA

lt.plot(signalA, label='PWMA')
plt.plot(signalB, label='PWMB')
plt.plot(signalB - signalA, label='Output')
plt.legend()
plt.savefig('sine.png')

assert np.sum(signalB - signalA) == 0, 'Signal does not integrate to zero'

print(signalA)
