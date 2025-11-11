import matplotlib.pyplot as plt
import numpy as np

def read_data(filename):
    n = []
    areas = []
    with open(filename, 'r') as f:
        for line in f:
            parts = line.strip().split('\t')
            n.append(int(parts[0]))
            areas.append(float(parts[1]))
    return n, areas

n_wide, areas_wide = read_data('wide_area.txt')
n_narrow, areas_narrow = read_data('narrow_area.txt')

exact_area = 0.25 * np.pi + 1.25 * np.arcsin(0.8) - 1

plt.figure(figsize=(15, 5))

plt.subplot(1, 2, 1)
plt.plot(n_wide, areas_wide, 'b-', label='Широкая область', alpha=0.7, linewidth=1.5)
plt.plot(n_narrow, areas_narrow, 'r-', label='Узкая область', alpha=0.7, linewidth=1.5)
plt.axhline(y=exact_area, color='green', linestyle='--', linewidth=2, label=f'Точная площадь = {exact_area:.6f}')
plt.xlabel('Количество точек')
plt.ylabel('Приближенная площадь')
plt.title('Зависимость приближенной площади от количества точек')
plt.legend()
plt.grid(True, alpha=0.3)

plt.subplot(1, 2, 2)

relative_error_wide = [abs(area - exact_area) / exact_area * 100 for area in areas_wide]
relative_error_narrow = [abs(area - exact_area) / exact_area * 100 for area in areas_narrow]

plt.plot(n_wide, relative_error_wide, 'b-', label='Широкая область', alpha=0.7, linewidth=1.5)
plt.plot(n_narrow, relative_error_narrow, 'r-', label='Узкая область', alpha=0.7, linewidth=1.5)
plt.xlabel('Количество точек')
plt.ylabel('Относительное отклонение (%)')
plt.title('Зависимость относительного отклонения от количества точек')
plt.legend()
plt.grid(True, alpha=0.3)

plt.tight_layout()
plt.show()
