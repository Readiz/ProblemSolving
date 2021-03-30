#define _CRT_SECURE_NO_WARNINGS
#define MAX_LENGTH 1'000'000
#define ROOT 1
typedef struct Node
{
	int value;
	int pIdx;
}Node;
typedef struct Position
{
	int maxIndex;
	int minIndex;
}Position;
Position position[MAX_LENGTH + 1];
typedef struct priority_queue
{
	int heapsize, type;
	Node tree[MAX_LENGTH + 1];
	bool (*compare)(Node, Node);

	void init(bool (*func)(Node, Node), int _type)
	{
		heapsize = 0;
		compare = func;
		type = _type;
	}

	bool isEmpty()
	{
		return heapsize == 0;
	}

	void swap(int p, int q)
	{
		int p_pIdx = tree[p].pIdx;
		int q_pIdx = tree[q].pIdx;
		if (type)
		{
			position[p_pIdx].maxIndex = q;
			position[q_pIdx].maxIndex = p;
		}
		else
		{
			position[p_pIdx].minIndex = q;
			position[q_pIdx].minIndex = p;
		}

		Node temp = tree[p];
		tree[p] = tree[q];
		tree[q] = temp;
	}

	void update(int index)
	{
		int cur = index;
		int parent = cur >> 1;
		while (parent)
		{
			if (compare(tree[cur], tree[parent]))
			{
				swap(parent, cur);
				cur = parent;
				parent = cur >> 1;
			}
			else
				break;
		}
	}

	void downdate(int index)
	{
		int cur = index;
		int child;

		while (1)
		{
			child = cur << 1;
			if (child > heapsize) break;
			else if (child + 1 == heapsize)
			{
				if (compare(tree[child + 1], tree[child])) child++;
			}

			if (compare(tree[child], tree[cur]))
			{
				swap(cur, child);
				cur = child;
			}
			else
				break;
		}
	}

	void push(int value, int pIdx)
	{
		tree[++heapsize].value = value;
		tree[heapsize].pIdx = pIdx;
		update(heapsize);
	}

	Node pop()
	{
		swap(heapsize, ROOT);
		Node ret = tree[heapsize];
		heapsize--;
		downdate(ROOT);
		return ret;
	}

	void remove(int index)
	{
		if (!heapsize) return;
		swap(heapsize, index);
		heapsize--;
		downdate(index);
		update(index);
	}
}priority_queue;
priority_queue minHeap;
priority_queue maxHeap;

bool max(Node a, Node b) { return a.value > b.value; }
bool min(Node a, Node b) { return a.value < b.value; }
#include <stdio.h>
int main()
{
	int testcase, k, value, pIdx;
	char c[2];
	scanf("%d", &testcase);

	while (testcase--)
	{
		maxHeap.init(max, 1);
		minHeap.init(min, 0);
		pIdx = 0;
		scanf("%d", &k);
		while (k--)
		{
			scanf("%s %d", &c, &value);

			if (c[0] == 'I')
			{
				position[pIdx].maxIndex = position[pIdx].minIndex = maxHeap.heapsize + 1;
				maxHeap.push(value, pIdx);
				minHeap.push(value, pIdx);
				pIdx++;
			}
			else // D
			{
				if (!maxHeap.isEmpty())
				{
					if (value == 1)
					{
						Node v = maxHeap.pop();
						minHeap.remove(position[v.pIdx].minIndex);
					}
					else
					{
						Node v = minHeap.pop();
						maxHeap.remove(position[v.pIdx].maxIndex);
					}
				}
			}
		}
		if (maxHeap.isEmpty())
		{
			printf("EMPTY\n");
		}
		else if (maxHeap.heapsize == 1)
		{
			Node v = maxHeap.pop();
			printf("%d %d\n", v.value, v.value);
		}
		else
		{
			printf("%d %d\n", maxHeap.pop().value, minHeap.pop().value);
		}
	}
	return 0;
}