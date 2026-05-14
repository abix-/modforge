// Address: 0x1401c7380
// Ghidra name: FUN_1401c7380
// ============ 0x1401c7380 FUN_1401c7380 (size=184) ============


ulonglong FUN_1401c7380(longlong *param_1,longlong param_2,undefined8 param_3)



{

  undefined4 *puVar1;

  undefined1 auVar2 [16];

  longlong lVar3;

  ulonglong in_RAX;

  undefined4 *puVar4;

  ulonglong uVar5;

  undefined1 (*pauVar6) [16];

  ulonglong uVar7;

  

  if ((param_2 != 0) && (*(uint *)(param_1 + 3) != 0)) {

    pauVar6 = (undefined1 (*) [16])param_1[2];

    uVar7 = (ulonglong)*(uint *)(param_1 + 3);

    lVar3 = *param_1;

    puVar4 = (undefined4 *)(param_2 + 0xc);

    do {

      auVar2 = *pauVar6;

      *(undefined8 *)(puVar4 + -3) = param_3;

      puVar1 = puVar4 + 8;

      pauVar6 = pauVar6 + 1;

      puVar4[-1] = auVar2._0_4_;

      uVar5 = auVar2._0_8_ >> 0x20;

      puVar4[2] = auVar2._12_4_;

      *puVar4 = *(undefined4 *)(&DAT_1403e4970 + (longlong)auVar2._8_4_ * 4);

      puVar4[1] = auVar2._4_4_;

      puVar4[3] = *(undefined4 *)(&DAT_1403e4960 + (longlong)*(int *)(lVar3 + 8 + uVar5 * 0x10) * 4)

      ;

      puVar4[4] = (uint)(*(int *)(lVar3 + uVar5 * 0x10 + 8) == 1);

      uVar7 = uVar7 - 1;

      puVar4 = puVar1;

    } while (uVar7 != 0);

    return CONCAT71((int7)((ulonglong)puVar1 >> 8),1);

  }

  return in_RAX & 0xffffffffffffff00;

}




