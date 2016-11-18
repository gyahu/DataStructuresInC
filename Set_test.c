/* Tests for Set*/
#include "Set.h"

boolean test_insertion(Set s){
	int current = s->size;
	s->ops->add(5);
	int failed = s->ops->insert(5);
	boolean failed_insertion = (failed == -1);
	boolean right_amount = (current+1 == s->size);
	return (failed_insertion && right_amount);
}

boolean test_contains(Set s){
	s->ops->insert(5);
	boolean belongs = s->ops->contains(5);
	boolean not_belongs = !s->ops->contains(4);
	return (belongs && not_belongs);
}

boolean test_remove(Set s){
	for (int i = 0; i<6; i++)
		s->ops->insert(i);
	int current = s->size;
	s->ops->remove(5);
	boolean deleted = !s->ops->contains(5);
	boolean right_amount1 = (current-1 == s->size);
	s->ops->clear();
	boolean cleared = TRUE;
	for (int k = 0; k<5; k++){
		if (s->ops->contains(k))
			cleared = FALSE;
	}
	boolean right_amount2 = (s->size == 0);
	Set s2 = newSet();
	for (int i = 0; i<8; i++)
		s2->ops->add(i);
	for (int j = 5; j<15; j++)
		s->ops->add(j);
	current = s->size;
	s->ops->removeAll(s2);
	boolean right_amount3 = (current-3 == s->size);
	boolean not_belongs = !s->ops->contains(5);
	Set s3 = newSet();
	current = s->size;
	s->ops->removeAll(s3);
	boolean right_amount4 = (current == s->size);
	boolean right_amount = (right_amount1 && right_amount2 && right_amount3 && right_amount4);
	return (deleted && cleared && not_belongs && right_amount);
}

boolean test_retain(Set s){
	Set s2 = newSet();
	for (int i = 0; i<8; i++)
		s2->ops->add(i);
	for (int j = 5; j<15; j++)
		s->ops->add(j);
	s->ops->retain(s2);
	boolean right_amount1 = (s->size == 3);
	boolean not_belongs = !s->ops->contains(0);
	boolean deleted1 = !s->ops->contains(8);
	boolean belongs = s->ops->contains(5);
	Set s3 = newSet();
	s->ops->retain(s3);
	boolean right_amount2 = (s->size == 0);
	boolean deleted2 = !s->ops->contains(5);
	return (right_amount1 && right_amount2 && not_belongs && deleted1 && deleted2 && belongs);
}

void main(){
	Set s = newSet();
	boolean insertion = test_insertion(s);
	if (insertion)
		printf("Insertion test successfull\n");
	else
		printf("Insertion test failed\n");
	boolean contains = test_contains(s);
	if (contains)
		printf("Contains test successfull\n");
	else
		printf("Contains test failed\n");
	boolean remov = test_remove(s);
	if (remov)
		printf("Remove test successfull\n");
	else
		printf("Remove test failed\n");
	boolean retain = test_retain(s);
	if (retain)
		printf("Retain test successfull\n");
	else
		printf("Retain test failed\n");
	s->ops->destroy();
	if (insertion && contains && retain && retain)
		printf("All test were succesull!\n");
}

