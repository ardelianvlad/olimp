"""
Алгоритм Дейкстри
"""


def dijkstra(V:set, w:dict, a):
	"""
	Рахує найменьш вартісний шлях від вершини а до всіх їнших.
	V - множина вершин графа
	w - вага ребра
	Повертає список d найменш вартісних шляхів та список p самих цих шляхів
	"""
	U = set()
	d = {i:float('inf') for i in V}
	p = {i:[] for i in V}
	d[a] = 0
	p[a] = [0]
	for _ in range(len(V)):
		v = float('inf')
		for i in V - U:
			if d[i] < v:
				v = i
		U.add(v)
		for u in V:
			if u not in U and (v, u) in w:
				if d[u] > d[v] + w[(v, u)]:
					d[u] = d[v] + w[(v, u)]
					p[u] = p[v] + [u]			
	return d, p


def printer(d, p):
	"""Виводить результати"""
	for i in range(len(d)):
		print(a, '->', i, '=', d[i], '\tpath =', p[i])



if __name__ == '__main__':
	a = 0
	V = set(range(6))
	E = [(0, 1), (0, 2), (0, 7), (1, 3), (1, 2), (2, 5), (2, 3)]
	E += [x[::-1] for x in E] 
	w = dict(zip(E, [7, 9, 14, 15, 10, 2, 11] * 2))
	del E
	printer(*dijkstra(V, w, a))
