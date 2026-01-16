
#include "linked_list.h"

int main(void)
{
    linked_list * list = create("First element");
    add(list, "Second element");
    add(list, "Third element");
    printAllElements(list);
    removeLastElement(list);
    printAllElements(list);
}
