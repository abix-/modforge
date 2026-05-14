// Address: 0x1402da600
// Ghidra name: FUN_1402da600
// ============ 0x1402da600 FUN_1402da600 (size=184) ============


double FUN_1402da600(double param_1)



{

  double dVar1;

  

  if (((uint)((ulonglong)param_1 >> 0x20) & 0x7ff00000) == 0x7ff00000) {

    if (((ulonglong)param_1 & 0xfffffffffffff) != 0) {

      dVar1 = (double)FUN_1402e9080(param_1);

      return dVar1;

    }

    if ((longlong)param_1 < 0) goto LAB_1402da648;

  }

  if (-1 < (longlong)param_1 || ABS(param_1) == 0.0) {

    return SQRT(param_1);

  }

LAB_1402da648:

  dVar1 = (double)FUN_1402e8e00(&DAT_140389ca0,5,0xfff8000000000000,1,8,0x21,param_1,0,1);

  return dVar1;

}




