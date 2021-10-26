#include "Data.h"

bool operator<(const Data& first, const Data& second) {

	if (first.interest != second.interest) {
		return first.interest < second.interest;
	}

	if (first.utility != second.utility) {
		return first.utility < second.utility;
	}

	if (first.complexity != second.complexity) {
		return first.complexity < second.complexity;
	}

	return first.deadline < second.deadline;

}

bool operator>(const Data& first, const Data& second) {

	if (first.interest != second.interest) {
		return first.interest > second.interest;
	}

	if (first.utility != second.utility) {
		return first.utility > second.utility;
	}

	if (first.complexity != second.complexity) {
		return first.complexity > second.complexity;
	}

	return first.deadline > second.deadline;
}

bool operator==(const Data& first, const Data& second) {
	if (first.deadline == second.deadline && first.interest == second.interest && first.complexity == second.complexity && first.utility == second.utility) {
		return true;
	}
	return false;
}


bool myCompare(Data x, Data y) {
	return x > y;
}
