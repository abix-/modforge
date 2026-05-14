// Address: 0x1400fd1e0
// Ghidra name: FUN_1400fd1e0
// ============ 0x1400fd1e0 FUN_1400fd1e0 (size=495) ============


void FUN_1400fd1e0(longlong param_1)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  undefined8 *puVar5;

  longlong *plVar6;

  longlong lVar7;

  undefined4 uVar8;

  undefined4 uVar9;

  undefined4 uVar10;

  undefined4 uVar11;

  undefined8 *puVar12;

  longlong *plVar13;

  undefined4 uVar14;

  undefined4 uVar15;

  

  puVar5 = *(undefined8 **)(DAT_1403f4e00 + 0x138);

  for (puVar12 = *(undefined8 **)(DAT_1403f4e00 + 0x130); puVar12 != puVar5; puVar12 = puVar12 + 1)

  {

    FUN_140100d80(param_1,*puVar12,DAT_1403ffbe8);

  }

  if (*(longlong *)(DAT_1403f4e00 + 0x130) != *(longlong *)(DAT_1403f4e00 + 0x138)) {

    *(longlong *)(DAT_1403f4e00 + 0x138) = *(longlong *)(DAT_1403f4e00 + 0x130);

  }

  uVar11 = DAT_14039ca58;

  uVar10 = DAT_14030a23c;

  uVar9 = DAT_140305fc0;

  uVar8 = DAT_140303398;

  plVar6 = *(longlong **)(DAT_1403f4e00 + 0xc0);

  for (plVar13 = *(longlong **)(DAT_1403f4e00 + 0xb8); plVar13 != plVar6; plVar13 = plVar13 + 1) {

    lVar7 = *plVar13;

    if (*(int *)(lVar7 + 8) == 3) {

      uVar14 = FUN_1400c6940(uVar10,uVar8);

      uVar15 = FUN_1400c6940(uVar9,uVar11);

      FUN_140100fc0(param_1,lVar7,uVar15,uVar14);

    }

  }

  if (*(longlong *)(DAT_1403f4e00 + 0xb8) != *(longlong *)(DAT_1403f4e00 + 0xc0)) {

    *(longlong *)(DAT_1403f4e00 + 0xc0) = *(longlong *)(DAT_1403f4e00 + 0xb8);

  }

  lVar7 = *(longlong *)(param_1 + 0x300);

  fVar1 = *(float *)(param_1 + 0x394);

  fVar2 = *(float *)(param_1 + 0x398);

  fVar3 = *(float *)(lVar7 + 0x28);

  fVar4 = *(float *)(lVar7 + 0x2c);

  *(float *)(lVar7 + 0x28) = fVar1;

  *(undefined4 *)(*(longlong *)(param_1 + 0x300) + 0x2c) = *(undefined4 *)(param_1 + 0x398);

  *(undefined1 *)(*(longlong *)(param_1 + 0x300) + 0xac) = 0;

  FUN_1400a89f0(*(undefined8 *)(param_1 + 0x300));

  FUN_1400fb9c0(*(undefined8 *)(param_1 + 0x300));

  if (*(int *)(param_1 + 0x35c) != 0) {

    *(float *)(param_1 + 0x354) = (fVar1 - fVar3) + *(float *)(param_1 + 0x354);

    *(float *)(param_1 + 0x358) = (fVar2 - fVar4) + *(float *)(param_1 + 0x358);

  }

  return;

}




