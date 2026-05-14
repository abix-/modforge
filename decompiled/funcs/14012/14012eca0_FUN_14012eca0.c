// Address: 0x14012eca0
// Ghidra name: FUN_14012eca0
// ============ 0x14012eca0 FUN_14012eca0 (size=122) ============


undefined8 FUN_14012eca0(ulonglong param_1,ulonglong *param_2)



{

  byte *pbVar1;

  ulonglong uVar2;

  undefined8 uVar3;

  ulonglong local_res10 [3];

  

  if ((param_2 == (ulonglong *)0x0) || (uVar2 = *param_2, local_res10[0] = uVar2, uVar2 <= param_1))

  {

    return 0;

  }

  do {

    if (local_res10[0] == param_1) break;

    pbVar1 = (byte *)(local_res10[0] - 1);

    local_res10[0] = local_res10[0] - 1;

  } while ((*pbVar1 & 0xc0) == 0x80);

  *param_2 = local_res10[0];

  uVar3 = FUN_1401300a0(local_res10,uVar2 - local_res10[0]);

  return uVar3;

}




