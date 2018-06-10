#include "RBset.h"
#include "operators.h"

void clear(pset t) {
	while (t)
		t = t->erase(t->key);
}
