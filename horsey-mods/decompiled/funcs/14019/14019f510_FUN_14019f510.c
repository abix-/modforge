// Address: 0x14019f510
// Ghidra name: FUN_14019f510
// ============ 0x14019f510 FUN_14019f510 (size=338) ============


void FUN_14019f510(longlong *param_1)



{

  longlong lVar1;

  byte *pbVar2;

  char cVar3;

  int iVar4;

  char *pcVar5;

  byte bVar6;

  uint uVar7;

  

  do {

    if (*(int *)((longlong)param_1 + 0x482c) == 0) {

      lVar1 = *param_1;

      pbVar2 = *(byte **)(lVar1 + 0xc0);

      if (pbVar2 < *(byte **)(lVar1 + 200)) {

        bVar6 = *pbVar2;

        *(byte **)(lVar1 + 0xc0) = pbVar2 + 1;

      }

      else if (*(int *)(lVar1 + 0x30) == 0) {

        bVar6 = 0;

      }

      else {

        FUN_1401a4400(lVar1);

        bVar6 = **(byte **)(lVar1 + 0xc0);

        *(byte **)(lVar1 + 0xc0) = *(byte **)(lVar1 + 0xc0) + 1;

      }

      uVar7 = (uint)bVar6;

      if (bVar6 == 0xff) {

        lVar1 = *param_1;

        pcVar5 = *(char **)(lVar1 + 0xc0);

        if (*(char **)(lVar1 + 200) <= pcVar5) {

          if (*(int *)(lVar1 + 0x30) == 0) goto LAB_14019f60b;

          FUN_1401a4400(lVar1);

          pcVar5 = *(char **)(lVar1 + 0xc0);

        }

        cVar3 = *pcVar5;

        *(char **)(lVar1 + 0xc0) = pcVar5 + 1;

        while (cVar3 == -1) {

          lVar1 = *param_1;

          pcVar5 = *(char **)(lVar1 + 0xc0);

          if (*(char **)(lVar1 + 200) <= pcVar5) {

            if (*(int *)(lVar1 + 0x30) == 0) {

              cVar3 = '\0';

              break;

            }

            FUN_1401a4400(lVar1);

            pcVar5 = *(char **)(lVar1 + 0xc0);

          }

          cVar3 = *pcVar5;

          *(char **)(lVar1 + 0xc0) = pcVar5 + 1;

        }

        if (cVar3 != '\0') {

          *(char *)(param_1 + 0x905) = cVar3;

          *(undefined4 *)((longlong)param_1 + 0x482c) = 1;

          return;

        }

      }

    }

    else {

      uVar7 = 0;

    }

LAB_14019f60b:

    iVar4 = *(int *)((longlong)param_1 + 0x4824) + 8;

    *(uint *)(param_1 + 0x904) =

         *(uint *)(param_1 + 0x904) |

         uVar7 << (0x18U - (char)*(int *)((longlong)param_1 + 0x4824) & 0x1f);

    *(int *)((longlong)param_1 + 0x4824) = iVar4;

    if (0x18 < iVar4) {

      return;

    }

  } while( true );

}




