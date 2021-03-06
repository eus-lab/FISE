#include "instsim.h"

void op_addfd(uint32_t reg1, uint32_t reg2, uint32_t reg3)
{
	uint32_t cc = CurrentCore;
	longdouble  d1, d2, d3;
	/* RH850Ì{¸x®¬_ðCÌ{¸x®¬_ÉÏ·*/
	d1.twolong32.tw = Context[cc].reg[reg1];  d1.twolong32.bw = Context[cc].reg[reg1 + 1];
	d2.twolong32.tw = Context[cc].reg[reg2];  d2.twolong32.bw = Context[cc].reg[reg2 + 1];
	/* CÌ{¸x®¬_ÅÌÁZ*/
	d3.d64 = d1.d64 + d2.d64;
	/* CÌ{¸x®¬_ðRH850Ì{¸x®¬_ÉÏ· */
	Context[cc].reg[reg3] = d3.twolong32.tw; Context[cc].reg[reg3 + 1] = d3.twolong32.bw;

#ifdef DELAY
	Context[cc].delay += delay_addfd * TargetClock;
#endif
}


void op_subfd(uint32_t reg1, uint32_t reg2, uint32_t reg3)
{
	uint32_t cc = CurrentCore;
	longdouble  d1, d2, d3;
	/* RH850Ì{¸x®¬_ðCÌ{¸x®¬_ÉÏ·*/
	d1.twolong32.tw = Context[cc].reg[reg1];  d1.twolong32.bw = Context[cc].reg[reg1 + 1];
	d2.twolong32.tw = Context[cc].reg[reg2];  d2.twolong32.bw = Context[cc].reg[reg2 + 1];
	/* CÌ{¸x®¬_ÅÌ¸Z*/
	d3.d64 = d2.d64 - d1.d64;
	/* CÌ{¸x®¬_ðRH850Ì{¸x®¬_ÉÏ· */
	Context[cc].reg[reg3] = d3.twolong32.tw; Context[cc].reg[reg3 + 1] = d3.twolong32.bw;

#ifdef DELAY
	Context[cc].delay += delay_subfd * TargetClock;
#endif
}
