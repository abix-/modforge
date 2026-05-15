// Address: 0x1400f12b0
// Ghidra name: FUN_1400f12b0
// ============ 0x1400f12b0 FUN_1400f12b0 (size=166) ============


void FUN_1400f12b0(longlong param_1,int *param_2,int *param_3,int *param_4)



{

  int *piVar1;

  longlong *plVar2;

  

  piVar1 = (int *)(param_1 + 0x24);

  plVar2 = (longlong *)(param_1 + 8);

  if (param_2 != (int *)0x0) {

    *param_2 = (int)(short)((ushort)*(byte *)((longlong)*piVar1 + 5 + *plVar2) +

                           (ushort)*(byte *)((longlong)*piVar1 + 4 + *plVar2) * 0x100);

  }

  if (param_3 != (int *)0x0) {

    *param_3 = (int)(short)((ushort)*(byte *)((longlong)*piVar1 + 7 + *plVar2) +

                           (ushort)*(byte *)((longlong)*piVar1 + 6 + *plVar2) * 0x100);

  }

  if (param_4 != (int *)0x0) {

    *param_4 = (int)(short)((ushort)*(byte *)((longlong)*piVar1 + 9 + *plVar2) +

                           (ushort)*(byte *)((longlong)*piVar1 + 8 + *plVar2) * 0x100);

  }

  return;

}




