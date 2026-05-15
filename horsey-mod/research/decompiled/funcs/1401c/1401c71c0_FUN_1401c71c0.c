// Address: 0x1401c71c0
// Ghidra name: FUN_1401c71c0
// ============ 0x1401c71c0 FUN_1401c71c0 (size=209) ============


ulonglong FUN_1401c71c0(int *param_1,uint *param_2)



{

  char cVar1;

  int iVar2;

  uint uVar3;

  int iVar4;

  ulonglong in_RAX;

  

  if (param_2 == (uint *)0x0) {

    return in_RAX & 0xffffffffffffff00;

  }

  cVar1 = *(char *)((longlong)param_1 + 0x27);

  *param_2 = (uint)(*(char *)((longlong)param_1 + 0x26) == '\x01');

  iVar4 = param_1[10];

  param_2[1] = (uint)(cVar1 == '\x01');

  iVar2 = *param_1;

  param_2[3] = (uint)((char)iVar4 == '\x01');

  param_2[2] = *(uint *)(&DAT_1403e48f8 + (longlong)iVar2 * 4);

  *(char *)(param_2 + 4) = (char)param_1[9];

  *(undefined1 *)((longlong)param_2 + 0x11) = *(undefined1 *)((longlong)param_1 + 0x25);

  param_2[5] = *(uint *)(&DAT_1403e4920 + (longlong)param_1[5] * 4);

  param_2[6] = *(uint *)(&DAT_1403e4920 + (longlong)param_1[7] * 4);

  param_2[7] = *(uint *)(&DAT_1403e4920 + (longlong)param_1[6] * 4);

  param_2[8] = *(uint *)(&DAT_1403e48f8 + (longlong)param_1[8] * 4);

  param_2[9] = *(uint *)(&DAT_1403e4920 + (longlong)param_1[1] * 4);

  param_2[10] = *(uint *)(&DAT_1403e4920 + (longlong)param_1[3] * 4);

  param_2[0xb] = *(uint *)(&DAT_1403e4920 + (longlong)param_1[2] * 4);

  uVar3 = *(uint *)(&DAT_1403e48f8 + (longlong)param_1[4] * 4);

  param_2[0xc] = uVar3;

  return CONCAT71((uint7)(uint3)(uVar3 >> 8),1);

}




