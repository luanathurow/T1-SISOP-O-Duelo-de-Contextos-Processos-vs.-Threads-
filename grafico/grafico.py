import matplotlib.pyplot as plt

N = [2, 4, 8]

T1 = [13.464, 13.665, 13.674]
T2 = [71.511, 69.704, 66.794]
P1 = [9.440, 5.324, 4.363]
P2 = [99.784, 234.073, 177.713]

plt.plot(N, T1, marker='o', label='T1 - Threads sem sincronização')
plt.plot(N, T2, marker='o', label='T2 - Threads com mutex')
plt.plot(N, P1, marker='o', label='P1 - Processos sem sincronização')
plt.plot(N, P2, marker='o', label='P2 - Processos com semáforo')

plt.xlabel('Número de trabalhadores (N)')
plt.ylabel('Tempo de execução (segundos)')
plt.title('Gráfico de Escalabilidade')
plt.legend()
plt.grid(True)

plt.show()