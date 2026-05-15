// Address: 0x140111f20
// Ghidra name: FUN_140111f20
// ============ 0x140111f20 FUN_140111f20 (size=477) ============


undefined8

FUN_140111f20(undefined8 *param_1,undefined8 *param_2,longlong param_3,undefined1 param_4)



{

  undefined1 auVar1 [16];

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined8 *puVar5;

  longlong lVar6;

  undefined8 uVar7;

  ulonglong uVar8;

  undefined8 *puVar9;

  undefined8 *local_58;

  undefined8 *local_50;

  undefined8 local_48;

  undefined8 uStack_40;

  undefined8 local_38;

  undefined8 uStack_30;

  undefined8 local_28;

  

  lVar6 = (longlong)param_2 - (longlong)param_1;

  while( true ) {

    if (lVar6 < 0x528) {

      uVar7 = FUN_140110a10(param_1,param_2,param_4);

      return uVar7;

    }

    if (param_3 < 1) break;

    FUN_1401112f0(&local_58,param_1,param_2,param_4);

    puVar5 = local_50;

    puVar9 = local_58;

    param_3 = (param_3 >> 1) + (param_3 >> 2);

    if (((longlong)local_58 - (longlong)param_1) / 0x28 <

        ((longlong)param_2 - (longlong)local_50) / 0x28) {

      FUN_140111f20(param_1,local_58,param_3,param_4);

      puVar9 = param_2;

      param_1 = puVar5;

    }

    else {

      FUN_140111f20(local_50,param_2,param_3,param_4);

    }

    lVar6 = (longlong)puVar9 - (longlong)param_1;

    param_2 = puVar9;

  }

  uVar7 = FUN_140110bf0(param_1,param_2,param_4);

  uVar8 = (longlong)param_2 - (longlong)param_1;

  while (0x4f < (longlong)uVar8) {

    puVar9 = param_2 + -5;

    auVar1._8_8_ = 0;

    auVar1._0_8_ = uVar8;

    uVar7 = SUB168(ZEXT816(0xcccccccccccccccd) * auVar1,0);

    if (1 < uVar8 / 0x28) {

      local_48 = *puVar9;

      uStack_40 = param_2[-4];

      local_38 = param_2[-3];

      uStack_30 = param_2[-2];

      local_28 = param_2[-1];

      uVar7 = param_1[1];

      *puVar9 = *param_1;

      param_2[-4] = uVar7;

      uVar2 = *(undefined4 *)((longlong)param_1 + 0x14);

      uVar3 = *(undefined4 *)(param_1 + 3);

      uVar4 = *(undefined4 *)((longlong)param_1 + 0x1c);

      *(undefined4 *)(param_2 + -3) = *(undefined4 *)(param_1 + 2);

      *(undefined4 *)((longlong)param_2 + -0x14) = uVar2;

      *(undefined4 *)(param_2 + -2) = uVar3;

      *(undefined4 *)((longlong)param_2 + -0xc) = uVar4;

      param_2[-1] = param_1[4];

      uVar7 = FUN_140111a50(param_1,0,((longlong)puVar9 - (longlong)param_1) / 0x28,&local_48,

                            param_4);

    }

    param_2 = puVar9;

    uVar8 = (longlong)puVar9 - (longlong)param_1;

  }

  return uVar7;

}




