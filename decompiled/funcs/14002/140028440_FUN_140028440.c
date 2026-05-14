// Address: 0x140028440
// Ghidra name: FUN_140028440
// ============ 0x140028440 FUN_140028440 (size=297) ============


longlong * FUN_140028440(longlong *param_1)



{

  longlong *plVar1;

  char cVar2;

  int iVar3;

  undefined8 uVar4;

  longlong lVar5;

  uint uVar6;

  uint uVar7;

  char *pcVar8;

  longlong *local_58;

  char local_50;

  undefined1 local_48 [16];

  undefined1 local_38 [48];

  

  plVar1 = *(longlong **)((longlong)*(int *)(*param_1 + 4) + 0x48 + (longlong)param_1);

  if (plVar1 != (longlong *)0x0) {

    FUN_140028290(&local_58,param_1);

    if (local_50 != '\0') {

      iVar3 = (**(code **)(*plVar1 + 0x68))(plVar1);

      uVar7 = 0;

      uVar6 = 4;

      if (iVar3 == -1) {

        uVar7 = 4;

      }

      lVar5 = (longlong)*(int *)(*param_1 + 4);

      if (*(longlong *)(lVar5 + 0x48 + (longlong)param_1) != 0) {

        uVar6 = 0;

      }

      uVar7 = uVar6 | *(uint *)(lVar5 + 0x10 + (longlong)param_1) & 0x17 | uVar7;

      *(uint *)(lVar5 + 0x10 + (longlong)param_1) = uVar7;

      uVar7 = uVar7 & *(uint *)(lVar5 + 0x14 + (longlong)param_1);

      if (uVar7 != 0) {

        if ((uVar7 & 4) == 0) {

          pcVar8 = "ios_base::failbit set";

          if ((uVar7 & 2) == 0) {

            pcVar8 = "ios_base::eofbit set";

          }

        }

        else {

          pcVar8 = "ios_base::badbit set";

        }

        uVar4 = FUN_140024200(local_48,1);

        FUN_140024730(local_38,pcVar8,uVar4);

                    /* WARNING: Subroutine does not return */

        FUN_1402c8240(local_38,&DAT_1403c78a8);

      }

    }

    cVar2 = __uncaught_exception();

    if (cVar2 == '\0') {

      FUN_140028590(local_58);

    }

    plVar1 = *(longlong **)((longlong)*(int *)(*local_58 + 4) + 0x48 + (longlong)local_58);

    if (plVar1 != (longlong *)0x0) {

      (**(code **)(*plVar1 + 0x10))();

    }

  }

  return param_1;

}




