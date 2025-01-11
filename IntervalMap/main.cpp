#include "IntervalMap.h"

int main () {
	IntervalMap<int, char> imap('A');

	imap.assign(1, 5, 'B');
	imap.assign(3, 7, 'C');
	imap.assign(6, 8, 'D');
	imap.assign(4, 7, 'E');
	imap.print();

	return 0;
}