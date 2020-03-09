#from queue import PriorityQueue
import heapq

inf = 10000

'''
def dijkstra(source, dest, forbidden):
    if source == dest:
        return 0
    elif dest in forbidden:
        return -1
    dist = {}
    dist[source] = 0
    q = []
    heapq.heappush(q,(0,source))
    visited = set()
    while q:
        #q.sort(key=lambda vertex: dist.get(vertex,inf))
        #idx,u = min(enumerate(q), key=lambda vertex: dist.get(vertex[1],inf))
        #del q[idx]
        #u = q.pop(0)
        u = heapq.heappop(q)[1]
        if u in visited:
            continue
        visited.add(u)
        #print(u,dist.get(u,inf))
        if u == dest:
            break 
        elif dist[u] >= 10000:
            dist[dest] = -1
            break
        for v in neighbours(u):
            if v in visited or v in forbidden:
                continue
            alt = dist[u] + (1 if v not in forbidden else inf)
            if alt < dist.setdefault(v,inf):
                dist[v] = alt
            heapq.heappush(q,(dist[v],v))
    return dist.get(dest,"ERROR")
'''

def neighbours(node):
    l_p = tuple(map(lambda x: (x+1)%10, node))
    l_m = tuple(map(lambda x: (x-1)%10, node))
    
    yield (l_p[0], node[1], node[2], node[3])
    yield (l_m[0], node[1], node[2], node[3])

    yield (node[0], l_p[1], node[2], node[3])
    yield (node[0], l_m[1], node[2], node[3])

    yield (node[0], node[1], l_p[2], node[3])
    yield (node[0], node[1], l_m[2], node[3])

    yield (node[0], node[1], node[2], l_p[3])
    yield (node[0], node[1], node[2], l_m[3])
    

def dijkstra(source, dest, forbidden):
    if source == dest:
        return 0
    elif dest in forbidden:
        return -1
    dist = {}
    dist[source] = 0
    q = []
    heapq.heappush(q,(0,source))
    visited = set()
    while q:
        #q.sort(key=lambda vertex: dist.get(vertex,inf))
        #idx,u = min(enumerate(q), key=lambda vertex: dist.get(vertex[1],inf))
        #del q[idx]
        #u = q.pop(0)
        u = heapq.heappop(q)[1]
        if u in visited:
            continue
        visited.add(u)
        #print(u,dist.get(u,inf))
        if u == dest:
            break 
        for v in neighbours(u):
            if v in visited or v in forbidden:
                continue
            alt = dist[u] + 1
            if alt < dist.setdefault(v,inf):
                dist[v] = alt
            heapq.heappush(q,(dist[v],v))
    return dist.get(dest,-1)

n_cases = int(input())

input()

for case in range(n_cases):
    source = tuple(map(int,input().split()))
    dest = tuple(map(int,input().split()))

    n_forbidden = int(input())

    forbidden = set()
    for f in range(n_forbidden):
        forbidden.add(tuple(map(int,input().split())))
    try:
        input()
    except Exception as e:
        #print(e)
        pass

    print(dijkstra(source,dest,forbidden))