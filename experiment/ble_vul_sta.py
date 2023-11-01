import matplotlib.pyplot as plt
import numpy as np

plt.rc('font', family='Georgia')

# data
singular = [24,15,3,0,1,3,0,3,0][::-1]
sequence = [1,1,12,21,8,6,7,0,0][::-1]
other = [0,0,0,0,0,0,0,0,10][::-1]


# label
bars = ['Bounds Check Missing','Buffer Overflow','Function Error','Specification Flaw','Access Control Flaw','Weak Configuration','Replay Mishandling','Corrupted Pointer','Other'][::-1]

y_pos = np.arange(len(bars))

fig = plt.figure(figsize=(5,2.5))
ax = fig.add_subplot(111)

# create bar
ax.barh(y_pos, singular, height=0.7,hatch='/',edgecolor='lightgrey',color='cornflowerblue', label='Singular')
ax.barh(y_pos, sequence, height=0.7,hatch='/',edgecolor='lightgrey',left=singular, color='mediumaquamarine', label='Sequence')
ax.barh(y_pos, other, height=0.7,hatch='/',edgecolor='lightgrey',left=np.add(singular, sequence), color='grey', label='Other')

# create label
ax.set_xticks(np.arange(0, 31, 5))
ax.set_yticks(y_pos, bars)

# add grids
ax.grid(axis='x', linestyle='--', linewidth=1, alpha=0.5)

# add text
# for i, v in enumerate(singular):
#     if v != 0: 
#         plt.text(v/2, i, str(v), color='black', va='center')

sin_and_seq = np.add(singular,sequence)
for i, v in enumerate(np.add(sin_and_seq,other)):
    if v != 0: 
        plt.text(v + 1, i , str(v), color='black', va='center')

# add labels
ax.set_xlabel('Number of Vulnerabilities')
# plt.ylabel('Major Category', fontweight='bold', fontsize=15)

ax2 = ax.twinx()
ax2.set_ylabel('Category')
ax2.set_yticks([])


ax.legend()
plt.tight_layout()

# save as pdf
plt.savefig('./exp/barchart.pdf')

# plt.show()