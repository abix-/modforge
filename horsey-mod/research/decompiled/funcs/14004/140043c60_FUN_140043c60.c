// Address: 0x140043c60
// Ghidra name: FUN_140043c60
// ============ 0x140043c60 FUN_140043c60 (size=884) ============


void FUN_140043c60(float param_1)



{

  int iVar1;

  longlong lVar2;

  longlong lVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  float fVar6;

  

  uVar4 = 0;

  iVar1 = *(int *)(DAT_1403ea2a8 + 0x4c);

  if (iVar1 == 2) {

    param_1 = param_1 + *(float *)(DAT_1403ea2a8 + 0x3c);

    *(float *)(DAT_1403ea2a8 + 0x3c) = param_1;

    fVar6 = *(float *)(DAT_1403ea2a8 + 0x40);

    if (fVar6 <= param_1) {

      *(undefined4 *)(DAT_1403ea2a8 + 0x4c) = 0;

      *(undefined1 *)(*(longlong *)(DAT_1403ea2a8 + 0x58) + 9) = 0;

      *(undefined8 *)(DAT_1403ea2a8 + 0x58) = 0;

      goto LAB_140043f15;

    }

  }

  else {

    if (iVar1 == 3) {

      param_1 = param_1 + *(float *)(DAT_1403ea2a8 + 0x3c);

      *(float *)(DAT_1403ea2a8 + 0x3c) = param_1;

      if (param_1 < *(float *)(DAT_1403ea2a8 + 0x40)) {

        param_1 = param_1 / *(float *)(DAT_1403ea2a8 + 0x40);

        *(float *)(*(longlong *)(DAT_1403ea2a8 + 0x58) + 0xc) =

             (DAT_14030338c - (param_1 + param_1)) * param_1 * param_1 *

             *(float *)(DAT_1403ea2a8 + 0xc);

      }

      else {

        *(undefined4 *)(DAT_1403ea2a8 + 0x4c) = 1;

        *(undefined4 *)(*(longlong *)(DAT_1403ea2a8 + 0x58) + 0xc) =

             *(undefined4 *)(DAT_1403ea2a8 + 0xc);

      }

      goto LAB_140043f15;

    }

    if (iVar1 != 4) {

      if (iVar1 == 5) {

        param_1 = param_1 + *(float *)(DAT_1403ea2a8 + 0x3c);

        *(float *)(DAT_1403ea2a8 + 0x3c) = param_1;

        if (param_1 < *(float *)(DAT_1403ea2a8 + 0x40)) {

          param_1 = param_1 / *(float *)(DAT_1403ea2a8 + 0x40);

          *(float *)(*(longlong *)(DAT_1403ea2a8 + 0x60) + 0xc) =

               (DAT_14030338c - (param_1 + param_1)) * param_1 * param_1 *

               *(float *)(DAT_1403ea2a8 + 0xc);

          goto LAB_140043f15;

        }

        *(undefined4 *)(DAT_1403ea2a8 + 0x4c) = 1;

      }

      else {

        if (iVar1 != 6) goto LAB_140043f15;

        param_1 = param_1 + *(float *)(DAT_1403ea2a8 + 0x3c);

        *(float *)(DAT_1403ea2a8 + 0x3c) = param_1;

        if (param_1 < *(float *)(DAT_1403ea2a8 + 0x40)) {

          param_1 = param_1 / *(float *)(DAT_1403ea2a8 + 0x40);

          fVar6 = (DAT_14030338c - (param_1 + param_1)) * param_1 * param_1;

          *(float *)(*(longlong *)(DAT_1403ea2a8 + 0x58) + 0xc) =

               (DAT_14039ca44 - fVar6) * *(float *)(DAT_1403ea2a8 + 0x48);

          *(float *)(*(longlong *)(DAT_1403ea2a8 + 0x60) + 0xc) =

               fVar6 * *(float *)(DAT_1403ea2a8 + 0xc);

          goto LAB_140043f15;

        }

        *(undefined4 *)(DAT_1403ea2a8 + 0x4c) = 1;

        *(undefined1 *)(*(longlong *)(DAT_1403ea2a8 + 0x58) + 9) = 0;

      }

      *(undefined4 *)(*(longlong *)(DAT_1403ea2a8 + 0x60) + 0xc) =

           *(undefined4 *)(DAT_1403ea2a8 + 0xc);

      *(undefined8 *)(DAT_1403ea2a8 + 0x58) = *(undefined8 *)(DAT_1403ea2a8 + 0x60);

      *(undefined8 *)(DAT_1403ea2a8 + 0x60) = 0;

      goto LAB_140043f15;

    }

    param_1 = param_1 + *(float *)(DAT_1403ea2a8 + 0x3c);

    *(float *)(DAT_1403ea2a8 + 0x3c) = param_1;

    fVar6 = *(float *)(DAT_1403ea2a8 + 0x40);

    if (fVar6 <= param_1) {

      *(undefined4 *)(DAT_1403ea2a8 + 0x4c) = 5;

      *(undefined1 *)(*(longlong *)(DAT_1403ea2a8 + 0x58) + 9) = 0;

      *(undefined4 *)(*(longlong *)(DAT_1403ea2a8 + 0x58) + 0xc) = 0;

      *(undefined4 *)(DAT_1403ea2a8 + 0x3c) = 0;

      *(undefined4 *)(DAT_1403ea2a8 + 0x40) = *(undefined4 *)(DAT_1403ea2a8 + 0x44);

      *(undefined4 *)(DAT_1403ea2a8 + 0x44) = 0;

      *(undefined1 *)(*(longlong *)(DAT_1403ea2a8 + 0x60) + 10) = 0;

      goto LAB_140043f15;

    }

  }

  param_1 = param_1 / fVar6;

  *(float *)(*(longlong *)(DAT_1403ea2a8 + 0x58) + 0xc) =

       (DAT_14039ca44 - (DAT_14030338c - (param_1 + param_1)) * param_1 * param_1) *

       *(float *)(DAT_1403ea2a8 + 0x48);

LAB_140043f15:

  SDL_LockMutex(*(undefined8 *)(DAT_1403ea2a8 + 0xe0));

  lVar3 = DAT_1403ea2a8;

  uVar5 = uVar4;

  if (0 < *(int *)(DAT_1403ea2a8 + 0x6c)) {

    do {

      lVar2 = *(longlong *)(uVar5 + *(longlong *)(lVar3 + 0x70));

      if (*(int *)(lVar2 + 0xc) == 0) {

        lVar3 = *(longlong *)(lVar2 + 0x10);

        if (lVar3 != 0) {

          thunk_FUN_1402e9a80(lVar3 - (ulonglong)*(byte *)(lVar3 + -1));

        }

        thunk_FUN_1402e9a80(lVar2);

        iVar1 = *(int *)(DAT_1403ea2a8 + 0x6c);

        *(int *)(DAT_1403ea2a8 + 0x6c) = iVar1 + -1;

        *(undefined8 *)(uVar5 + *(longlong *)(DAT_1403ea2a8 + 0x70)) =

             *(undefined8 *)(*(longlong *)(DAT_1403ea2a8 + 0x70) + -8 + (longlong)iVar1 * 8);

        lVar3 = DAT_1403ea2a8;

      }

      else {

        uVar4 = (ulonglong)((int)uVar4 + 1);

        uVar5 = uVar5 + 8;

      }

    } while ((int)uVar4 < *(int *)(lVar3 + 0x6c));

  }

  SDL_UnlockMutex(*(undefined8 *)(lVar3 + 0xe0));

  return;

}




