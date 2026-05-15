// Address: 0x140285980
// Ghidra name: FUN_140285980
// ============ 0x140285980 FUN_140285980 (size=239) ============


undefined4 * FUN_140285980(short param_1)



{

  undefined4 *puVar1;

  longlong lVar2;

  int *piVar3;

  

  puVar1 = (undefined4 *)FUN_1401841a0(1,0x50);

  if (puVar1 != (undefined4 *)0x0) {

    *puVar1 = 0x50;

    puVar1[4] = 10000;

    puVar1[1] = 2;

    puVar1[2] = 0x3e7fc18;

    puVar1[5] = 0xffffffff;

    puVar1[7] = 2;

    lVar2 = FUN_1401841a0(2,4);

    *(longlong *)(puVar1 + 8) = lVar2;

    if (lVar2 != 0) {

      lVar2 = FUN_1401841a0(puVar1[7],4);

      *(longlong *)(puVar1 + 10) = lVar2;

      if (lVar2 != 0) {

        puVar1[1] = puVar1[1] | 0x10;

        piVar3 = (int *)FUN_1401841a0(1,0x10);

        if (piVar3 != (int *)0x0) {

          piVar3[3] = 1000000;

          *piVar3 = (param_1 * 10000) / 0x7fff;

          puVar1[0xe] = 0x10;

          *(int **)(puVar1 + 0x10) = piVar3;

          return puVar1;

        }

      }

    }

    FUN_1402861d0(puVar1);

  }

  return (undefined4 *)0x0;

}




