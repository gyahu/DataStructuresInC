/*Tests for Linked List*/
#include "LinkedList.h"

boolean test_insertion(LinkedList l){
	int original_length = l->length;
	l->ops->add(5);
	boolean amount_insertion = ((original_length + 1) == l->length);
	boolean correct_value = (l->ops->find(5) != -1);
	return (amount_insertion && correct_value);
}

boolean test_extraction(LinkedList l){
	int original_length = l->length;
	l->ops->add(10);
	l->ops->add(11);
	l->ops->add(12);
	l->ops->add(14);
	l->ops->add(15);
	l->ops->add(16);
	int ext1 = l->ops->get(0);
	boolean extraction1 = (ext1 == 10);
	boolean right_amount1 = ((original_length+5) == l->length);
	int ext2 = l->ops->get(1);
	boolean extraction2 = (ext2 == 12);
	boolean right_amount2 = ((original_length+4) == l->length);
	int ext3 = l->ops->get(3);
	boolean extraction3 = (ext3 == 16);
	boolean right_amount3 = ((original_length+3) == l->length);
	int last = l->ops->getLast();
	boolean extraction4 = (last == 15);
	boolean right_amount4 = ((original_length+2) == l->length);
	int first = l->ops->getFirst();
	boolean extraction5 = (first == 11);
	boolean right_amount5 = ((original_length+1) == l->length);
	l->ops->add(10);
	l->ops->clear();
	boolean right_amount6 = (original_length == l->length);
	/* Test exceptions */
	boolean amounts = (right_amount1 && right_amount2 && right_amount3 && right_amount4 && right_amount5 && right_amount6);
	boolean extractions = (extraction1 && extraction2 && extraction3 && extraction4 && extraction5);
	return (amounts && extractions);
}

boolean test_contains(LinkedList l){
	l->ops->add(50);
	boolean belongs = l->ops->contains(50);
	boolean not_belongs = !l->ops->contains(51);
	return (belongs && not_belongs);
}

boolean test_repetitions(LinkedList l){
	int rep = 5;
	for (int i = 0; i<rep; i++)
		l->ops->add(100);
	for (int k = 0; k<20; k++)
		l->ops->add(k);
	boolean repetitions = (l->ops->repetitions(100) == 5);
	l->ops-clear();
	return repetitions;
}

void main(){
	LinkedList l=newLinkedList();
	boolean insertion = test_insertion(l);
	if (insertion)
		printf("Insertion test succesfull\n");
	else
		printf("Insertion test failed\n");
	boolean extraction = test_extraction(l);
	if (extraction)
		printf("Extraction test succesfull\n");
	else
		printf("Extraction test failed\n");
	boolean contains = test_contains(l);
	if (contains)
		printf("Contains test succesfull\n");
	else
		printf("Contains test failed\n");
	boolean repetitions = test_repetitions(l);
	if (repetitions)
		printf("Repetitions test succesfull\n");
	else
		printf("Repetitions test failed\n");
	l->ops->destroy();

	/* All test succesfull */
	if (insertion && extraction && contains && repetitions)
		printf("All test were succesfull!\n");

}