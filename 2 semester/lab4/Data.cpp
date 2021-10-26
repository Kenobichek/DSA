#include "Data.h"

bool operator<(const Data& first, const Data& second) {
	
	if (first.rank != second.rank) {
		return first.rank < second.rank;
	}

	if (first.amountOfExperience != second.amountOfExperience) {
		return first.amountOfExperience < second.amountOfExperience;
	}

	if (first.sizeDonut != second.sizeDonut) {
		return first.sizeDonut < second.sizeDonut;
	}

	return first.nickname < second.nickname;

}

bool operator>(const Data& first, const Data& second) {
	
	if (first.rank != second.rank) {
		return first.rank > second.rank;
	}

	if (first.amountOfExperience != second.amountOfExperience) {
		return first.amountOfExperience > second.amountOfExperience;
	}

	if (first.sizeDonut != second.sizeDonut) {
		return first.sizeDonut > second.sizeDonut;
	}

	return first.nickname > second.nickname;

}

bool operator<=(const Data& first, const Data& second) {

	if (first.rank != second.rank) {
		return first.rank < second.rank;
	}

	if (first.amountOfExperience != second.amountOfExperience) {
		return first.amountOfExperience < second.amountOfExperience;
	}

	if (first.sizeDonut != second.sizeDonut) {
		return first.sizeDonut < second.sizeDonut;
	}

	if (first.nickname != second.nickname) {
		return first.nickname < second.nickname;
	}

	if (first.nickname == second.nickname && first.rank == second.rank && first.amountOfExperience == second.amountOfExperience && first.sizeDonut == second.sizeDonut) {
		return true;
	}

	return false;
}

bool operator>=(const Data& first, const Data& second) {

	if (first.rank != second.rank) {
		return first.rank > second.rank;
	}

	if (first.amountOfExperience != second.amountOfExperience) {
		return first.amountOfExperience > second.amountOfExperience;
	}

	if (first.sizeDonut != second.sizeDonut) {
		return first.sizeDonut > second.sizeDonut;
	}

	if (first.nickname != second.nickname) {
		return first.nickname > second.nickname;
	}

	if (first.nickname == second.nickname && first.rank == second.rank && first.amountOfExperience == second.amountOfExperience && first.sizeDonut == second.sizeDonut) {
		return true;
	}

	return false;
}

bool operator==(const Data& first, const Data& second) {
	if (first.nickname == second.nickname && first.rank == second.rank && first.amountOfExperience == second.amountOfExperience && first.sizeDonut == second.sizeDonut) {
		return true;
	}
	return false;
}