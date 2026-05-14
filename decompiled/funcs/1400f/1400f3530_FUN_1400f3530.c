// Address: 0x1400f3530
// Ghidra name: FUN_1400f3530
// ============ 0x1400f3530 FUN_1400f3530 (size=298) ============


longlong FUN_1400f3530(longlong param_1,int *param_2,int param_3,int param_4,int param_5,int param_6

                      )



{

  longlong lVar1;

  byte bVar2;

  byte bVar3;

  longlong lVar4;

  uint uVar5;

  ulonglong uVar6;

  int iVar7;

  int iVar8;

  

  lVar4 = *(longlong *)(param_1 + 8);

  uVar5 = FUN_1400f4020(lVar4,*(undefined4 *)(param_1 + 0x10));

  if (uVar5 != 0) {

    bVar2 = *(byte *)(lVar4 + 5 + (ulonglong)uVar5);

    lVar1 = lVar4 + (ulonglong)uVar5;

    bVar3 = *(byte *)(lVar1 + 4);

    iVar7 = 0;

    iVar8 = (uint)*(byte *)(lVar1 + 3) + (uint)*(byte *)(lVar1 + 2) * 0x100;

    if (iVar8 != 0) {

      do {

        uVar6 = (ulonglong)(uVar5 + 6 + iVar7 * 0xc);

        if ((((param_3 ==

               (uint)*(byte *)(uVar6 + lVar4) * 0x100 + (uint)*(byte *)(uVar6 + 1 + lVar4)) &&

             (param_4 ==

              (uint)*(byte *)(uVar6 + 3 + lVar4) + (uint)*(byte *)(uVar6 + 2 + lVar4) * 0x100)) &&

            (param_5 ==

             (uint)*(byte *)(uVar6 + 5 + lVar4) + (uint)*(byte *)(uVar6 + 4 + lVar4) * 0x100)) &&

           (param_6 ==

            (uint)*(byte *)(uVar6 + 7 + lVar4) + (uint)*(byte *)(uVar6 + 6 + lVar4) * 0x100)) {

          *param_2 = (uint)*(byte *)(uVar6 + 9 + lVar4) + (uint)*(byte *)(uVar6 + 8 + lVar4) * 0x100

          ;

          return (longlong)(int)((uint)bVar3 * 0x100 + bVar2 + uVar5) +

                 (ulonglong)*(byte *)(uVar6 + 0xb + lVar4) + lVar4 +

                 (ulonglong)*(byte *)(uVar6 + 10 + lVar4) * 0x100;

        }

        iVar7 = iVar7 + 1;

      } while (iVar7 < iVar8);

    }

  }

  return 0;

}




