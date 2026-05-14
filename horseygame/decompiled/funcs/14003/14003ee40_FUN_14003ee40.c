// Address: 0x14003ee40
// Ghidra name: FUN_14003ee40
// ============ 0x14003ee40 FUN_14003ee40 (size=354) ============


void FUN_14003ee40(void)



{

  int iVar1;

  longlong lVar2;

  ulonglong uVar3;

  longlong lVar4;

  float fVar5;

  

  DAT_1403ea293 = DAT_1403d9500;

  if (DAT_1403d9500 != '\0') {

    iVar1 = FUN_140043810(0xac44);

    if (iVar1 == 0) {

      fVar5 = 0.0;

      if (0.0 <= (float)DAT_1403d9504 * DAT_14039ca0c) {

        fVar5 = (float)DAT_1403d9504 * DAT_14039ca0c;

      }

      *(float *)(DAT_1403ea2a8 + 0x14) = fVar5;

      fVar5 = 0.0;

      if (0.0 <= (float)DAT_1403d9508 * DAT_14039ca0c) {

        fVar5 = (float)DAT_1403d9508 * DAT_14039ca0c;

      }

      *(float *)(DAT_1403ea2a8 + 0xc) = fVar5;

      if (*(longlong *)(DAT_1403ea2a8 + 0x58) != 0) {

        *(float *)(*(longlong *)(DAT_1403ea2a8 + 0x58) + 0xc) = fVar5;

      }

      if (*(longlong *)(DAT_1403ea2a8 + 0x60) != 0) {

        *(float *)(*(longlong *)(DAT_1403ea2a8 + 0x60) + 0xc) = fVar5;

      }

      DAT_1403ea293 = 1;

      if ((ulonglong)(DAT_1403ea2e0 - DAT_1403ea2d0 >> 3) < 1000) {

        lVar4 = DAT_1403ea2d8 - DAT_1403ea2d0;

        lVar2 = FUN_1402c704c();

        if (lVar2 == 0) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        uVar3 = lVar2 + 0x27U & 0xffffffffffffffe0;

        *(longlong *)(uVar3 - 8) = lVar2;

        FUN_1402f8e20(uVar3,DAT_1403ea2d0,DAT_1403ea2d8 - DAT_1403ea2d0);

        FUN_140037380(&DAT_1403ea2d0,uVar3,lVar4 >> 3,1000);

      }

      FUN_14003f810("sound.xml");

      return;

    }

  }

  return;

}




