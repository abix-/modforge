// Address: 0x1401a1750
// Ghidra name: FUN_1401a1750
// ============ 0x1401a1750 FUN_1401a1750 (size=182) ============


longlong FUN_1401a1750(undefined8 param_1,undefined4 *param_2,undefined4 *param_3,int *param_4,

                      int param_5)



{

  int iVar1;

  longlong lVar2;

  int iVar3;

  int *piVar4;

  undefined4 uVar5;

  undefined8 uVar6;

  undefined4 uVar7;

  int local_18 [4];

  

  uVar7 = 0;

  uVar6 = 0;

  piVar4 = local_18;

  uVar5 = 8;

  iVar3 = param_5;

  lVar2 = FUN_1401a18d0();

  if (lVar2 != 0) {

    if (local_18[0] != 8) {

      iVar1 = param_5;

      if (param_5 == 0) {

        iVar1 = *param_4;

      }

      lVar2 = FUN_14019d1f0(lVar2,*param_2,*param_3,iVar1,iVar3,piVar4,uVar5,uVar6,uVar7);

    }

    if (DAT_1403fcd34 != 0) {

      if (param_5 == 0) {

        param_5 = *param_4;

      }

      FUN_1401a4d10(lVar2,*param_2,*param_3,param_5);

    }

  }

  return lVar2;

}




