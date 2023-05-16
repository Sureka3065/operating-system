# include<stdio.h>
int main()
{
	int n=100;
	int block_size=512;
	int fcb=1;
	int ib=1;
	int cont_start=0;
	int cont_end=n-1;
	int cont_io=0;
	int linked_start=0;
	int linked_end=n-1;
	int linked_io=0;
	int indexed_io=0;
	cont_end++;
	linked_start++;
	indexed_io++;
	int mid =n/2;
	if(cont_end<mid)
	{
		cont_end++;
		cont_io++;
	}
	else
	{
		linked_start++;
		linked_io++;
	}
	indexed_io++;
	cont_end++;
	linked_end++;
	indexed_io++;
	cont_io+=(cont_end-cont_start+1);
	linked_io+=(linked_end-linked_start+1);
	indexed_io+=ib;
	printf("contiguous allocation:%d disk i/o operations\n",cont_io);
	printf("linked allocation:%d disk i/o operations\n",linked_io);
	printf("indexed allocation:%d disk i/o operations\n",indexed_io);
	return 0;
	
}
