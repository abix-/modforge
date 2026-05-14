// Address: 0x1401a1810
// Ghidra name: FUN_1401a1810
// ============ 0x1401a1810 FUN_1401a1810 (size=177) ============


longlong FUN_1401a1810(undefined8 param_1,undefined4 *param_2,undefined4 *param_3,longlong param_4,

                      undefined4 param_5)



{

  longlong lVar1;

  int local_res20;

  undefined4 uVar2;

  int *piVar3;

  undefined4 uVar4;

  int local_18 [4];

  

  if (param_4 != 0) {

    piVar3 = local_18;

    uVar4 = 8;

    uVar2 = 1;

    lVar1 = FUN_1401a18d0();

    if (lVar1 != 0) {

      if ((local_res20 == 1) && (local_18[0] == 8)) {

        if (DAT_1403fcd34 != 0) {

          FUN_1401a4d10(lVar1,*param_2,*param_3,1,uVar2,piVar3,uVar4,param_4,param_5);

        }

        return lVar1;

      }

      FUN_140160120(lVar1);

    }

  }

  return 0;

}




