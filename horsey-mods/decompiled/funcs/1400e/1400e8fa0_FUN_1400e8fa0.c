// Address: 0x1400e8fa0
// Ghidra name: FUN_1400e8fa0
// ============ 0x1400e8fa0 FUN_1400e8fa0 (size=246) ============


void FUN_1400e8fa0(longlong *param_1)



{

  byte bVar1;

  char cVar2;

  longlong lVar3;

  int iVar4;

  byte *pbVar5;

  char *pcVar6;

  uint uVar7;

  

  do {

    if (*(int *)((longlong)param_1 + 0x36cc) == 0) {

      lVar3 = *param_1;

      pbVar5 = *(byte **)(lVar3 + 0xb8);

      if (*(byte **)(lVar3 + 0xc0) <= pbVar5) {

        if (*(int *)(lVar3 + 0x30) == 0) goto LAB_1400e905d;

        FUN_1400ed820(lVar3);

        pbVar5 = *(byte **)(lVar3 + 0xb8);

      }

      bVar1 = *pbVar5;

      *(byte **)(lVar3 + 0xb8) = pbVar5 + 1;

      uVar7 = (uint)bVar1;

      if (bVar1 == 0xff) {

        lVar3 = *param_1;

        pcVar6 = *(char **)(lVar3 + 0xb8);

        uVar7 = 0xff;

        if (*(char **)(lVar3 + 0xc0) <= pcVar6) {

          if (*(int *)(lVar3 + 0x30) == 0) goto LAB_1400e905f;

          FUN_1400ed820(lVar3);

          pcVar6 = *(char **)(lVar3 + 0xb8);

        }

        cVar2 = *pcVar6;

        *(char **)(lVar3 + 0xb8) = pcVar6 + 1;

        if (cVar2 != '\0') {

          *(char *)(param_1 + 0x6d9) = cVar2;

          *(undefined4 *)((longlong)param_1 + 0x36cc) = 1;

          return;

        }

      }

    }

    else {

LAB_1400e905d:

      uVar7 = 0;

    }

LAB_1400e905f:

    iVar4 = *(int *)((longlong)param_1 + 0x36c4) + 8;

    *(uint *)(param_1 + 0x6d8) =

         *(uint *)(param_1 + 0x6d8) |

         uVar7 << (0x18U - (char)*(int *)((longlong)param_1 + 0x36c4) & 0x1f);

    *(int *)((longlong)param_1 + 0x36c4) = iVar4;

    if (0x18 < iVar4) {

      return;

    }

  } while( true );

}




