// Address: 0x1401ca910
// Ghidra name: FUN_1401ca910
// ============ 0x1401ca910 FUN_1401ca910 (size=161) ============


longlong *

FUN_1401ca910(longlong param_1,longlong param_2,undefined4 param_3,undefined4 param_4,char param_5,

             undefined4 param_6)



{

  int iVar1;

  longlong *plVar2;

  

  plVar2 = (longlong *)FUN_1401c9f20(param_2,param_3,param_4);

  if ((*(char *)(param_2 + 0x40) != '\0') && (param_5 != '\0')) {

    iVar1 = FUN_140138fe0(*plVar2 + 0x48);

    if (0 < iVar1) {

      FUN_1401c9400(*(undefined8 *)(param_1 + 0x110),param_2);

      plVar2 = (longlong *)FUN_1401c9f20(param_2,param_3,param_4);

    }

  }

  FUN_1401cb470(param_1,param_6,plVar2);

  return plVar2;

}




