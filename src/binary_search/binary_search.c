#include "binary_search.h"

int binary_search(int *array, int length, int value) {
	int start = 0;
	int end = length - 1;

	while (start != end) {
		int pivot = (start + end) / 2;

		if (array[pivot] == value) {
			return pivot;
		} else if (array[pivot] > value) {
			end = pivot - 1;
		} else {
			start = pivot + 1;
		}
	}

	if (array[start] == value) {
		return start;
	}

	return -1;
}

int binary_search_recursive(int *array, int start, int end, int value) {
	if (start > end) {
		start ^= end;
		end ^= start;
		start ^= end;
	}

	if (start == end) {
		if (array[start] == value) {
			return start;
		} else {
			return -1;
		}
	}

	int pivot = (start + end) / 2;

	if (array[pivot] == value) {
		return pivot;
	} else if (array[pivot] > value) {
		return binary_search_recursive(array, start, pivot - 1, value);
	} else {
		return binary_search_recursive(array, pivot + 1, end, value);
	}
}
