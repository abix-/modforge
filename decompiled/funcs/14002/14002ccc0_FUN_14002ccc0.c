// Address: 0x14002ccc0
// Ghidra name: FUN_14002ccc0
// ============ 0x14002ccc0 FUN_14002ccc0 (size=180) ============


undefined8 FUN_14002ccc0(longlong *param_1)



{

  int iVar1;

  uint uVar2;

  uint uVar3;

  undefined8 uVar4;

  char *pcVar5;

  undefined1 local_48 [16];

  undefined1 local_38 [48];

  

  iVar1 = *(int *)(*param_1 + 4);

  uVar3 = *(uint *)((longlong)param_1 + (longlong)iVar1 + 0x10);

  if (uVar3 == 0) {

    if (*(longlong *)((longlong)param_1 + (longlong)iVar1 + 0x50) != 0) {

      FUN_140028440();

    }

    return CONCAT71((int7)((ulonglong)*param_1 >> 8),

                    *(int *)((longlong)*(int *)(*param_1 + 4) + 0x10 + (longlong)param_1) == 0);

  }

  uVar2 = 4;

  if (*(longlong *)((longlong)param_1 + (longlong)iVar1 + 0x48) != 0) {

    uVar2 = 0;

  }

  uVar3 = uVar2 | uVar3 & 0x15 | 2;

  *(uint *)((longlong)param_1 + (longlong)iVar1 + 0x10) = uVar3;

  uVar3 = uVar3 & *(uint *)((longlong)param_1 + (longlong)iVar1 + 0x14);

  if (uVar3 == 0) {

    return 0;

  }

  if ((uVar3 & 4) == 0) {

    pcVar5 = "ios_base::failbit set";

    if ((uVar3 & 2) == 0) {

      pcVar5 = "ios_base::eofbit set";

    }

  }

  else {

    pcVar5 = "ios_base::badbit set";

  }

  uVar4 = FUN_140024200(local_48,1);

  FUN_140024730(local_38,pcVar5,uVar4);

                    /* WARNING: Subroutine does not return */

  FUN_1402c8240(local_38,&DAT_1403c78a8);

}




