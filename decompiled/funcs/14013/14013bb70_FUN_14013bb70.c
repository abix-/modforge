// Address: 0x14013bb70
// Ghidra name: FUN_14013bb70
// ============ 0x14013bb70 FUN_14013bb70 (size=522) ============


undefined4 FUN_14013bb70(int *param_1,longlong param_2)



{

  int iVar1;

  undefined4 uVar2;

  int iVar3;

  longlong lVar4;

  ulonglong uVar5;

  ulonglong uVar6;

  ulonglong uVar7;

  undefined8 in_stack_ffffffffffffff68;

  undefined8 uVar8;

  int local_88 [32];

  

  uVar2 = (undefined4)((ulonglong)in_stack_ffffffffffffff68 >> 0x20);

  if (param_2 < 1) {

    uVar6 = 0;

  }

  else {

    lVar4 = FUN_140149300();

    uVar6 = lVar4 + param_2;

  }

  iVar1 = FUN_140138fe0(&DAT_1403fb690);

  if (iVar1 == 0) {

    FUN_14013b080(1);

  }

  uVar8 = CONCAT44(uVar2,0xffff);

  iVar1 = FUN_14013adf0(param_1,1,2,0,uVar8,param_2 == 0);

  uVar2 = (undefined4)((ulonglong)uVar8 >> 0x20);

  if (iVar1 < 0) goto LAB_14013bd5a;

  if (param_2 == 0) {

    if (param_1 == (int *)0x0) {

      uVar8 = CONCAT44(uVar2,0xffff);

      iVar3 = FUN_14013adf0(local_88,1,1,0,uVar8,1);

      uVar2 = (undefined4)((ulonglong)uVar8 >> 0x20);

      if ((iVar3 == 0) || (local_88[0] != 0x7f00)) goto LAB_14013bc11;

      FUN_14013adf0(local_88,1,2,0x7f00,CONCAT44(uVar2,0x7f00),1);

    }

    else if (*param_1 != 0x7f00) goto LAB_14013bc11;

LAB_14013bd5a:

    uVar2 = 0;

  }

  else {

LAB_14013bc11:

    if (iVar1 == 0) {

      if (param_2 == 0) goto LAB_14013bd5a;

      lVar4 = FUN_14016dcf0();

      if ((((lVar4 != 0) && (*(longlong *)(lVar4 + 0x240) != 0)) &&

          (*(longlong *)(lVar4 + 0x248) != 0)) && (lVar4 = FUN_14013bf90(lVar4), lVar4 != 0)) {

        lVar4 = param_2;

        iVar1 = FUN_14013bd80();

        uVar2 = (undefined4)((ulonglong)lVar4 >> 0x20);

        if (0 < iVar1) goto LAB_14013bcf6;

        if (iVar1 == 0) goto LAB_14013bd5a;

      }

      FUN_14013b080(1);

      uVar8 = CONCAT44(uVar2,0xffff);

      iVar1 = FUN_14013afe0(param_1,1,2,0,uVar8);

      while (iVar1 < 1) {

        uVar2 = (undefined4)((ulonglong)uVar8 >> 0x20);

        uVar7 = 1000000;

        if (0 < param_2) {

          uVar5 = FUN_140149300();

          if (uVar6 <= uVar5) goto LAB_14013bd5a;

          if (uVar6 - uVar5 < 1000000) {

            uVar7 = uVar6 - uVar5;

          }

        }

        thunk_FUN_140184480(uVar7);

        FUN_14013b080(1);

        uVar8 = CONCAT44(uVar2,0xffff);

        iVar1 = FUN_14013afe0(param_1,1,2,0,uVar8);

      }

    }

LAB_14013bcf6:

    uVar2 = 1;

  }

  return uVar2;

}




