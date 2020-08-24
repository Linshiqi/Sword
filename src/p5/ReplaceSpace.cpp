#include "ReplaceSpace.h"

namespace code047 {
	void ReplaceSpaceBaseFromBack::replace(char* str, int length) {
		const int old_len = length;
		// Find all space, expand str to it's finnal length
		for (int i = 0; i < length; i++) {
			if (str[i] == ' ') {
				length += 2;
			}
		}

		// Replace space from back 
		char* p2 = str + length;	
		char* p1 = str + old_len;
		while (p1 >= str) {
			if (*p1 != ' ') {
				// copy back
				*p2 = *p1;
				p1--;
				p2--;
			}
			else {
				// Find a space
				*p2 = '0';
				*(p2 - 1) = '2';
				*(p2 - 2) = '%';
				p2 -= 3;
				p1--;
			}
		}
	}
}