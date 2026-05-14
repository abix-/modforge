// Address: 0x14002cac0
// Ghidra name: FUN_14002cac0
// ============ 0x14002cac0 FUN_14002cac0 (size=400) ============


uint FUN_14002cac0(longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  int iVar1;

  longlong *plVar2;

  char cVar3;

  uint uVar4;

  uint uVar5;

  uint uVar6;

  undefined8 uVar7;

  longlong lVar8;

  char *pcVar9;

  longlong *plVar10;

  undefined1 local_58 [16];

  undefined1 local_48 [48];

  

  param_1[1] = 0;

  plVar2 = *(longlong **)((longlong)*(int *)(*param_1 + 4) + 0x48 + (longlong)param_1);

  plVar10 = param_1;

  if (plVar2 != (longlong *)0x0) {

    (**(code **)(*plVar2 + 8))();

  }

  cVar3 = FUN_14002ccc0(param_1);

  if (cVar3 == '\0') {

    uVar4 = 0xffffffff;

    uVar6 = 0;

    goto LAB_14002cbc4;

  }

  plVar2 = *(longlong **)((longlong)*(int *)(*param_1 + 4) + 0x48 + (longlong)param_1);

  if ((*(byte **)plVar2[7] == (byte *)0x0) || (*(int *)plVar2[10] < 1)) {

    uVar4 = (**(code **)(*plVar2 + 0x30))();

  }

  else {

    uVar4 = (uint)**(byte **)plVar2[7];

  }

  if (uVar4 == 0xffffffff) {

    uVar6 = 3;

    goto LAB_14002cbc4;

  }

  plVar2 = *(longlong **)((longlong)*(int *)(*param_1 + 4) + 0x48 + (longlong)param_1);

  if (*(longlong *)plVar2[7] == 0) {

LAB_14002cb9b:

    (**(code **)(*plVar2 + 0x38))();

  }

  else {

    iVar1 = *(int *)plVar2[10];

    if (iVar1 < 1) goto LAB_14002cb9b;

    *(int *)plVar2[10] = iVar1 + -1;

    *(longlong *)plVar2[7] = *(longlong *)plVar2[7] + 1;

  }

  param_1[1] = 1;

  uVar6 = 0;

LAB_14002cbc4:

  lVar8 = (longlong)*(int *)(*param_1 + 4);

  uVar5 = 4;

  if (*(longlong *)(lVar8 + 0x48 + (longlong)param_1) != 0) {

    uVar5 = 0;

  }

  uVar6 = uVar5 | *(uint *)(lVar8 + 0x10 + (longlong)param_1) & 0x17 | uVar6;

  *(uint *)(lVar8 + 0x10 + (longlong)param_1) = uVar6;

  uVar6 = uVar6 & *(uint *)(lVar8 + 0x14 + (longlong)param_1);

  if (uVar6 != 0) {

    if ((uVar6 & 4) == 0) {

      pcVar9 = "ios_base::failbit set";

      if ((uVar6 & 2) == 0) {

        pcVar9 = "ios_base::eofbit set";

      }

    }

    else {

      pcVar9 = "ios_base::badbit set";

    }

    uVar7 = FUN_140024200(local_58,1);

    FUN_140024730(local_48,pcVar9,uVar7,param_4,plVar10);

                    /* WARNING: Subroutine does not return */

    FUN_1402c8240(local_48,&DAT_1403c78a8);

  }

  plVar2 = *(longlong **)((longlong)*(int *)(*param_1 + 4) + 0x48 + (longlong)param_1);

  if (plVar2 != (longlong *)0x0) {

    (**(code **)(*plVar2 + 0x10))();

  }

  return uVar4;

}




