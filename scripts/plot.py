import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('hook.csv')
ax = df['ms'].plot(kind='hist', bins=30, edgecolor='black')
ax.set_title('demo_add latency (ms)')
ax.set_xlabel('ms')
plt.tight_layout()
plt.savefig('latency.png', dpi=160)
print('Saved latency.png')
