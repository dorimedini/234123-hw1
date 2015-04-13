#ifndef _C_TEST_UTILS
#define _C_TEST_UTILS

#include <stdio.h>
#include <string.h>

// Defines the width of the output.
// This must always be an odd number (see start() and end())
#define OUTPUT_WIDTH 31

// Print a row of "=" signs
#define PRINTFILLROW() do { \
		int i; \
		for (i=0; i< OUTPUT_WIDTH; i++) { \
			printf("="); \
		} \
		printf("\n"); \
	} while(0)

// If a test fails, call this
#define FAIL(reason) do { \
		printf("%s", __func__); \
		int i; \
		for (i=0; i<OUTPUT_WIDTH - strlen(__func__) - 6; i++) { \
			printf("."); \
		} \
		printf("FAILED\n\t%s\n", reason); \
		return; \
	} while(0)

// If test is successful, call this to return to main()
#define SUCCESS() do { \
		printf("%s", __func__); \
		int i; \
		for (i=0; i<OUTPUT_WIDTH - strlen(__func__) - 2; i++) { \
			printf("."); \
		} \
		printf("OK\n"); \
		return; \
	} while(0)

// For use in tests
#define ASSERT(exp) do { \
		if (!(exp)) { \
			FAIL(#exp); \
		} \
	} while(0)
	
	
/**
 * A pair of pretty printing functions
 */
inline void start() {
	PRINTFILLROW();
	int i;
	for (i=0; i< (OUTPUT_WIDTH-13)/2; i++) {
		printf("=");
	}
	printf(" START TESTS ");
	for (i=0; i< (OUTPUT_WIDTH-13)/2; i++) {
		printf("=");
	}
	PRINTFILLROW();
}
inline void end() {
	PRINTFILLROW();
	int i;
	for (i=0; i< (OUTPUT_WIDTH-11)/2; i++) {
		printf("=");
	}
	printf(" END TESTS ");
	for (i=0; i< (OUTPUT_WIDTH-11)/2; i++) {
		printf("=");
	}
	printf("\n");
	PRINTFILLROW();
}

#endif
