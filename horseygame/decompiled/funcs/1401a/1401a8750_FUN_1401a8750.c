// Address: 0x1401a8750
// Ghidra name: FUN_1401a8750
// ============ 0x1401a8750 FUN_1401a8750 (size=460) ============


void FUN_1401a8750(undefined8 param_1,int param_2,undefined4 *param_3,byte param_4,char param_5)



{

  bool bVar1;

  char cVar2;

  longlong lVar3;

  uint uVar4;

  uint uVar5;

  int iVar6;

  undefined4 uVar7;

  undefined4 uVar8;

  int local_c8 [2];

  undefined8 local_c0;

  undefined4 local_b8;

  int local_b4;

  uint local_b0;

  undefined4 local_ac;

  undefined4 local_a8;

  byte local_a4;

  char local_a3;

  undefined8 local_a2;

  undefined8 uStack_9a;

  undefined8 local_92;

  undefined8 uStack_8a;

  undefined8 local_82;

  undefined8 uStack_7a;

  undefined8 local_72;

  undefined8 uStack_6a;

  undefined8 local_62;

  undefined8 uStack_5a;

  undefined8 local_52;

  undefined2 local_4a;

  

  bVar1 = false;

  uVar5 = 0;

  uVar7 = 0;

  uVar8 = 0;

  if (4 < (byte)(param_4 - 1)) {

    return;

  }

  FUN_14017caa0(DAT_1403fcd48);

  lVar3 = FUN_1401a8110(param_2);

  if (lVar3 == 0) goto LAB_1401a8809;

  FUN_1401a80e0(param_1,lVar3,param_3);

  uVar5 = *(uint *)(lVar3 + 0x4c);

  uVar7 = *(undefined4 *)(lVar3 + 0x44);

  uVar8 = *(undefined4 *)(lVar3 + 0x48);

  uVar4 = 1 << (param_4 & 0x1f);

  bVar1 = false;

  if (param_5 == '\0') {

    if ((uVar4 & uVar5) != 0) {

      uVar5 = uVar5 & ~uVar4;

      goto LAB_1401a8802;

    }

  }

  else if ((uVar4 & uVar5) == 0) {

    uVar5 = uVar5 | uVar4;

LAB_1401a8802:

    bVar1 = true;

  }

  *(uint *)(lVar3 + 0x4c) = uVar5;

LAB_1401a8809:

  FUN_14017cae0(DAT_1403fcd48);

  if (bVar1) {

    iVar6 = 0x1305 - (uint)(param_5 != '\0');

    cVar2 = FUN_140139420(iVar6);

    if (cVar2 != '\0') {

      local_c8[1] = 0;

      local_52 = 0;

      local_4a = 0;

      local_a3 = param_5;

      local_a2 = 0;

      uStack_9a = 0;

      local_92 = 0;

      uStack_8a = 0;

      local_82 = 0;

      uStack_7a = 0;

      local_72 = 0;

      uStack_6a = 0;

      local_62 = 0;

      uStack_5a = 0;

      local_c8[0] = iVar6;

      local_c0 = param_1;

      local_b4 = param_2;

      local_b0 = uVar5;

      local_ac = uVar7;

      local_a8 = uVar8;

      local_a4 = param_4;

      if (param_3 == (undefined4 *)0x0) {

        local_b8 = 0;

        FUN_14013b140(local_c8);

      }

      else {

        local_b8 = *param_3;

        FUN_14013b140(local_c8);

        if ((((DAT_1403fcd40 == 0) || (DAT_1403fcd40 == param_2)) &&

            (lVar3 = FUN_1401611a0(), lVar3 != 0)) &&

           ((*(char *)(lVar3 + 0xee) != '\0' && (param_4 < 5)))) {

          FUN_1401628d0(param_1,param_3,0xfffffffe,(&DAT_14033c3d4)[param_4],param_5);

        }

      }

    }

  }

  return;

}




