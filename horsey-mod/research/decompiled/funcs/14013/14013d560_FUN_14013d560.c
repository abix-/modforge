// Address: 0x14013d560
// Ghidra name: FUN_14013d560
// ============ 0x14013d560 FUN_14013d560 (size=281) ============


void FUN_14013d560(void)



{

  ulonglong uVar1;

  ulonglong uVar2;

  ushort uVar3;

  char *pcVar4;

  ushort in_R9W;

  char in_stack_00000028;

  undefined8 in_stack_00000030;

  undefined8 in_stack_00000038;

  ushort local_18;

  short local_16;

  ushort local_14;

  short local_12;

  ushort local_10;

  short local_e;

  short local_c;

  

  if (in_stack_00000028 == '\x02') {

    pcVar4 = "face:axby,";

  }

  else if (in_stack_00000028 == '\x03') {

    pcVar4 = "face:bayx,";

  }

  else if (in_stack_00000028 == '\x04') {

    pcVar4 = "face:sony,";

  }

  else {

    pcVar4 = "face:abxy,";

  }

  FUN_14012f120(in_stack_00000030,pcVar4,in_stack_00000038);

  local_e = (short)((ulonglong)in_R9W / 5);

  local_c = in_R9W + local_e * -5;

  uVar1 = ((ulonglong)in_R9W / 5) / 3;

  local_10 = (ushort)uVar1;

  local_e = local_e + local_10 * -3;

  uVar1 = uVar1 >> 2;

  local_10 = local_10 & 3;

  uVar2 = uVar1 / 3;

  local_14 = (ushort)uVar2;

  local_12 = (short)uVar1 + local_14 * -3;

  uVar2 = uVar2 >> 2;

  local_14 = local_14 & 3;

  uVar3 = (ushort)(uVar2 / 3);

  local_18 = uVar3 & 3;

  local_16 = (short)uVar2 + uVar3 * -3;

  FUN_1401413c0(&local_18,in_stack_00000030,in_stack_00000038);

  return;

}




