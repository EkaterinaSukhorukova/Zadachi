#include "RBset.h"
#include "operators.h"

RBset operator*(RBset a, RBset b) {
	pset t1(&a), t2(&b), res(NULL);
	while (t1) {
		if (t2->check(t1->key))
			res = res ? res->insert(t1->key) : new RBset(t1->key, false);
		t1 = t1->erase(t1->key);
	}
	return *res;
}
