from matplotlib import pyplot as plt
import numpy as np

values = [512, 583, 653, 719, 783, 840, 891, 935, 971, 998, 1015, 1023, 1020, 1008, 985, 954, 914, 866, 811, 751, 686, 618, 547, 475, 404, 337, 271, 211, 156, 108, 68, 37, 14, 2, 0, 7, 24, 51, 87, 131, 182, 241, 303, 370, 440]
y = np.arange(0, len(values), 1)
values_sub = [v - values[0] for v in values]
ex_vol = 0x47
previous_vol = [v*ex_vol/100 for v in values]
# orange is adjusted
adj_values = []
for v in values_sub:
    adj_values.append(int(v*ex_vol/100 + values[0]))
print(adj_values)
plt.plot(y, values, label='100% volume')
plt.plot(y, adj_values, label='71% volume')
plt.legend()
plt.show()