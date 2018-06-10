#include "RBset.h"
#include "operators.h"

RBset operator+(RBset a, RBset b) {
	pset res(&a), t(&b);
	while (t) {
		if (!res->check(t->key))
			res = res->insert(t->key);
		t = t->erase(t->key);
	}
	return *res;
}
