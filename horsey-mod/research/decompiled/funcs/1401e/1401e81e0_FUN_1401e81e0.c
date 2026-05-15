// Address: 0x1401e81e0
// Ghidra name: FUN_1401e81e0
// ============ 0x1401e81e0 FUN_1401e81e0 (size=195) ============


undefined8 FUN_1401e81e0(undefined8 param_1)



{

  int iVar1;

  undefined4 uVar2;

  undefined8 uVar3;

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

  

  FUN_1401e8670();

  iVar1 = FUN_1401e6200(param_1);

  if (-1 < iVar1) {

    iVar1 = FUN_1401e7960(param_1);

    if (-1 < iVar1) {

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

      uVar3 = FUN_14014ef60(param_1);

      uVar2 = FUN_14016e2d0(uVar3);

      local_78 = CONCAT44(local_78._4_4_,uVar2);

      FUN_14013b140(&local_88);

      return 1;

    }

  }

  uVar3 = FUN_14012e730();

                    /* WARNING: Subroutine does not return */

  FUN_14012e0b0(6,"Renderer couldn\'t recover from device lost: %s",uVar3);

}




