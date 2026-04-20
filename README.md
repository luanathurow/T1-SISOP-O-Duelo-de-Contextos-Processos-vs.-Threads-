# Trabalho Sistemas Operacionais - Processos vs Threads

## 👥 Integrantes
- Luana Thurow


---

## ⏱️ Resultados

| Tipo | N | Tempo (s) | Contador |
|------|--|----------|---------|
| T1   | 2 |          |         |
| T1   | 4 |          |         |
| T1   | 8 |          |         |
| T2   | 2 |          |         |
| T2   | 4 |          |         |
| T2   | 8 |          |         |
| P1   | 2 |          |         |
| P1   | 4 |          |         |
| P1   | 8 |          |         |
| P2   | 2 |          |         |
| P2   | 4 |          |         |
| P2   | 8 |          |         |

---

## ⚠️ Análise de Corrupção

Nos experimentos T1 e P1, o contador não atingiu 1 bilhão devido a condições de corrida (race condition), onde múltiplas threads/processos acessam e modificam a variável simultaneamente.

---

## 📈 Gráfico

(inserir gráfico aqui)

---

## 📊 Conclusão

- Threads possuem menor overhead de criação
- Processos possuem maior isolamento
- Comunicação com threads é mais eficiente
- Sincronização é essencial para consistência dos dados