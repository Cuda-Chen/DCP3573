#include <stdio.h>
#include <stdlib.h>

struct btree
{
	int value;
	int lcount;
	int fcount;
	struct btree *left;
	struct btree *right;
};

struct btree *initNode(int value, int lcount, int fcount);
int insertTree(struct btree *tree, int num);
int *countSmaller(int *nums, int numsSize, int *returnSize);

int main()
{
	int kMod = 524287;
	int numsSize;
	scanf("%d", &numsSize);
	int temp;
	
	int *nums = (int *)malloc(numsSize * sizeof(int));
	for(int i = 0; i < numsSize; i++)
	{
		scanf("%d", &temp);
		nums[i] = temp;
	}
	int returnSize;
	int *results = countSmaller(nums, numsSize, &returnSize);
	
	int sum = 0;
	for(int i = 0; i < returnSize; i++)
	{
		//printf("results[%d] = %d\n", i, results[i]);
		sum = (sum + results[i]) % kMod;
	}
	
	printf("%d", sum);
	
	return 0;
}

struct btree *initNode(int value, int lcount, int fcount)
{
	struct btree *node;
	
	node = (struct btree *)malloc(sizeof(struct btree));
	node->value = value;
	node->lcount = lcount;
	node->fcount = fcount;
	node->left = NULL;
	node->right = NULL;
	
	return node;
}

int insertTree(struct btree *tree, int num)
{
	struct btree *p, *f, *node, *maxNode;
	maxNode = NULL;
	int count = 0;
	p = tree;
	
	while(p)
	{
		f = p;
		if(num <= (p->value))
		{
			p->lcount++;
			p = p->left;
		}
		else
		{
			maxNode = p;
			p = p->right;
		}
		
		if(p && maxNode)
		{
			p->fcount = maxNode->lcount + maxNode->fcount + 1;
		}
	}
	
	if(maxNode)
	{
		count = maxNode->lcount + maxNode->fcount + 1;
	}
	node = initNode(num, 0, count);
	
	if(num > (f->value))
	{
		f->right = node;
	}
	else
	{
		f->left = node;
	}
	
	return count;
}
int *countSmaller(int *nums, int numsSize, int *returnSize)
{
	if(numsSize == 0)
	{
		*returnSize = 0;
		return NULL;
	}
	
	struct btree *head;
	int *counts;
	int i;
	counts = (int *)malloc(numsSize * sizeof(int));
	counts[numsSize - 1] = 0;
	head = initNode(nums[numsSize - 1], 0, 0);
	for(i = numsSize - 1 - 1; i >= 0; i--)
	{
		counts[i] = insertTree(head, nums[i]);
	}
	
	*returnSize = numsSize;
	return counts;
}

