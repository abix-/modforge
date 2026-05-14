// Address: 0x1401c85b0
// Ghidra name: FUN_1401c85b0
// ============ 0x1401c85b0 FUN_1401c85b0 (size=232) ============


undefined8

FUN_1401c85b0(longlong param_1,undefined8 param_2,undefined8 param_3,int param_4,longlong *param_5,

             undefined8 *param_6)



{

  char cVar1;

  undefined8 uVar2;

  longlong lVar3;

  

  cVar1 = FUN_1401ca4b0(param_2,param_3);

  if (cVar1 == '\0') {

    if (param_4 != 4) {

      if (*(char *)(param_1 + 0x98) == '\0') {

        FUN_14012e850(&DAT_14039bf30,"The provided shader code is not valid DXIL!");

        return 0;

      }

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,&DAT_14039bf30,"The provided shader code is not valid DXIL!");

    }

    if (*(char *)(param_1 + 0x98) != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,&DAT_14039bf30,"The provided shader code is not valid DXBC!");

    }

    FUN_14012e850(&DAT_14039bf30,"The provided shader code is not valid DXBC!");

LAB_1401c861a:

    uVar2 = 0;

  }

  else {

    if (param_5 != (longlong *)0x0) {

      lVar3 = FUN_1401841f0(param_3);

      *param_5 = lVar3;

      if (lVar3 == 0) goto LAB_1401c861a;

      FUN_1402f8e20(lVar3,param_2,param_3);

      *param_6 = param_3;

    }

    uVar2 = 1;

  }

  return uVar2;

}




