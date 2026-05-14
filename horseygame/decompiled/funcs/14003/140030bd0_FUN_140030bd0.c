// Address: 0x140030bd0
// Ghidra name: FUN_140030bd0
// ============ 0x140030bd0 FUN_140030bd0 (size=363) ============


undefined8 FUN_140030bd0(longlong param_1)



{

  ulonglong uVar1;

  undefined4 uVar2;

  longlong *plVar3;

  int iVar4;

  longlong lVar5;

  bool bVar6;

  

  FUN_1400cd5a0(param_1,1);

  FUN_1400d0a00(param_1,0);

  FUN_1400ce540(param_1,0,0);

  if (*(int *)(param_1 + 0x250) != 0) {

    *(undefined4 *)(param_1 + 0x250) = 2;

  }

  *(undefined4 *)(param_1 + 0x254) = 0;

  bVar6 = *(char *)(param_1 + 0x6b0) != '\0';

  *(undefined8 *)(param_1 + 0x27c) = 0;

  *(undefined4 *)(param_1 + 0x694) = 0;

  uVar2 = 8;

  if (bVar6) {

    uVar2 = 0x10;

  }

  *(undefined4 *)(param_1 + 0x6a8) = uVar2;

  uVar2 = 0x14;

  if (bVar6) {

    uVar2 = 0x28;

  }

  *(undefined4 *)(param_1 + 0x6ac) = uVar2;

  *(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x405) = 0;

  *(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x46d) = 0;

  *(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x4d5) = 0;

  *(undefined1 *)(*(longlong *)(param_1 + 0x60) + 0x53d) = 0;

  uVar1 = DAT_1403d9548;

  uVar2 = DAT_140303750;

  plVar3 = (longlong *)&DAT_1403d9530;

  if (0xf < DAT_1403d9548) {

    plVar3 = DAT_1403d9530;

  }

  if (DAT_1403d9540 == 9) {

    lVar5 = *plVar3 + -0x656b6361686f6942;

    if (lVar5 == 0) {

      lVar5 = (ulonglong)*(byte *)(plVar3 + 1) - 0x72;

    }

    if (lVar5 != 0) goto LAB_140030cce;

  }

  else {

LAB_140030cce:

    plVar3 = (longlong *)&DAT_1403d9530;

    if (0xf < DAT_1403d9548) {

      plVar3 = DAT_1403d9530;

    }

    if (DAT_1403d9540 != 6) goto LAB_140030d2b;

    iVar4 = (int)*plVar3 + -0x74696c47;

    if (iVar4 == 0) {

      iVar4 = *(ushort *)((longlong)plVar3 + 4) - 0x6863;

    }

    if (iVar4 != 0) goto LAB_140030d2b;

  }

  *(int *)(param_1 + 0x698) = *(int *)(param_1 + 0x698) + 0xfa;

  *(undefined4 *)(param_1 + 0x250) = 3;

  *(undefined4 *)(param_1 + 0x254) = 0x168;

  FUN_1400cc9d0(param_1,0x30,uVar1,uVar2);

LAB_140030d2b:

  FUN_140032610(param_1);

  return 1;

}




