// Address: 0x1401fa960
// Ghidra name: FUN_1401fa960
// ============ 0x1401fa960 FUN_1401fa960 (size=217) ============


undefined8 FUN_1401fa960(longlong param_1)



{

  longlong lVar1;

  int iVar2;

  undefined4 uVar3;

  undefined8 uVar4;

  undefined8 local_88;

  undefined8 uStack_80;

  undefined8 local_78;

  undefined8 uStack_70;

  undefined8 local_68;

  undefined8 uStack_60;

  undefined8 local_58;

  undefined8 uStack_50;

  undefined8 local_48;

  undefined8 uStack_40;

  undefined8 local_38;

  undefined8 uStack_30;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  undefined8 uStack_10;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  FUN_1401f9010();

  iVar2 = FUN_1401f6770(param_1,*(undefined4 *)(lVar1 + 0x6f0));

  if (iVar2 == 0) {

    iVar2 = FUN_1401f8fa0(param_1);

    if (iVar2 == 0) {

      uStack_80 = 0;

      local_88 = 0x2001;

      local_78 = 0;

      uStack_70 = 0;

      local_68 = 0;

      uStack_60 = 0;

      local_58 = 0;

      uStack_50 = 0;

      local_48 = 0;

      uStack_40 = 0;

      local_38 = 0;

      uStack_30 = 0;

      local_28 = 0;

      uStack_20 = 0;

      local_18 = 0;

      uStack_10 = 0;

      uVar4 = FUN_14014ef60(param_1);

      uVar3 = FUN_14016e2d0(uVar4);

      local_78 = CONCAT44(local_78._4_4_,uVar3);

      FUN_14013b140(&local_88);

      return 1;

    }

  }

  uVar4 = FUN_14012e730();

                    /* WARNING: Subroutine does not return */

  FUN_14012e0b0(6,"Renderer couldn\'t recover from device lost: %s",uVar4);

}




