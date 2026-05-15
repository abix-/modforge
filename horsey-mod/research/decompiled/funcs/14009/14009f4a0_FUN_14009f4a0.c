// Address: 0x14009f4a0
// Ghidra name: FUN_14009f4a0
// ============ 0x14009f4a0 FUN_14009f4a0 (size=242) ============


longlong * FUN_14009f4a0(longlong *param_1,int *param_2)



{

  longlong *plVar1;

  bool bVar2;

  longlong *plVar3;

  longlong *plVar4;

  longlong *plVar5;

  longlong *plVar6;

  longlong *local_38;

  undefined8 uStack_30;

  longlong *local_28;

  uint uStack_20;

  undefined4 uStack_1c;

  

  plVar1 = (longlong *)*param_1;

  local_28 = (longlong *)plVar1[1];

  uStack_20 = 0;

  plVar5 = plVar1;

  if (*(char *)((longlong)local_28 + 0x19) == '\0') {

    plVar3 = local_28;

    plVar6 = plVar1;

    do {

      local_28 = plVar3;

      bVar2 = *param_2 <= (int)local_28[4];

      plVar4 = local_28;

      plVar5 = local_28;

      if (!bVar2) {

        plVar4 = local_28 + 2;

        plVar5 = plVar6;

      }

      uStack_20 = (uint)bVar2;

      plVar3 = (longlong *)*plVar4;

      plVar6 = plVar5;

    } while (*(char *)(*plVar4 + 0x19) == '\0');

  }

  if ((*(char *)((longlong)plVar5 + 0x19) != '\0') || (*param_2 < (int)plVar5[4])) {

    if (param_1[1] == 0x555555555555555) {

                    /* WARNING: Subroutine does not return */

      FUN_1400478f0();

    }

    uStack_30 = 0;

    local_38 = param_1;

    plVar5 = (longlong *)FUN_1402c704c(0x30);

    *(int *)(plVar5 + 4) = *param_2;

    plVar5[5] = 0;

    *plVar5 = (longlong)plVar1;

    plVar5[1] = (longlong)plVar1;

    plVar5[2] = (longlong)plVar1;

    *(undefined2 *)(plVar5 + 3) = 0;

    local_38 = local_28;

    uStack_30 = CONCAT44(uStack_1c,uStack_20);

    plVar5 = (longlong *)FUN_140047690(param_1,&local_38);

  }

  return plVar5 + 5;

}




