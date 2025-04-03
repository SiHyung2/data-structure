#include <stdio.h>
# define MAX_SIZE 5
# include <malloc.h>


// �ڷ� ������ ����ȭ
typedef struct listType {
	int data[MAX_SIZE];  // �迭�� ����� ����Ʈ
	int length;  // ����Ʈ �Ɵ�� ����
} listType;

void linear_list_display(listType* list) {
	printf("Linear List = [");
	for (int index = 0; index < list->length; index++) {
		printf("%d", list->data[index]);
		// �ε����� �������� �ƴ϶�� ��ǥ(,)�� �ٿ���
		if (index != list->length - 1)
			printf(", ");
	}
	printf("]\n");
}

void linear_list_insert(listType* list, int pos, int item) {

	// ����Ʈ�� ������ ���
	if (list->length >= MAX_SIZE) {
		printf("List is Full!\n");
		return;
	}

	if (pos < 1 || pos > 5 || pos > list->length + 1) {
		printf("Out of range!!\n");
		return;
	}

	for (int index = list->length - 1; index >= pos - 1; index--) {
		list->data[index + 1] = list->data[index];
	}
	list->data[pos - 1] = item;
	list->length++;
}


int linear_list_delete(listType* list, int pos) {
	// ����Ʈ�� ������� ���
	if (list->length == 0) {
		printf("List is Empty!\n");
		return -1;  // ���� ����
	}

	// ���� ��ġ ����
	if (pos < 0 || pos > 5 || pos > list->length +1) {
		printf("Out of range!\n");
		return -1;  // ���� ����
	}
	int delitem = list ->data[pos - 1];
	for (int index = pos - 1; index < list->length - 1; index++) {
		list->data[index] = list->data[index + 1];
	}
	list->length--;
	return delitem;
}

void linear_list_menu(listType* list) {

	int pos = 0; // ��ġ
	int delitem; // ������
	int item = 0;

	int menu = 0;
	// �޴�ȭ
	while (1) {
		printf("Linear List 1.Insert, 2.Delete, 3.Diplay, 4.Exit\n");
		printf("Input menu : ");
		scanf_s("%d", &menu);
		if (menu == 1) {
			printf("Insert Positon : ");
			scanf_s("%d", &pos);
			printf("Insert Item : ");
			scanf_s("%d", &item);
			linear_list_insert(list, pos, item);
		}
		else if (menu == 2) {
			printf("Deletion Positon : ");
			scanf_s("%d", &pos);
			delitem = linear_list_delete(list, pos);
			if (delitem >= 0)
				printf("Delete Itme : %d\n", delitem);
		}
		else if (menu == 3) {
			linear_list_display(list);
		}
		else if (menu == 4) {
			printf("Exit\n");
			return;
		}
		else {
			printf("�߸��� �Է��Դϴ�.\n");
		}

	}
}

listType* linear_list_init(void) {
	// �ڷ� ������ �ʱ�ȭ
	listType* list = (listType*)malloc(sizeof(listType));
	list->length = 0;

	return list;
}

int main(void) {
	int* data[MAX_SIZE] = { 0 };
	int length = 0;
	// �ڷᱸ���� �ʱ�ȭ
	listType list = { data, length };
	
	// ���� �޸� �Ҵ�
	listType* list = linear_list_init();
	linear_list_menu(list);


	return 0;
}