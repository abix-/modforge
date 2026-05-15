// Address: 0x14015a3a0
// Ghidra name: FUN_14015a3a0
// ============ 0x14015a3a0 FUN_14015a3a0 (size=312) ============


void FUN_14015a3a0(longlong param_1)



{

  undefined8 uVar1;

  int iVar2;

  int *piVar3;

  uint uVar4;

  int iVar5;

  

  uVar1 = FUN_140149300();

  uVar4 = 0;

  if (0 < *(int *)(param_1 + 0x44)) {

    do {

      if (*(char *)(*(longlong *)(param_1 + 0x48) + 6 + (longlong)(int)uVar4 * 10) != '\0') {

        FUN_14015aab0(uVar1,param_1,uVar4 & 0xff,

                      *(undefined2 *)(*(longlong *)(param_1 + 0x48) + 4 + (longlong)(int)uVar4 * 10)

                     );

      }

      uVar4 = uVar4 + 1;

    } while ((int)uVar4 < *(int *)(param_1 + 0x44));

  }

  uVar4 = 0;

  if (0 < *(int *)(param_1 + 0x70)) {

    do {

      FUN_14015ad00(uVar1,param_1,uVar4 & 0xff,0);

      uVar4 = uVar4 + 1;

    } while ((int)uVar4 < *(int *)(param_1 + 0x70));

  }

  uVar4 = 0;

  if (0 < *(int *)(param_1 + 0x60)) {

    do {

      FUN_14015ae90(uVar1,param_1,uVar4 & 0xff,0);

      uVar4 = uVar4 + 1;

    } while ((int)uVar4 < *(int *)(param_1 + 0x60));

  }

  iVar2 = 0;

  if (0 < *(int *)(param_1 + 0x80)) {

    do {

      iVar5 = 0;

      piVar3 = (int *)((longlong)iVar2 * 0x10 + *(longlong *)(param_1 + 0x88));

      if (0 < *piVar3) {

        do {

          FUN_14015b110(uVar1,param_1,iVar2,iVar5,0,0,0,0);

          iVar5 = iVar5 + 1;

        } while (iVar5 < *piVar3);

      }

      iVar2 = iVar2 + 1;

    } while (iVar2 < *(int *)(param_1 + 0x80));

  }

  return;

}




