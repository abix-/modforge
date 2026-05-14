// Address: 0x1401d3850
// Ghidra name: FUN_1401d3850
// ============ 0x1401d3850 FUN_1401d3850 (size=130) ============


void FUN_1401d3850(double param_1,double param_2,double param_3,double param_4,float *param_5,

                  double *param_6,double *param_7)



{

  float fVar1;

  float fVar2;

  

  fVar1 = *param_5;

  fVar2 = param_5[1];

  *param_6 = (param_1 - (double)fVar1) * param_4 - (param_2 - (double)fVar2) * param_3;

  *param_7 = (param_2 - (double)fVar2) * param_4 + (param_1 - (double)fVar1) * param_3;

  *param_6 = (double)*param_5 + *param_6;

  *param_7 = (double)param_5[1] + *param_7;

  return;

}




