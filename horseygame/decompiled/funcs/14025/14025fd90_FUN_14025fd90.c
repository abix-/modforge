// Address: 0x14025fd90
// Ghidra name: FUN_14025fd90
// ============ 0x14025fd90 FUN_14025fd90 (size=346) ============


undefined8 FUN_14025fd90(longlong param_1,longlong param_2,int param_3,undefined4 param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  char cVar7;

  uint uVar8;

  undefined8 uVar9;

  longlong lVar11;

  ulonglong uVar10;

  

  cVar7 = FUN_1401489c0();

  if (cVar7 == '\0') {

    uVar9 = FUN_14012e850("Parameter \'%s\' is invalid","SDL_DrawPoints(): dst");

    return uVar9;

  }

  uVar10 = *(ulonglong *)(param_1 + 0x38);

  if (7 < *(byte *)(uVar10 + 4)) {

    iVar1 = *(int *)(param_1 + 0x68);

    iVar2 = *(int *)(param_1 + 100);

    iVar3 = *(int *)(param_1 + 0x70);

    iVar4 = *(int *)(param_1 + 0x6c);

    if (0 < param_3) {

      lVar11 = 0;

      do {

        iVar5 = *(int *)(param_2 + lVar11 * 8);

        iVar6 = *(int *)(param_2 + 4 + lVar11 * 8);

        if ((((iVar2 <= iVar5) && (iVar5 <= iVar2 + -1 + iVar4)) && (iVar1 <= iVar6)) &&

           (iVar6 <= iVar1 + -1 + iVar3)) {

          uVar8 = (uint)*(byte *)(*(longlong *)(param_1 + 0x38) + 5);

          if (uVar8 == 1) {

            *(char *)((longlong)(iVar6 * *(int *)(param_1 + 0x10)) + *(longlong *)(param_1 + 0x18) +

                     (longlong)iVar5) = (char)param_4;

            uVar10 = 0;

          }

          else if (uVar8 == 2) {

            uVar10 = *(ulonglong *)(param_1 + 0x18);

            *(short *)((longlong)(iVar6 * *(int *)(param_1 + 0x10)) + (longlong)(iVar5 * 2) + uVar10

                      ) = (short)param_4;

          }

          else {

            uVar8 = uVar8 - 3;

            uVar10 = (ulonglong)uVar8;

            if (uVar8 == 0) {

              uVar9 = FUN_14012e850("That operation is not supported");

              return uVar9;

            }

            if (uVar8 == 1) {

              uVar10 = *(ulonglong *)(param_1 + 0x18);

              *(undefined4 *)

               ((longlong)(iVar6 * *(int *)(param_1 + 0x10)) + (longlong)(iVar5 * 4) + uVar10) =

                   param_4;

            }

          }

        }

        lVar11 = lVar11 + 1;

      } while (lVar11 < param_3);

    }

    return CONCAT71((int7)(uVar10 >> 8),1);

  }

  uVar9 = FUN_14012e850("SDL_DrawPoints(): Unsupported surface format");

  return uVar9;

}




