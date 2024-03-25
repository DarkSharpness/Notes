# T1

Given a path $e_1,\cdots,e_m$, the probability is $\prod_{i=1}^{m}P(e_i) = \exp(\sum_{i=1}^{m}\log P(e_i))$.

Then, finding the maximum probability path is equivalent to finding the maximum sum of $\log P(e_i)$, which is equivalent to finding the minimum sum of $-\log P(e_i)$.

Due to the fact that $P \in [0,1]$, $-\log P \in [0,+\infty)$, we may turn this problem into a shortest path problem by replacing the edge weight $-\log P(e_i)$.

Specially, we define $-\log(0)$ as $+\infty$, where $+\infty + x = +\infty$ for any $x\in\mathbb{R}^+ \cup \{0\} \cup \{+\infty\}$ and $\exp(-\infty) = 0$. Also, define $x \lt +\infty$ for any $x\in\mathbb{R}$. Then, we have a well-defined order and addition operation on $[0,+\infty]$.

Then, we can apply Dijkstra's algorithm to find the shortest path from the start to the end, with the lowest sum of $-\log P(e_i)$.

By definition, for any other path from s to t, $\sum_{i=1}^{m'}-\log P({e_i}') \ge \sum_{i=1}^{m}-\log P(e_i)$. So, $\exp(\sum_{i=1}^{m'}\log P({e_i}')) \le \exp(\sum_{i=1}^{m}\log P(e_i))$, which equals: $P({e_1}')\cdots P({e_{m'}}') \le P(e_1)\cdots P(e_m)$.

That means the path found by Dijkstra's algorithm is the maximum probability path.

# T2

## a

G is shown as follows:

![1711369246922](image/HW2/1711369246922.png)

In G', there is no cycle, so the graph cannot be strongly connected.

## b

If the statement doesn't hold, then there exist an edge in $G$ , removing which $G$ will not be connected, and we call it $e_1 = (u_1,v_1)$, and $G'$ is strongly connected simultaneously.

By definition, after removing $e$, $G$ will be divided into two connected components (because at first, $G$ is connected), $V_1$ and $V_2$. 

That's because if there exist an undirected edge $e = (u,v), u\in V_1, v\in V_2, e_1 \ne e$, after removing edge $e_1$, $V_1$ and $V_2$ will still be connected by the edge $e$ , which means $G - \{e_1\}$ is still connected, which contradicts the assumption.

So, we may conclude that there's no edge in $G$ (as well as $G'$) that connects $V_1$ and $V_2$ except $e_1$.

By definition, in $G'$, $e$ may have $2$ directions:

- $(u_1,v_1)$: In this case, $u_1\in V_1, v_1\in V_2$. Then we claim that $v_1$ cannot reach $u_1$ in $G'$, because if it can, then there must be a path from $V_2$ to $V_1$ in $G'$. However, there's no edge in $G$ which connects $V_1$ and $V_2$ except $e_1$, and $e_1$ has been oriented from $V_1$ to $V_2$. So, $v_1$ cannot reach $u_1$ in $G'$.
- $(v_1,u_1)$: Similar to the above case, $u_1$ cannot reach $v_1$ in $G'$.

In short, there always exist $x,y \in G'$ , with the fact that $x$ can never reach $y$ in $G'$, which means $G'$ is not strongly connected.

This contradicts the assumption that $G'$ is strongly connected. So, the statement must holds by law of contradiction.

## c

If $G$ satisfies the property that removing any single edge from
$G$ will still give a connected graph, then we will prove that $G'$ is strongly connected, which means $\forall u,v\in V, u\ne v, \exists$ path from $u$ to $v$.

Let $V$ be the set of vertices in $G$.

Consider the relationship between $u$ and $v$ in $G'$.

### case 1: u is the ancestor of v

$u$ is the ancestor of $v$: Then there must exist a path from $u$ to $v$ in $G'$ by walking on tree-edges on dfs tree.

### case 2: v is the ancestor of u

$v$ is the ancestor of $u$: Let $w$ be the parent of $u$ in the dfs tree. By the fact that assumption that "removing $\cdots$", we may remove the edge $(w,v)$, and $G$ will still be connected. Then, there must exist a path from $v$ to $w$ in $G'$.

Consider the dfs sub-tree of $v$ (all the nodes which has $v$ as one of its ancestors, and $v$ iteself; we call it $V_1$). 

Trivially, $w \notin V_1$, so there must exist a path from $x \in V_1$ to $y \in V - V_1$ other than $(w,v)$. Then, consider the edge $(x,y)$.

- $(y,x)$ is a tree edge: $y$ is the parent of $x$. Since $x\in V_1$, $V_1$ is the dfs sub-tree of $w$, so $y \in V_1 \cup \{w\}$. Along with the fact that $y \in V - V_i$, we have $y = w, x = v$, which contradicts the assumption that $x$ and $y$ are different.Unfortunately, this edge is not $(w,v)$ due to our assumption.
- $(y,x)$ is a back edge: $x$ is ancestor of $y$. Since $x\in V_1$, $V_1$ is the dfs sub-tree of $w$, so $y \in V_1$. However, $y \in V - V_1$. So this never happens.
- $(x,y)$ is a tree edge: $x$ is the parent of $y$. Since $x\in V_1$, $V_1$ is the dfs sub-tree of $w$, so $y \in V_1$, which contradicts the fact that $y \in V - V_1$.

The only case left is that $(x,y)$ is a back edge, which means $y$ is the ancestor of $x$. In addition, $x\in V_1, y\in V - V_1$ , and $V_1$ is the dfs sub-tree of $v$. So, $y$ must also be ancestor of $v$. Since from the ancestor to the descendant, there must be a directed path on dfs tree, we have a path from $v$ to $x$ (on tree), $x$ to $y$ (back edge), and $y$ to $w$ (on tree). So, there must be a path from $v$ to $w$ in $G'$.

We may conclude that for every $(w,v)$ where $w$ is the parent of $v$ in the dfs tree, there must be a path from $v$ to $w$ in $G'$.

Connection all those paths, we may get a path from $v$ to its parent, to its parent's parent, and so on, until we reach the root of the dfs tree. We will surely reach $u$, the ancestor of $v$ somewhere on the path, since $u$ is the ancestor of $v$. So, there must be a path from $v$ to $u$ in $G'$.

### case 3: no ancestor-descendant relationship

That doesn't matter. In case 2, we find a general way to find a directed path from $v$ its parent, to its parent's parent, and so on, until we reach the root of the dfs tree.

So, for any $u,v$, we may first find a directed path from $u$ to the root, and then go down the dfs-tree to $v$. So, there must be a path from $u$ to $v$ in $G'$.

## d

We define dfs-subtree of $u$: All vertices with $u$ as it ancestor, and $u$ itself.

We propose Tarjan algorithm to find all edges in a given undirected graph such that removing any one of them will make the graph no longer connected.

The algorithm work as below:

1. Run DFS on the graph, and record the dfs number (the number that calls the dfs function; we call it dfn) of each vertex.
2. In second DFS, we record the smallest dfn (we call it low) that can be reached from the current vertex's dfs subtree within one back-edge. It is initialized as dfn, and gets updated when we are visiting a vertex $v$ from $u$:
   - If $v$ is the parent of $u$, we do not perform any update.
   - Else if $v$ is the descendant of $u$, we first dfs into $v$, and then update $low[u] = \min(low[u], low[v])$.
   - Otherwise, $v$ is the ancestor of $u$, we update $low[u] = \min(low[u], dfn[v])$.
3. Checking for each edge $(u,v)$. If $dfn[u] \lt low[v]$ or $dfn[v] \lt low[u]$, then $(u,v)$ is an edge that satisfies the property.

### Correctness

First, we prove that algorithm can really find the smallest dfn that can be reached from the current vertex's dfs subtree within one back-edge.

Suppose the dfs subtree of $u$ is $V_u$. We prove it by induction on the height of $V_u$.


#### Height = 0

When the height of $V_u$ (maximum number of tree-edges to travel from $u$ to any vertex in $V_u$) is $0$, the statement is trivially true.

That's because in this time, $V_u$ has $u$ as the only vertex, so all the vertices in $V_u$ can be reached from $u$ within one back-edge is all the nodes that $u$ can reach within one back-edge and $u$ itself.

In our algorithm, all those nodes $v$ are descendants of $u$, so we will take a min of those nodes' dfn (including $u$'s dfn, since $low[u]$ is initialized as $dfn[u]$) as the $low[u]$. So, at this time, the statement that $low[u]$ is the smallest dfn that can be reached from the current vertex's dfs subtree within one back-edge, holds true.

#### Height = k + 1

If the statement holds true when the height of $V_u$ is below $k$, then we prove that it also holds true when the height of $V_u$ is $k$. Then, for all the back-edges from $u$, we will take the min of the smallest dfn that can be reached from those.

For those nodes $v$ that are descendants of $u$, by induction hypothesis, we have find out the correct $low[v]$ for them. So, we will take the min of those $low[v]$ as the $low[u]$.

So, in our algorithm, the meaning of $low[u]$ is the minimum(which is the smallest) dfn that can be reached from $u$, or its descendants. So, the statement holds true for height $k+1$.

#### Conclusion

For all the vertices $u$, the $low[u]$ is the smallest dfn that can be reached from the current vertex's dfs subtree within one back-edge.

#### Completeness

In (b), we have proved that if removing $e = (u,v)$ ($u$ is ancestor) from $G$ will make $G$ disconnected, there doesn't exist path from $v$ to vertices that are not in its dfs sub-tree.

Consequently, there doesn't exist an ancestor of $v$ which can be reached from $v$ or its dfs sub-tree within one back-edge, so the largest dfn that can be reached from $v$ or its dfs sub-tree within one back-edge is $dfn[v]$. 

As $u$ is the ancestor of $v$, $dfn[u] \lt dfn[v] \le low[v]$.

This shows that if removing $e = (u,v)$ ($u$ is ancestor) from $G$ will make $G$ disconnected, then $dfn[u] \lt low[v]$. So our algorithm can find all the edges that satisfy the property.

Next, we're going to prove that the algorithm will not find wrong edges.

#### Soundness

In (c), we have proved that if removing $e = (u,v)$ ($u$ is ancestor) from $G$ will **NOT** make $G$ disconnected, then $v$ can reach its parent (which is $u$) in $G'$.

This means that the back-edge from $v$ and its dfs sub-tree can reach $u$ or its ancestor. So, $low[v]$ should be no less than $dfn[u]$. So, $dfn[u] \lt low[v]$ will not hold.

This show that if $dfn[u] \lt low[v]$, then removing $e = (u,v)$ ($u$ is ancestor) from $G$ will make $G$ disconnected.

#### Final Conclusion

The algorithm can find all the edges that satisfy the property, and will not find wrong edges.

### Time Complexity

This algorithm runs just like normal dfs, just including some extra operations. 

We have proved in class that the complexity of dfs is $\mathcal{O}(V+E)$.

The $low$ array is updated at most once for each vertex, which is $\mathcal{O}(V)$. The update operation happens on each edge at most twice, so the time complexity is $\mathcal{O}(E)$.

The checking of $dfn$ and $low$ for each edge $(u,v)$ is $\mathcal{O}(E)$.

So, the total time complexity is $\mathcal{O}(V+E)$.

# T3




# T6

Timing: (Thinking + Writing)

1. : $1\text{min} + 10\text{min}$
2. : $5\text{min} + 55\text{min}$
