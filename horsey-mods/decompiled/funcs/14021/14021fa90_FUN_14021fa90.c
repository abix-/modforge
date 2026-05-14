// Address: 0x14021fa90
// Ghidra name: FUN_14021fa90
// ============ 0x14021fa90 FUN_14021fa90 (size=75) ============


void FUN_14021fa90(short *param_1,short *param_2)



{

  int iVar1;

  int iVar2;

  

  iVar1 = MulDiv((int)*param_1,4,DAT_1403fdba4);

  iVar2 = DAT_1403fdba8;

  *param_1 = (short)iVar1;

  iVar2 = MulDiv((int)*param_2,8,iVar2);

  *param_2 = (short)iVar2;

  return;

}




