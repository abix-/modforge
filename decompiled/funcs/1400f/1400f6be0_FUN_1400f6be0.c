// Address: 0x1400f6be0
// Ghidra name: FUN_1400f6be0
// ============ 0x1400f6be0 FUN_1400f6be0 (size=498) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_1400f6be0(longlong param_1,int param_2,int param_3)



{

  uint *puVar1;

  longlong lVar2;

  int *piVar3;

  undefined8 uVar4;

  char cVar5;

  float fVar6;

  undefined8 in_stack_ffffffffffffffc8;

  undefined4 uVar7;

  undefined8 *local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  ulonglong uStack_10;

  

  uVar7 = (undefined4)((ulonglong)in_stack_ffffffffffffffc8 >> 0x20);

  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8);

  if ((lVar2 == *(longlong *)(param_1 + 600)) && (param_3 == 0)) {

    *(undefined1 *)(lVar2 + 0x204) = 1;

    return 1;

  }

  if ((*(longlong *)(param_1 + 600) == 0) && (param_3 == 2)) {

    cVar5 = FUN_1400b76c0();

    if (cVar5 == '\0') {

      lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x130) + (longlong)param_2 * 8);

      *(longlong *)(param_1 + 600) = lVar2;

      *(undefined1 *)(lVar2 + 0x1a) = 1;

      puVar1 = (uint *)(*(longlong *)(param_1 + 600) + 600);

      *puVar1 = *puVar1 | 1;

      FUN_1400b6820(*(undefined8 *)(param_1 + 600),DAT_14030fc10,DAT_140303394);

      FUN_1400b8f90(*(undefined8 *)(param_1 + 600),3);

      fVar6 = *(float *)(*(longlong *)(param_1 + 600) + 0x158) * DAT_140303390;

      piVar3 = *(int **)(*(longlong *)(*(longlong *)(param_1 + 600) + 0x40) + 0x30);

      if (*piVar3 == 2) {

        if ((*(ushort *)(piVar3 + 1) & 2) == 0) {

          *(ushort *)(piVar3 + 1) = *(ushort *)(piVar3 + 1) | 2;

          piVar3[0x2b] = 0;

        }

        piVar3[0x12] = (int)(fVar6 * (float)piVar3[0x27] + (float)piVar3[0x12]);

      }

      local_28 = (undefined8 *)0x0;

      uStack_20 = 0;

      local_18 = 0;

      uStack_10 = 0;

      local_28 = (undefined8 *)FUN_1400285e0(0x20);

      uVar4 = _UNK_140312860;

      local_18 = _DAT_140304d00;

      uStack_10 = _UNK_140304d08;

      *local_28 = _DAT_140312858;

      local_28[1] = uVar4;

      local_28[2] = DAT_140312868;

      *(undefined4 *)(local_28 + 3) = DAT_140312870;

      *(undefined1 *)((longlong)local_28 + 0x1c) = DAT_140312874;

      *(undefined1 *)((longlong)local_28 + 0x1d) = 0;

      FUN_1400d0c80(param_1,*(undefined8 *)(param_1 + 600),&local_28,0,CONCAT44(uVar7,DAT_140303758)

                   );

      if (0xf < uStack_10) {

        if (0xfff < uStack_10 + 1) {

          if (0x1f < (ulonglong)((longlong)local_28 + (-8 - local_28[-1]))) {

                    /* WARNING: Subroutine does not return */

            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

          }

        }

        FUN_1402c7088();

      }

      *(undefined1 *)(*(longlong *)(param_1 + 600) + 0x204) = 0;

      *(undefined4 *)(param_1 + 0x260) = 0;

    }

  }

  return 1;

}




