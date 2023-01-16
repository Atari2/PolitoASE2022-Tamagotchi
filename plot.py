from matplotlib import pyplot as plt
import numpy as np

y = np.arange(0, 32, 1)
values = [512,612,708,796,873,937,984,1013,1023,1013,984,937,873,796,708,612,512,412,316,228,151,87,40,11,1,11,40,87,151,228,316,412]
values_sub = [v - values[0] for v in values]
ex_vol = 0x47
previous_vol = [v*ex_vol/100 for v in values]
# orange is adjusted
adj_values = []
for v in values_sub:
    adj_values.append(int(v*ex_vol/100 + values[0]))
print(adj_values)
plt.plot(y, values,y, previous_vol, y, adj_values)
plt.show()