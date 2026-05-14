// Address: 0x14021b0d0
// Ghidra name: FUN_14021b0d0
// ============ 0x14021b0d0 FUN_14021b0d0 (size=110) ============


void FUN_14021b0d0(longlong param_1,undefined8 *param_2)



{

  undefined8 *puVar1;

  longlong lVar2;

  undefined8 uVar3;

  int iVar4;

  longlong lVar5;

  

  iVar4 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x10) + 0x38))();

  if (-1 < iVar4) {

    uVar3 = param_2[1];

    lVar2 = *(longlong *)(param_1 + 0x10);

    lVar5 = (longlong)iVar4;

    puVar1 = (undefined8 *)(lVar2 + lVar5 * 0x50);

    *puVar1 = *param_2;

    puVar1[1] = uVar3;

    uVar3 = param_2[3];

    puVar1 = (undefined8 *)(lVar2 + 0x10 + lVar5 * 0x50);

    *puVar1 = param_2[2];

    puVar1[1] = uVar3;

    uVar3 = param_2[5];

    puVar1 = (undefined8 *)(lVar2 + 0x20 + lVar5 * 0x50);

    *puVar1 = param_2[4];

    puVar1[1] = uVar3;

    uVar3 = param_2[7];

    puVar1 = (undefined8 *)(lVar2 + 0x30 + lVar5 * 0x50);

    *puVar1 = param_2[6];

    puVar1[1] = uVar3;

    *(undefined8 *)(lVar2 + 0x40 + lVar5 * 0x50) = param_2[8];

  }

  return;

}




