/*Tests for Array List*/
#include "ArrayList.h"

boolean test_add(ArrayList a){
	int available = a->avail;
	a->ops->add(15);
	a->ops->add(20, 16);
	int new_index = a->ops->add(20, 17);
	boolean reinserted = (new_index != -1);
	boolean right_amount = ((available-3) == a->avail);
	boolean added = ((a->ops->find(15) != -1) && (a->ops->find(16) != -1) && (a->ops->find(17) != -1));
	return (right_amount && added);
}

boolean test_contains(ArrayList a){
	a->ops->add(15);
	a->ops->add(3, 14);
	boolean contains_final = a->obs->contains(15);
	boolean contains_index = a->obs->contains(14);
	boolean not_contains = !a->obs->contains(8);
	return (contains_final && contains_index && not_contains);
}

boolean test_remove(ArrayList a){
	a->ops->add(0, 15);
	a->ops->add(1, 16);
	a->ops->add(2, 17);
	a->ops->add(3, 18);
	a->ops->add(4, 19);
	a->ops->add(5, 20);
	a->ops->add(6, 21);
	a->ops->removeByIndex(0);
	a->ops->removeByValue(21);
	boolean deleted_index = !a->ops->contains(15);
	boolean deleted_value = !a->ops->contains(21);
	a->ops->clear();
	boolean cleared = (a->avail == a->size);
	return (deleted_value && deleted_index && cleared);
}

boolean test_retrieve(ArrayList a){
	a->ops->add(0, 15);
	int retrieved = a->ops->get(0);
	return (retrieved == 15);
}

boolean test_repetitions(ArrayList a){
	int rep = 5;
	for (int i = 0; i<rep; i++)
		a->ops->add(100);
	for (int k = 0; k<20; k++)
		a->ops->add(k);
	boolean repetitions = (a->ops->repetitions(100) == 5);
	a->ops-clear();
	return repetitions;
}

boolean greaterThan(int a, int b){
	return a>b;
}

boolean lessThan(int a, int b){
	return a<b;
}

boolean test_sorting(ArrayList a){
	for (int i =0; i<100; i++)
		a->ops->add(i,i);
	a->ops->sort(greaterThan);
	boolean sorted1 = TRUE;
	for (int i = 0; i<99; i++){
		if (a->ops-get(i)<a->ops->get(i+1))
			sorted1=FALSE;
	}
	a->ops->clear();
	for (int i=0; i<100; i++)
		a->ops->add(i, 100-i);
	a->ops->sort(lessThan);
	boolean sorted2 = TRUE;
	for (int i = 0; i<99; i++){
		if (a->ops-get(i)>a->ops->get(i+1))
			sorted2=FALSE;
	}
	return (sorted1 && sorted2)
}

void main(){
	ArrayList a = newArrayList();
	/* ADD */
	boolean add = test_add(a);
	if (add)
		printf("Add test succesfull\n");
	else
		printf("Add test failed\n");
	/* CONTAINS */
	boolean contains = test_contains(a);
	if (contains)
		printf("Contains test succesfull\n");
	else
		printf("Contains test failed\n");
	/* REMOVE */
	boolean remov = test_remove(a);
	if (remov)
		printf("Remove test succesfull\n");
	else
		printf("Remove test failed\n");
	/* RETRIEBE */
	boolean retrieve - test_retrieve(a);
	if (retrieve)
		printf("Retrieve test succesfull\n");
	else
		printf("Retrieve test failed\n");
	/* REPETITIONS */
	boolean repetitions = test_repetitions(a);
	if (repetitions)
		printf("Repetitions test succesfull\n");
	else
		printf("Repetitions test failed\n");
	/* SORTING */
	boolean sorting = test_sorting(a);
	if (sorting)
		printf("Sorting test succesfull\n");
	else
		printf("Sorting test failed\n");
	a->ops->destroy();

	/* All test succesfull */
	if (add && contains && remov && retrieve && repetitions && sorting)
		printf("All test were succesull!\n");
}