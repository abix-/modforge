// Address: 0x14015aab0
// Ghidra name: FUN_14015aab0
// ============ 0x14015aab0 FUN_14015aab0 (size=388) ============


void FUN_14015aab0(undefined8 param_1,undefined4 *param_2,byte param_3,short param_4)



{

  short *psVar1;

  char cVar2;

  short sVar3;

  int iVar4;

  undefined4 local_a8;

  undefined4 uStack_a4;

  undefined4 uStack_a0;

  undefined4 uStack_9c;

  undefined4 local_98 [2];

  undefined8 local_90;

  undefined4 local_88;

  byte local_84;

  short local_80;

  

  if ((int)(uint)param_3 < (int)param_2[0x11]) {

    psVar1 = (short *)(*(longlong *)(param_2 + 0x12) + (ulonglong)param_3 * 10);

    if ((*(char *)(*(longlong *)(param_2 + 0x12) + 6 + (ulonglong)param_3 * 10) == '\0') ||

       ((*(char *)((longlong)psVar1 + 7) == '\0' &&

        (((*psVar1 < -0x7ffe || (*psVar1 == 0x7fff)) &&

         (iVar4 = FUN_140190050((int)param_4), iVar4 < 0x1fff)))))) {

      *psVar1 = param_4;

      psVar1[1] = param_4;

      psVar1[2] = param_4;

      *(undefined1 *)(psVar1 + 3) = 1;

      sVar3 = param_4;

    }

    else {

      if ((param_4 == psVar1[1]) && (*(char *)((longlong)psVar1 + 9) == '\0')) {

        return;

      }

      *(undefined1 *)((longlong)psVar1 + 7) = 1;

      sVar3 = psVar1[1];

    }

    if ((char)psVar1[4] == '\0') {

      iVar4 = FUN_140190050((int)param_4 - (int)sVar3);

      if (iVar4 < 0x19a) {

        local_a8 = param_2[8];

        uStack_a4 = param_2[9];

        uStack_a0 = param_2[10];

        uStack_9c = param_2[0xb];

        cVar2 = FUN_1401596e0(&local_a8);

        if (cVar2 == '\0') {

          return;

        }

      }

      psVar1[4] = 0x101;

      FUN_14015aab0(param_1,param_2,param_3,*psVar1);

      *(undefined1 *)((longlong)psVar1 + 9) = 0;

    }

    cVar2 = FUN_14015a640();

    if (cVar2 != '\0') {

      if (*(char *)((longlong)psVar1 + 9) != '\0') {

        return;

      }

      if (psVar1[2] < param_4) {

        if (psVar1[1] <= param_4) {

          return;

        }

      }

      else if ((param_4 < psVar1[2]) && (param_4 <= psVar1[1])) {

        return;

      }

    }

    psVar1[1] = param_4;

    *(undefined8 *)(param_2 + 0x4e) = param_1;

    cVar2 = FUN_140139420(0x600);

    if (cVar2 != '\0') {

      local_88 = *param_2;

      local_98[0] = 0x600;

      local_90 = param_1;

      local_84 = param_3;

      local_80 = param_4;

      FUN_14013b140(local_98);

    }

  }

  return;

}




