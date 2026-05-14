// Address: 0x1400f16a0
// Ghidra name: FUN_1400f16a0
// ============ 0x1400f16a0 FUN_1400f16a0 (size=236) ============


undefined8

FUN_1400f16a0(longlong param_1,undefined8 param_2,int *param_3,int *param_4,int *param_5,

             int *param_6)



{

  longlong *plVar1;

  undefined4 uVar2;

  int iVar3;

  longlong lVar4;

  

  uVar2 = FUN_1400f0eb0();

  iVar3 = FUN_1400f3c70(param_1,uVar2);

  if (iVar3 < 0) {

    return 0;

  }

  lVar4 = (longlong)iVar3;

  plVar1 = (longlong *)(param_1 + 8);

  if (param_3 != (int *)0x0) {

    *param_3 = (int)(short)((ushort)*(byte *)(*plVar1 + 3 + lVar4) +

                           (ushort)*(byte *)(*plVar1 + 2 + lVar4) * 0x100);

  }

  if (param_4 != (int *)0x0) {

    *param_4 = (int)(short)((ushort)*(byte *)(*plVar1 + 5 + lVar4) +

                           (ushort)*(byte *)(*plVar1 + 4 + lVar4) * 0x100);

  }

  if (param_5 != (int *)0x0) {

    *param_5 = (int)(short)((ushort)*(byte *)(*plVar1 + 6 + lVar4) * 0x100 +

                           (ushort)*(byte *)(*plVar1 + 7 + lVar4));

  }

  if (param_6 != (int *)0x0) {

    *param_6 = (int)(short)((ushort)*(byte *)(*plVar1 + 8 + lVar4) * 0x100 +

                           (ushort)*(byte *)(*plVar1 + 9 + lVar4));

  }

  return 1;

}




