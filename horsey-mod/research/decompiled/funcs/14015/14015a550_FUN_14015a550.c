// Address: 0x14015a550
// Ghidra name: FUN_14015a550
// ============ 0x14015a550 FUN_14015a550 (size=167) ============


void FUN_14015a550(int param_1)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  undefined4 local_88 [2];

  undefined8 local_80;

  int local_78;

  

  piVar1 = DAT_1403fc070;

  do {

    if (piVar1 == (int *)0x0) {

LAB_14015a591:

      cVar2 = FUN_14013f5e0(param_1);

      if (cVar2 != '\0') {

        FUN_1401400c0(param_1);

      }

      local_88[0] = 0x606;

      local_80 = 0;

      cVar2 = FUN_140139420(0x606);

      if (cVar2 != '\0') {

        local_78 = param_1;

        FUN_14013b140(local_88);

      }

      iVar3 = FUN_1401591d0(param_1);

      if (-1 < iVar3) {

        *(undefined4 *)(DAT_1403fc078 + (longlong)iVar3 * 4) = 0;

      }

      return;

    }

    if (*piVar1 == param_1) {

      FUN_14015a3a0(piVar1);

      *(undefined1 *)(piVar1 + 0x38) = 0;

      goto LAB_14015a591;

    }

    piVar1 = *(int **)(piVar1 + 0x56);

  } while( true );

}




