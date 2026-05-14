// Address: 0x14002c950
// Ghidra name: FUN_14002c950
// ============ 0x14002c950 FUN_14002c950 (size=337) ============


uint FUN_14002c950(longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)



{

  longlong *plVar1;

  char cVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  undefined8 uVar6;

  longlong lVar7;

  char *pcVar8;

  longlong *plVar9;

  undefined1 local_58 [16];

  undefined1 local_48 [48];

  

  uVar5 = 0;

  param_1[1] = 0;

  plVar1 = *(longlong **)((longlong)*(int *)(*param_1 + 4) + 0x48 + (longlong)param_1);

  plVar9 = param_1;

  if (plVar1 != (longlong *)0x0) {

    (**(code **)(*plVar1 + 8))();

  }

  cVar2 = FUN_14002ccc0(param_1);

  if (cVar2 == '\0') {

    uVar3 = 0xffffffff;

  }

  else {

    plVar1 = *(longlong **)((longlong)*(int *)(*param_1 + 4) + 0x48 + (longlong)param_1);

    if ((*(byte **)plVar1[7] == (byte *)0x0) || (*(int *)plVar1[10] < 1)) {

      uVar3 = (**(code **)(*plVar1 + 0x30))();

    }

    else {

      uVar3 = (uint)**(byte **)plVar1[7];

    }

    uVar5 = (uint)(uVar3 == 0xffffffff);

  }

  lVar7 = (longlong)*(int *)(*param_1 + 4);

  uVar4 = 4;

  if (*(longlong *)(lVar7 + 0x48 + (longlong)param_1) != 0) {

    uVar4 = 0;

  }

  uVar5 = uVar4 | *(uint *)(lVar7 + 0x10 + (longlong)param_1) & 0x17 | uVar5;

  *(uint *)(lVar7 + 0x10 + (longlong)param_1) = uVar5;

  uVar5 = uVar5 & *(uint *)(lVar7 + 0x14 + (longlong)param_1);

  if (uVar5 == 0) {

    plVar1 = *(longlong **)((longlong)*(int *)(*param_1 + 4) + 0x48 + (longlong)param_1);

    if (plVar1 != (longlong *)0x0) {

      (**(code **)(*plVar1 + 0x10))();

    }

    return uVar3;

  }

  if ((uVar5 & 4) == 0) {

    pcVar8 = "ios_base::failbit set";

    if ((uVar5 & 2) == 0) {

      pcVar8 = "ios_base::eofbit set";

    }

  }

  else {

    pcVar8 = "ios_base::badbit set";

  }

  uVar6 = FUN_140024200(local_58,1);

  FUN_140024730(local_48,pcVar8,uVar6,param_4,plVar9);

                    /* WARNING: Subroutine does not return */

  FUN_1402c8240(local_48,&DAT_1403c78a8);

}




