#include <assert.h>
#include <string.h>
#include <float.h>
#include <stdio.h>
#include <math.h>
#include "../hrtf/mysofa.h"
#include "../hrtf/tools.h"
#include "tests.h"

void test_minphase() {
	struct MYSOFA_HRTF *hrtf;
	int err = 0;
	int len, i;

	hrtf = mysofa_load("tests/Pulse.sofa", &err);
	if (!hrtf) {
		CU_FAIL_FATAL("Error reading file.");
	}

	len = mysofa_minphase(hrtf, 0.01);
#ifdef VDEBUG
	printf("max length %d\n", len);
#endif
	CU_ASSERT(len==1);
	for(i=0;i<hrtf->DataIR.elements;i++)
		CU_ASSERT(fequals(hrtf->DataIR.values[i],1));
	mysofa_free(hrtf);



	hrtf = mysofa_load("share/MIT_KEMAR_normal_pinna.sofa",
			&err);
	if (!hrtf) {
		CU_FAIL_FATAL("Error reading file.");
	}

	len = mysofa_minphase(hrtf, 0.01);
#ifdef VDEBUG
	printf("max length %d\n", len);
#endif
	CU_ASSERT(len==361);
	mysofa_free(hrtf);

	hrtf = mysofa_load("share/MIT_KEMAR_normal_pinna.sofa",
				&err);
	if (!hrtf) {
		CU_FAIL_FATAL("Error reading file.");
	}

	len = mysofa_minphase(hrtf, 0.001);
#ifdef VDEBUG
	printf("max length %d\n", len);
#endif
	CU_ASSERT(len==463);
	mysofa_free(hrtf);



	hrtf = mysofa_load("share/MIT_KEMAR_normal_pinna.sofa",
			&err);
	if (!hrtf) {
		CU_FAIL_FATAL("Error reading file.");
	}
	err = mysofa_resample(hrtf, 8000.);
	CU_ASSERT_FATAL(err == MYSOFA_OK);

	len = mysofa_minphase(hrtf, 0.01);
#ifdef VDEBUG
	printf("max length %d\n", len);
#endif
	CU_ASSERT(len==70 || len==71);
	mysofa_free(hrtf);

}
