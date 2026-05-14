// Address: 0x14014f740
// Ghidra name: FUN_14014f740
// ============ 0x14014f740 FUN_14014f740 (size=100) ============


undefined8 FUN_14014f740(uint *param_1,int *param_2,longlong *param_3,undefined4 *param_4)



{

  undefined4 uVar1;

  longlong lVar2;

  uint uVar3;

  

  uVar3 = *param_1;

  lVar2 = *(longlong *)(param_1 + 0x3c);

  if ((uVar3 == 0) || ((uVar3 & 0xf0000000) == 0x10000000)) {

    uVar3 = (int)uVar3 >> 8 & 0xff;

  }

  else {

    uVar3 = 0;

  }

  *param_3 = (longlong)((int)(uVar3 * *param_2 + ((int)(uVar3 * *param_2) >> 0x1f & 7U)) >> 3) +

             (longlong)(param_2[1] * *(int *)(lVar2 + 0x10)) + *(longlong *)(lVar2 + 0x18);

  uVar1 = *(undefined4 *)(lVar2 + 0x10);

  *param_4 = uVar1;

  return CONCAT71((uint7)(uint3)((uint)uVar1 >> 8),1);

}




