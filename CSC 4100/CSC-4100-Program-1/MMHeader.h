/*
Ethan Newman
CSC 4100
Program 1 - Memory Manager
Memory Manager Header
Due: 3/8/2021
*/

#include <sys/mman.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>

//Allocated Space
typedef struct __mmalloc_t
{
	
	size_t size;					//Carries the Size.
	
} mmalloc_t;

//Contiguous Free Space
typedef struct __mmfree_t
{
	
	size_t size;					//Carries the Size.
	bool free;						//Flag if free or not, 1 == free, 0 == else.
	struct mmfree_t* next			//Points to next block.
	
} mmfree_t;

mmfree_t* head;

//Function Definitions
void* mem_manager_malloc(size_t size);
void mem_manager_free(void* ptr);
void locate_split(struct mmfree_t *fitting, size_t size);
//traverse the free space list starting from the head, printing out info (for debugging)
void traverse_free_list(struct mmfree_t *freeSpaceList); 
void init_mem(int free_space_size);

void* mem_manager_malloc(size_t size)
{
	struct mmfree_t *current, *previous;	
	void *result;
	
	
	
	current = head;
	
	//Check block to see if it can be used for allocation.
	while((((current->size)<size)||((current->free) == 0))&&(current->next != NULL))
	{
		previous = current;
		current = current->next;
		printf("Block Checked.\n");
	
	//Checked block refers to a chunk of memory that exactly fits the required size.
	//Else if checked block refers to a chunk of memory that is greater than what is required.
	//Else there is no sufficient memory.
		if((current->size) == size)
		{
			current->free = false;
			head->size = current->size;
			head->next = new;
			current = current->next;
			result = (void*)(current);
			printf("Exact block allocated.\n");
			return result;
		}
		else if((current->size) > (size+sizeof(struct mmfree_t)))
		{
			locate_split(current, size);
			current = current->next;
			result = (void*)(current);
			printf("Block allocated with a split.\n");
			return result;
		}
		else
		{
			result = NULL;
			printf("No sufficient memory to allocate.\n");
			return result;
		}
	}
	
}

void mem_manager_free(void* ptr)
{
	//Check if address lies within the address range
	if(((void*)memory <= ptr)&&(ptr <= (void*)(memory+4096)))
	{
		 struct mmfree_t curr = ptr;
		--curr;
}

void locate_split(struct mmfree_t *fitting, size_t size)
{
	struct mmfree_t *first_fit = (void*)((void*)fitting+size+sizeof(struct mmfree_t));
	first_fit->size = (fitting->size)-size-sizeof(struct mmfree_t);
	first_fit->free = true;
	first_fit->next = fitting->next;
	fitting->size = size;
	fitting->free = false;
	fitting->next = new;
	
	
	head->size = fitting->size;
	head->next = NULL;
}

void traverse_free_list()
{
	i = 1
	while(head->next != NULL)
	{
		printf("\nCurrent Node: ");
		printf(i);
		printf("\nPointer for Free Space List: ");
		printf(head);
		printf("\nSize of node in Free Space List: ");
		printf(head->size);
		++i;
		head = head->next;
	}
}

void init_mem(int free_space_size)
{
	head = mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_ANON|MAP_PRIVATE, -1, 0);
	head->size = 4096 - sizeof(mmfree);
	head->next = NULL;
	
	
	head->size = free_space_size-sizeof(struct mmfree_t);
	head->free = true;
	head->next = NULL;
}