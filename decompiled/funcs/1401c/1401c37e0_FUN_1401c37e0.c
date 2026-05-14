// Address: 0x1401c37e0
// Ghidra name: FUN_1401c37e0
// ============ 0x1401c37e0 FUN_1401c37e0 (size=374) ============


undefined8 FUN_1401c37e0(longlong param_1,undefined8 param_2)



{

  uint uVar1;

  char cVar2;

  undefined4 uVar3;

  longlong lVar4;

  undefined8 *puVar5;

  undefined8 uVar6;

  

  lVar4 = FUN_1401c9f40(param_2);

  if (lVar4 == 0) {

    puVar5 = (undefined8 *)FUN_1401841a0(1,0x150);

    if (puVar5 != (undefined8 *)0x0) {

      *puVar5 = param_2;

      puVar5[1] = param_1;

      *(undefined4 *)(puVar5 + 2) = 1;

      cVar2 = FUN_1401c8780(param_1,puVar5,0,0);

      if (cVar2 != '\0') {

        uVar3 = FUN_14016ea50(param_2);

        FUN_140175480(uVar3,"SDL.internal.gpu.d3d12.data",puVar5);

        FUN_140179b40(*(undefined8 *)(param_1 + 0x218));

        if (*(uint *)(param_1 + 0x14c) <= *(uint *)(param_1 + 0x148)) {

          uVar1 = *(uint *)(param_1 + 0x14c) * 2;

          *(uint *)(param_1 + 0x14c) = uVar1;

          uVar6 = FUN_140184230(*(undefined8 *)(param_1 + 0x140),(ulonglong)uVar1 << 3);

          *(undefined8 *)(param_1 + 0x140) = uVar6;

        }

        *(undefined8 **)(*(longlong *)(param_1 + 0x140) + (ulonglong)*(uint *)(param_1 + 0x148) * 8)

             = puVar5;

        *(int *)(param_1 + 0x148) = *(int *)(param_1 + 0x148) + 1;

        FUN_140179b60(*(undefined8 *)(param_1 + 0x218));

        FUN_1401cd9b0(1,FUN_1401ca640,param_2);

        return 1;

      }

      FUN_1401841e0(puVar5);

    }

    return 0;

  }

  if (*(longlong *)(lVar4 + 8) == param_1) {

    *(int *)(lVar4 + 0x10) = *(int *)(lVar4 + 0x10) + 1;

    return 1;

  }

  if (*(char *)(param_1 + 0x98) != '\0') {

                    /* WARNING: Subroutine does not return */

    FUN_14012e0b0(9,&DAT_14039bf30,"Window already claimed");

  }

  FUN_14012e850(&DAT_14039bf30,"Window already claimed");

  return 0;

}




