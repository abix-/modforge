// Address: 0x1400a9180
// Ghidra name: FUN_1400a9180
// ============ 0x1400a9180 FUN_1400a9180 (size=263) ============


void FUN_1400a9180(longlong param_1,undefined4 param_2,undefined4 param_3)



{

  longlong *plVar1;

  undefined8 *puVar2;

  ulonglong uVar3;

  undefined8 *puVar4;

  undefined8 uVar5;

  longlong lVar6;

  undefined8 *puVar7;

  ulonglong uVar8;

  undefined1 local_res10 [8];

  

  puVar2 = *(undefined8 **)(param_1 + 0x20);

  plVar1 = (longlong *)(param_1 + 0x18);

  lVar6 = *plVar1;

  uVar3 = ((longlong)puVar2 - lVar6) / 0x168;

  uVar8 = (ulonglong)((int)uVar3 + 1);

  if (uVar8 < uVar3) {

    puVar7 = (undefined8 *)(uVar8 * 0x168 + lVar6);

    for (puVar4 = puVar7; puVar4 != puVar2; puVar4 = puVar4 + 0x2d) {

      puVar4[0x14] = b2Shape::vftable;

      *puVar4 = b2Shape::vftable;

    }

    *(undefined8 **)(param_1 + 0x20) = puVar7;

  }

  else if (uVar3 < uVar8) {

    if ((ulonglong)((*(longlong *)(param_1 + 0x28) - lVar6) / 0x168) < uVar8) {

      FUN_1400bea50(plVar1,uVar8,local_res10);

    }

    else {

      uVar5 = FUN_1400bf070(puVar2,uVar8 - uVar3,plVar1);

      *(undefined8 *)(param_1 + 0x20) = uVar5;

    }

  }

  lVar6 = *plVar1 + (longlong)(int)uVar3 * 0x168;

  *(undefined4 *)(lVar6 + 0x154) = param_3;

  *(undefined4 *)(lVar6 + 0x150) = param_2;

  return;

}




