#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	return;
}

ListNode* insert_first(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}

ListNode* insert_last(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;
}

ListNode* delete_first(ListNode* head) {
	if (head == NULL) {
		error("List is Empty\n");
	}
	ListNode* first = head->link;

	if (first == head) {
		free(first);
		return NULL;
	}
	head->link = first->link;
	free(first);
	return head;
}

ListNode* delete_last(ListNode* head) {
	if (head == NULL) {
		error("List is Empty\n");
	}
	ListNode* pre = head->link;
	ListNode* last = head;

	if (pre == last) {
		free(last);
		return NULL;
	}
	while (pre->link != head) {
		pre = pre->link;
	}
	pre->link = head->link;
	free(last);
	head = pre;
	return head;
}

void print_list(ListNode* head) {
	ListNode* p;

	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head->link);

	printf("\n");
}

void print_menu(void) {
	printf("\nMenu\n");
	printf("(1) Insert First\n");
	printf("(2) Insert Last\n");
	printf("(3) Delete First\n");
	printf("(4) Delete Last\n");
	printf("(5) Print List\n");
	printf("(0) Exit\n");
	printf("Enter the menu: ");
}

int main() {
	ListNode* head = NULL;
	int choice, data;

	while (1) {
		print_menu();
		scanf_s("%d", &choice);

		switch (choice) {
		case 0:
			printf("Exit the program.\n");
			exit(0);

		case 1:
			printf("Input a number: ");
			scanf_s("%d", &data);
			head = insert_first(head, data);
			break;

		case 2:
			printf("Input a number: ");
			scanf_s("%d", &data);
			head = insert_last(head, data);
			break;

		case 3:
			head = delete_first(head);
			break;
		case 4:
			head = delete_last(head);
			break;
		case 5:
			print_list(head);
			break;

		default:
			printf("Invalid Menu. Please select again. \n");
			while (getchar() != '\n');
			break;
		}
	}
}