typedef struct linked_list linked_list;

linked_list * create(char * data);

void add(linked_list * list, char * data);

void removeLastElement(linked_list * list);

void printAllElements(linked_list * list);