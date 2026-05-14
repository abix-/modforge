// Address: 0x1400f19c0
// Ghidra name: FUN_1400f19c0
// ============ 0x1400f19c0 FUN_1400f19c0 (size=226) ============


undefined8

FUN_1400f19c0(longlong param_1,undefined8 param_2,int *param_3,int *param_4,int *param_5,

             int *param_6)



{

  longlong *plVar1;

  int iVar2;

  longlong lVar3;

  

  iVar2 = FUN_1400f3c70();

  if (iVar2 < 0) {

    return 0;

  }

  lVar3 = (longlong)iVar2;

  plVar1 = (longlong *)(param_1 + 8);

  if (param_3 != (int *)0x0) {

    *param_3 = (int)(short)((ushort)*(byte *)(*plVar1 + 2 + lVar3) * 0x100 +

                           (ushort)*(byte *)(*plVar1 + 3 + lVar3));

  }

  if (param_4 != (int *)0x0) {

    *param_4 = (int)(short)((ushort)*(byte *)(*plVar1 + 5 + lVar3) +

                           (ushort)*(byte *)(*plVar1 + 4 + lVar3) * 0x100);

  }

  if (param_5 != (int *)0x0) {

    *param_5 = (int)(short)((ushort)*(byte *)(*plVar1 + 7 + lVar3) +

                           (ushort)*(byte *)(*plVar1 + 6 + lVar3) * 0x100);

  }

  if (param_6 != (int *)0x0) {

    *param_6 = (int)(short)((ushort)*(byte *)(lVar3 + 8 + *plVar1) * 0x100 +

                           (ushort)*(byte *)(lVar3 + 9 + *plVar1));

  }

  return 1;

}




